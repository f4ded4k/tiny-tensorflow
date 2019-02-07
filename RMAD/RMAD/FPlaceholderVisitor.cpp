#include "FPlaceholderVisitor.h"
#include "FOperand.h"


FPlaceholderVisitor::FPlaceholderVisitor()
{
}


FPlaceholderVisitor::~FPlaceholderVisitor() = default;

void FPlaceholderVisitor::SetAssignable(double Assignable)
{
	mAssignable = Assignable;
}

void FPlaceholderVisitor::Visit(FOperand & Operand)
{
	if (Operand.GetType() == EType::Placeholder)
	{
		Operand.SetValue(mAssignable);
	}
}

void FPlaceholderVisitor::Visit(FAdd & Add)
{
}

void FPlaceholderVisitor::Visit(FMultiply & Multiply)
{
}

void FPlaceholderVisitor::Visit(FSubstract & Substract)
{
}

void FPlaceholderVisitor::Visit(FDivide & Divide)
{
}

void FPlaceholderVisitor::Visit(FSin & Sin)
{
}

void FPlaceholderVisitor::Visit(FCos & Cos)
{
}

void FPlaceholderVisitor::Visit(FPower & Power)
{
}
