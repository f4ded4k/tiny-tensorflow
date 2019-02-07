#include "FNode.h"
#include "FGraph.h"

auto mt = std::mt19937(std::chrono::steady_clock::now().time_since_epoch().count());

extern FGraph* DefaultGraph;

FNode::FNode(int Key) : mKey(Key)
{
}

int FNode::GetKey() const
{
	return mKey;
}


FNode::~FNode() = default;

bool operator<(const FNode& FirstNode, const FNode& SecondNode)
{
	return &FirstNode < &SecondNode;
}

FNode placeholder()
{
	int Key = DefaultGraph->InsertPlaceholder();
	return FNode(Key);
}

FNode constant(double InitValue)
{
	int Key = DefaultGraph->InsertConstant(InitValue);
	return FNode(Key);
}

FNode variable(double InitValue)
{
	int Key = DefaultGraph->InsertVariable(InitValue);
	return FNode(Key);
}

FNode variable()
{
	return variable(static_cast<double>(mt()) / mt.max());
}

FNode add(const FNode& FirstNode, const FNode& SecondNode)
{
	int Key = DefaultGraph->InsertAdd(FirstNode.GetKey(), SecondNode.GetKey());
	return FNode(Key);
}

FNode operator+(const FNode& FirstNode, const FNode& SecondNode)
{
	return add(FirstNode, SecondNode);
}

FNode operator+(const FNode& FirstNode, double SecondNodeValue)
{
	int InputConstKey = DefaultGraph->InsertConstant(SecondNodeValue);
	return add(FirstNode, FNode(InputConstKey));
}

FNode operator+(double FirstNodeValue, const FNode& SecondNode)
{
	int InputConstKey = DefaultGraph->InsertConstant(FirstNodeValue);
	return add(FNode(InputConstKey), SecondNode);
}

FNode multiply(const FNode& FirstNode, const FNode& SecondNode)
{
	int Key = DefaultGraph->InsertMultiply(FirstNode.GetKey(), SecondNode.GetKey());
	return FNode(Key);
}

FNode operator*(const FNode& FirstNode, const FNode& SecondNode)
{
	return multiply(FirstNode, SecondNode);
}

FNode operator*(const FNode& FirstNode, double SecondNodeValue)
{
	int InputConstKey = DefaultGraph->InsertConstant(SecondNodeValue);
	return multiply(FirstNode, FNode(InputConstKey));
}
FNode operator*(double FirstNodeValue, const FNode& SecondNode)
{
	int InputConstKey = DefaultGraph->InsertConstant(FirstNodeValue);
	return multiply(FNode(InputConstKey), SecondNode);
}

FNode substract(const FNode & FirstNode, const FNode & SecondNode)
{
	int Key = DefaultGraph->InsertSubstract(FirstNode.GetKey(), SecondNode.GetKey());
	return FNode(Key);
}

FNode operator-(const FNode & FirstNode, const FNode & SecondNode)
{
	return substract(FirstNode, SecondNode);
}

FNode operator-(const FNode & FirstNode, double SecondNodeValue)
{
	int InputConstKey = DefaultGraph->InsertConstant(SecondNodeValue);
	return substract(FirstNode, FNode(InputConstKey));
}

FNode operator-(double FirstNodeValue, const FNode & SecondNode)
{
	int InputConstKey = DefaultGraph->InsertConstant(FirstNodeValue);
	return substract(FNode(InputConstKey), SecondNode);
}

FNode divide(const FNode & FirstNode, const FNode & SecondNode)
{
	int Key = DefaultGraph->InsertDivide(FirstNode.GetKey(), SecondNode.GetKey());
	return FNode(Key);
}

FNode operator/(const FNode & FirstNode, const FNode & SecondNode)
{
	return divide(FirstNode, SecondNode);
}

FNode operator/(const FNode & FirstNode, double SecondNodeValue)
{
	int InputConstKey = DefaultGraph->InsertConstant(SecondNodeValue);
	return divide(FirstNode, FNode(InputConstKey));
}

FNode operator/(double FirstNodeValue, const FNode & SecondNode)
{
	
	int InputConstKey = DefaultGraph->InsertConstant(FirstNodeValue);
	return divide(FNode(InputConstKey), SecondNode);
}

FNode pow(const FNode & FirstNode, const FNode & SecondNode)
{
	int Key = DefaultGraph->InsertPower(FirstNode.GetKey(), SecondNode.GetKey());
	return FNode(Key);
}

FNode pow(const FNode & FirstNode, double SecondNodeValue)
{
	int InputConstKey = DefaultGraph->InsertConstant(SecondNodeValue);
	return pow(FirstNode, FNode(InputConstKey));
}

FNode pow(double FirstNodeValue, const FNode & SecondNode)
{
	int InputConstKey = DefaultGraph->InsertConstant(FirstNodeValue);
	return pow(FNode(InputConstKey), SecondNode);
}

FNode sin(const FNode & Node)
{
	int Key = DefaultGraph->InsertSin(Node.GetKey());
	return FNode(Key);
}

FNode cos(const FNode & Node)
{
	int Key = DefaultGraph->InsertCos(Node.GetKey());
	return FNode(Key);
}