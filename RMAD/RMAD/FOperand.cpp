#include "FOperand.h"
#include "IVisitor.h"


void FOperand::Accept(IVisitor& Visitor)
{
	Visitor.Visit(*this);
}


FOperand::FOperand(int Key, EType Type, FGraph & Graph, const std::optional<double>& Value)
	: FVertex(Key, Graph, Value), mType(Type)
{
}

FOperand::~FOperand() = default;

EType FOperand::GetType() const
{
	return mType;
}
