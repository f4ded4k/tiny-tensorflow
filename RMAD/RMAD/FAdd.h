#pragma once

#include "FOperator.h"

class IVisitor;

class FAdd : public FOperator
{
public:
	FAdd(int Key, FGraph & Graph, int FirstInputKey, int SecondInputKey);
	virtual ~FAdd();

private:
	void Accept(IVisitor& Visitor) override;
};

