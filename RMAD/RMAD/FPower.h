#pragma once


#include "FOperator.h"


class FPower : public FOperator
{
public:
	FPower(int Key, FGraph & Graph, int BaseInputKey, int ExponentInputKey);
	virtual ~FPower();

private:
	void Accept(IVisitor& Visitor) override;
};

