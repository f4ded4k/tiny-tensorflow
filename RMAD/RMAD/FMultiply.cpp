#include "FMultiply.h"
#include "IVisitor.h"




FMultiply::FMultiply(int Key, FGraph & Graph, int FirstInputKey, int SecondInputKey)
	: FOperator(Key, Graph, { FirstInputKey, SecondInputKey })
{
}

FMultiply::~FMultiply() = default;

void FMultiply::Accept(IVisitor& Visitor)
{
	Visitor.Visit(*this);
}