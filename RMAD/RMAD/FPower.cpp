#include "FPower.h"
#include "IVisitor.h"




FPower::FPower(int Key, FGraph & Graph, int BaseInputKey, int ExponentInputKey)
	: FOperator(Key, Graph, { BaseInputKey,ExponentInputKey })
{
}

FPower::~FPower() = default;

void FPower::Accept(IVisitor & Visitor)
{
	Visitor.Visit(*this);
}
