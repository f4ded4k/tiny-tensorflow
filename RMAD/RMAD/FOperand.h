#pragma once

#include "FVertex.h"

class IVisitor;

enum class EType { Variable, Constant, Placeholder };


class FOperand : public FVertex
{
private:
	EType mType;
	void Accept(IVisitor& Visitor) override;

public:
	FOperand(int Key, EType Type, FGraph& Graph, const std::optional<double> & Value = std::nullopt);
	virtual ~FOperand();

	EType GetType() const;
};

