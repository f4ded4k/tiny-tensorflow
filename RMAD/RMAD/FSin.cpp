#include "FSin.h"
#include "IVisitor.h"



FSin::FSin(int Key, FGraph & Graph, int InputKey)
	: FOperator(Key, Graph, { InputKey })
{
}

FSin::~FSin() = default;

void FSin::Accept(IVisitor& Visitor)
{
	Visitor.Visit(*this);
}
