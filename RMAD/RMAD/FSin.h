#pragma once


#include "FOperator.h"


class FSin : public FOperator
{
public:
	FSin(int Key, FGraph & Graph, int InputKey);
	virtual ~FSin();

private:
	void Accept(IVisitor& Visitor) override;
};

