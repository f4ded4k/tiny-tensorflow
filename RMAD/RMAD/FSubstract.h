#pragma once


#include "FOperator.h"


class FSubstract : public FOperator
{
public:
	FSubstract(int Key, FGraph & Graph, int FirstInputKey, int SecondInputKey);
	virtual ~FSubstract();

private:
	void Accept(IVisitor& Visitor) override;
};

