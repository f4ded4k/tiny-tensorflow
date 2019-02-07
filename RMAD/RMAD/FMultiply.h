#pragma once

#include "FOperator.h"

class IVisitor;


class FMultiply : public FOperator
{
public:
	FMultiply(int Key, FGraph & Graph, int FirstInputKey, int SecondInputKey);
	virtual ~FMultiply();

private:
	void Accept(IVisitor& Visitor) override;
};
