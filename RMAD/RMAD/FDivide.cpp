#include "FDivide.h"
#include "IVisitor.h"




FDivide::FDivide(int Key, FGraph & Graph, int FirstInputKey, int SecondInputKey)
	: FOperator(Key, Graph, { FirstInputKey,SecondInputKey })
{
}

FDivide::~FDivide() = default;

void FDivide::Accept(IVisitor & Visitor)
{
	Visitor.Visit(*this);
}


