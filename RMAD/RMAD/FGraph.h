#pragma once

#include <vector>
#include <optional>
#include <memory>
#include <map>
#include <initializer_list>
#include "FVertex.h"

class FVertex;
class FNode;
class FForwardVisitor;

class FGraph
{
public:
	FGraph();
	~FGraph();

private:
	int mKey;
	std::vector<std::unique_ptr<FVertex>> mVertices;

	void PostOrderTraversal(FVertex* CurrentVertex, FForwardVisitor& ForwardVisitorm, std::vector<FVertex*>& ReversePostOrder);

public:
	using FeedMap = std::map<std::reference_wrapper<const FNode>, double, std::less<const FNode>>;

	int InsertPlaceholder();
	int InsertConstant(double InitValue);
	int InsertVariable(double InitValue);
	int InsertAdd(int FirstKey, int SecondKey);
	int InsertMultiply(int FirstKey, int SecondKey);
	int InsertSubstract(int FirstKey, int SecondKey);
	int InsertDivide(int FirstKey, int SecondKey);
	int InsertSin(int Key);
	int InsertCos(int Key);
	int InsertPower(int BaseKey, int ExponentKey);
	
	void AssignPlaceholders(const FeedMap& FeedMap);
	void ForwardCompute(const FNode& FinalNode, std::vector<FVertex*>& ReversePostOrder);
	void BackwardCompute(const FNode& FinalNode, double LearningRate, const std::vector<FVertex*>& ReversePostorder);
	void ResetUsed(std::vector<FVertex*> & ReversePostOrder);

	double Evaluate(const FNode& FinalNode, const FeedMap& FeedMap = {});
	void Train(const FNode& FinalNode, double LearningRate, const FeedMap& FeedMap = {});
	void Train(const FNode& FinalNode, double LearningRate, int Turns = 1, const FeedMap& FeedMap = {});

	void SetAsDefault();
	FVertex* GetVertex(int Key);
	int GetKeyAndUpdate();
};

