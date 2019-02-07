#include "FCos.h"
#include "IVisitor.h"



FCos::FCos(int Key, FGraph & Graph, int InputKey)
	: FOperator(Key, Graph, { InputKey })
{
}

FCos::~FCos() = default;

void FCos::Accept(IVisitor & Visitor)
{
	Visitor.Visit(*this);
}
