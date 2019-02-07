#pragma once
#include <random>
#include <chrono>

class FNode
{
private:
	int mKey;

public:
	FNode(int Key);
	int GetKey() const;
	~FNode();
};

bool operator<(const FNode& FirstNode, const FNode& SecondNode);

FNode placeholder();
FNode constant(double InitValue);
FNode variable(double InitValue);
FNode variable();

FNode add(const FNode& FirstNode, const FNode& SecondNode);
FNode operator+(const FNode& FirstNode, const FNode& SecondNode);
FNode operator+(const FNode& FirstNode, double SecondNodeValue);
FNode operator+(double FirstNodeValue, const FNode& SecondNode);

FNode multiply(const FNode& FirstNode, const FNode& SecondNode);
FNode operator*(const FNode& FirstNode, const FNode& SecondNode);
FNode operator*(const FNode& FirstNode, double SecondNodeValue);
FNode operator*(double FirstNodeValue, const FNode& SecondNode);

FNode substract(const FNode& FirstNode, const FNode& SecondNode);
FNode operator-(const FNode& FirstNode, const FNode& SecondNode);
FNode operator-(const FNode& FirstNode, double SecondNodeValue);
FNode operator-(double FirstNodeValue, const FNode& SecondNode);

FNode divide(const FNode& FirstNode, const FNode& SecondNode);
FNode operator/(const FNode& FirstNode, const FNode& SecondNode);
FNode operator/(const FNode& FirstNode, double SecondNodeValue);
FNode operator/(double FirstNodeValue, const FNode& SecondNode);

FNode pow(const FNode& FirstNode, const FNode& SecondNode);
FNode pow(const FNode& FirstNode, double SecondNodeValue);
FNode pow(double FirstNodeValue, const FNode& SecondNode);

FNode sin(const FNode& Node);

FNode cos(const FNode& Node);