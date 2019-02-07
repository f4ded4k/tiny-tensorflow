#pragma once


#include "FOperator.h"


class FCos : public FOperator
{
public:
	FCos(int Key, FGraph & Graph, int InputKey);
	virtual ~FCos();

private:
	void Accept(IVisitor& Visitor) override;
};

