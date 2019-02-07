#include "FGraph.h"
#include "FOperand.h"
#include "FAdd.h"
#include "FMultiply.h"
#include "FSubstract.h"
#include "FDivide.h"
#include "FSin.h"
#include "FCos.h"
#include "FPower.h"
#include "FForwardVisitor.h"
#include "FPlaceholderVisitor.h"
#include "FResetVisitor.h"
#include "FBackwardVisitor.h"
#include "FNode.h"
#include <algorithm>

extern FGraph* DefaultGraph;


FGraph::FGraph() : mKey(0)
{
}


FGraph::~FGraph() = default;


void FGraph::PostOrderTraversal(FVertex * CurrentVertex, FForwardVisitor & ForwardVisitor, std::vector<FVertex*>& ReversePostOrder)
{
	ReversePostOrder.push_back(CurrentVertex);

	if (CurrentVertex->IsValueSet()) { return; }

	for (FVertex* InputVertex : CurrentVertex->GetInputVertices())
	{
		PostOrderTraversal(InputVertex, ForwardVisitor, ReversePostOrder);
	}

	CurrentVertex->Accept(ForwardVisitor);
}


int FGraph::InsertPlaceholder()
{
	int CurrentKey = GetKeyAndUpdate();
	mVertices.push_back(std::make_unique<FOperand>(CurrentKey, EType::Placeholder, *this));
	return CurrentKey;
}

int FGraph::InsertConstant(double InitValue)
{
	int CurrentKey = GetKeyAndUpdate();
	mVertices.push_back(std::make_unique<FOperand>(CurrentKey, EType::Constant, *this, InitValue));
	return CurrentKey;
}

int FGraph::InsertVariable(double InitValue)
{
	int CurrentKey = GetKeyAndUpdate();
	mVertices.push_back(std::make_unique<FOperand>(CurrentKey, EType::Variable, *this, InitValue));
	return CurrentKey;
}

int FGraph::InsertAdd(int FirstKey, int SecondKey)
{
	int CurrentKey = GetKeyAndUpdate();
	mVertices.push_back(std::make_unique<FAdd>(CurrentKey, *this, FirstKey, SecondKey));
	return CurrentKey;
}

int FGraph::InsertMultiply(int FirstKey, int SecondKey)
{
	int CurrentKey = GetKeyAndUpdate();
	mVertices.push_back(std::make_unique<FMultiply>(CurrentKey, *this, FirstKey, SecondKey));
	return CurrentKey;
}

int FGraph::InsertSubstract(int FirstKey, int SecondKey)
{
	int CurrentKey = GetKeyAndUpdate();
	mVertices.push_back(std::make_unique<FSubstract>(CurrentKey, *this, FirstKey, SecondKey));
	return CurrentKey;
}

int FGraph::InsertDivide(int FirstKey, int SecondKey)
{
	int CurrentKey = GetKeyAndUpdate();
	mVertices.push_back(std::make_unique<FDivide>(CurrentKey, *this, FirstKey, SecondKey));
	return CurrentKey;
}

int FGraph::InsertSin(int Key)
{
	int CurrentKey = GetKeyAndUpdate();
	mVertices.push_back(std::make_unique<FSin>(CurrentKey, *this, Key));
	return CurrentKey;
}

int FGraph::InsertCos(int Key)
{
	int CurrentKey = GetKeyAndUpdate();
	mVertices.push_back(std::make_unique<FCos>(CurrentKey, *this, Key));
	return CurrentKey;
}

int FGraph::InsertPower(int BaseKey, int ExponentKey)
{
	int CurrentKey = GetKeyAndUpdate();
	mVertices.push_back(std::make_unique<FPower>(CurrentKey, *this, BaseKey, ExponentKey));
	return CurrentKey;
}

void FGraph::AssignPlaceholders(const FeedMap & FeedMap)
{
	FPlaceholderVisitor PlaceholderVisitor;
	
	for (auto&&[Vertex, Value] : FeedMap)
	{
		PlaceholderVisitor.SetAssignable(Value);
		int Key = Vertex.get().GetKey();
		GetVertex(Key)->Accept(PlaceholderVisitor);
	}
}

void FGraph::ForwardCompute(const FNode & FinalNode, std::vector<FVertex*>& ReversePostOrder)
{
	FForwardVisitor ForwardVisitor;
	PostOrderTraversal(GetVertex(FinalNode.GetKey()), ForwardVisitor, ReversePostOrder);
	ReversePostOrder.erase(std::unique(ReversePostOrder.begin(), ReversePostOrder.end()), ReversePostOrder.end());
}

void FGraph::BackwardCompute(const FNode & FinalNode, double LearningRate, const std::vector<FVertex*>& ReversePostorder)
{
	FBackwardVisitor BackwardVisitor{ LearningRate, FinalNode.GetKey() };

	for (FVertex* Vertex : ReversePostorder)
	{
		Vertex->Accept(BackwardVisitor);
	}
}

void FGraph::ResetUsed(std::vector<FVertex*>& ReversePostOrder)
{
	FResetVisitor ResetVisitor;
	for (auto&& Vertex : ReversePostOrder)
	{
		Vertex->Accept(ResetVisitor);
	}
}

int FGraph::GetKeyAndUpdate()
{
	++mKey;
	return mKey - 1;
}

double FGraph::Evaluate(const FNode & FinalNode, const FeedMap & FeedMap)
{
	AssignPlaceholders(FeedMap);
	std::vector<FVertex*> ReversePostOrder;
	ForwardCompute(FinalNode, ReversePostOrder);
	double Result = GetVertex(FinalNode.GetKey())->GetValue();
	ResetUsed(ReversePostOrder);
	return Result;
}

void FGraph::Train(const FNode & FinalNode, double LearningRate, const FeedMap & FeedMap)
{
	AssignPlaceholders(FeedMap);
	std::vector<FVertex*> ReversePostOrder;
	ForwardCompute(FinalNode, ReversePostOrder);
	BackwardCompute(FinalNode, LearningRate, ReversePostOrder);
	ResetUsed(ReversePostOrder);
}

void FGraph::Train(const FNode & FinalNode, double LearningRate, int Turns, const FeedMap & FeedMap)
{
	while (Turns--)
	{
		Train(FinalNode, LearningRate, FeedMap);
	}
}

void FGraph::SetAsDefault()
{
	DefaultGraph = this;
}

FVertex * FGraph::GetVertex(int Key)
{
	return mVertices[Key].get();
}
