#include "FSubstract.h"
#include "IVisitor.h"



FSubstract::FSubstract(int Key, FGraph & Graph, int FirstInputKey, int SecondInputKey)
	: FOperator(Key, Graph, { FirstInputKey,SecondInputKey })
{
}

FSubstract::~FSubstract() = default;

void FSubstract::Accept(IVisitor & Visitor)
{
	Visitor.Visit(*this);
}
