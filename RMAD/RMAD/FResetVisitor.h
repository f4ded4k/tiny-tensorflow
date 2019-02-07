#pragma once


#include "IVisitor.h"

class FOperator;


class FResetVisitor : public IVisitor
{
private:
	void ResetOperator(FOperator& Operator);

public:
	FResetVisitor();
	virtual ~FResetVisitor();

	virtual void Visit(FOperand& Operand) override;
	virtual void Visit(FAdd& Add) override;
	virtual void Visit(FMultiply& Multiply) override;
	virtual void Visit(FSubstract& Substract) override;
	virtual void Visit(FDivide& Divide) override;
	virtual void Visit(FSin& Sin) override;
	virtual void Visit(FCos& Cos) override;
	virtual void Visit(FPower& Power) override;
};

