#include "FResetVisitor.h"
#include "FOperand.h"
#include "FOperator.h"
#include "FAdd.h"
#include "FMultiply.h"
#include "FSubstract.h"
#include "FDivide.h"
#include "FSin.h"
#include "FCos.h"
#include "FPower.h"

void FResetVisitor::ResetOperator(FOperator & Operator)
{
	Operator.ResetValue();
	Operator.ResetEdgeGrediant();
	Operator.ResetGrediant();
}

FResetVisitor::FResetVisitor()
{
}


FResetVisitor::~FResetVisitor() = default;

void FResetVisitor::Visit(FOperand & Operand)
{
	if (Operand.GetType() == EType::Placeholder)
	{
		Operand.ResetValue();
	}
}

void FResetVisitor::Visit(FAdd& Add)
{
	ResetOperator(Add);
}

void FResetVisitor::Visit(FMultiply & Multiply)
{
	ResetOperator(Multiply);
}

void FResetVisitor::Visit(FSubstract & Substract)
{
	ResetOperator(Substract);
}

void FResetVisitor::Visit(FDivide & Divide)
{
	ResetOperator(Divide);
}

void FResetVisitor::Visit(FSin & Sin)
{
	ResetOperator(Sin);
}

void FResetVisitor::Visit(FCos & Cos)
{
	ResetOperator(Cos);
}

void FResetVisitor::Visit(FPower & Power)
{
	ResetOperator(Power);
}
