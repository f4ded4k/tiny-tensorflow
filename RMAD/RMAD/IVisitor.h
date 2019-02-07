#pragma once

class FOperand;
class FAdd;
class FMultiply;
class FSubstract;
class FDivide;
class FSin;
class FCos;
class FPower;

class IVisitor
{
protected:
	IVisitor();
	virtual ~IVisitor();

public:
	virtual void Visit(FOperand& Operand) = 0;

	virtual void Visit(FAdd& Add) = 0;
	virtual void Visit(FMultiply& Multiply) = 0;
	virtual void Visit(FSubstract& Substract) = 0;
	virtual void Visit(FDivide& Divide) = 0;
	virtual void Visit(FSin& Sin) = 0;
	virtual void Visit(FCos& Cos) = 0;
	virtual void Visit(FPower& Power) = 0;
};

