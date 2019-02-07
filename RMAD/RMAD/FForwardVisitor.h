#pragma once


#include "IVisitor.h"


class FForwardVisitor :  public IVisitor
{
public:
	FForwardVisitor();
	virtual ~FForwardVisitor();

	virtual void Visit(FOperand& Operand) override;
	virtual void Visit(FAdd& Add) override;
	virtual void Visit(FMultiply& Multiply) override;
	virtual void Visit(FSubstract& Substract) override;
	virtual void Visit(FDivide& Divide) override;
	virtual void Visit(FSin& Sin) override;
	virtual void Visit(FCos& Cos) override;
	virtual void Visit(FPower& Power) override;
};