#include "FOperator.h"
#include "FGraph.h"


FOperator::FOperator(int Key, FGraph & Graph, const std::initializer_list<int>& InputKeys)
	: FVertex(Key, Graph)
{
	for (auto&& InputKey : InputKeys)
	{
		FVertex* InputVertex = Graph.GetVertex(InputKey);
		InputVertex->mOutputVertices.push_back(this);
		mInputVertices.push_back(InputVertex);
	}
}

FOperator::~FOperator() = default;

void FOperator::SetEdgeGrediantPair(int InputKey, double Value)
{
	mEdgeGrediant[InputKey] = Value;
}

double FOperator::GetEdgeGrediantOrZero(int InputKey)
{
	if (mEdgeGrediant.count(InputKey)) { return mEdgeGrediant[InputKey]; }
	else { return 0.0; }
}

double FOperator::GetGrediant() const
{
	return *mGrediant;
}

void FOperator::SetGrediant(double Grediant)
{
	mGrediant = Grediant;
}

void FOperator::ResetGrediant()
{
	mGrediant.reset();
}

void FOperator::ResetEdgeGrediant()
{
	mEdgeGrediant.clear();
}
