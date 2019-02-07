#pragma once


#include "IVisitor.h"

class FOperator;


class FBackwardVisitor : public IVisitor
{
private:
	double mLearningRate;
	int mSeedKey;
	void VisitOperator(FOperator& Operator);

public:
	FBackwardVisitor(double LearningRate, int SeedKey);
	virtual ~FBackwardVisitor();

	virtual void Visit(FOperand& Operand) override;
	virtual void Visit(FAdd& Add) override;
	virtual void Visit(FMultiply& Multiply) override;
	virtual void Visit(FSubstract& Substract) override;
	virtual void Visit(FDivide& Divide) override;
	virtual void Visit(FSin& Sin) override;
	virtual void Visit(FCos& Cos) override;
	virtual void Visit(FPower& Power) override;
};

