#pragma once


#include "FOperator.h"


class FDivide : public FOperator
{
public:
	FDivide(int Key, FGraph & Graph, int FirstInputKey, int SecondInputKey);
	virtual ~FDivide();

private:
	void Accept(IVisitor& Visitor) override;
};

