#include "FAdd.h"
#include "IVisitor.h"


FAdd::FAdd(int Key, FGraph & Graph, int FirstInputKey, int SecondInputKey)
	: FOperator(Key, Graph, { FirstInputKey, SecondInputKey })
{
}


FAdd::~FAdd() = default;

void FAdd::Accept(IVisitor& Visitor)
{
	Visitor.Visit(*this);
}