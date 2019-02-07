#include "FVertex.h"



FVertex::FVertex(int Key, FGraph & Graph, const std::optional<double>& Value)
	: mKey(Key), mGraph(Graph), mValue(Value)
{
}


FVertex::~FVertex() = default;

const std::vector<FVertex*>& FVertex::GetInputVertices() const
{
	return mInputVertices;
}

const std::vector<FOperator*>& FVertex::GetOutputOperators() const
{
	return mOutputVertices;
}

void FVertex::SetValue(double Value)
{
	mValue = Value;
}

double FVertex::GetValue() const
{
	return *mValue;
}

int FVertex::GetKey() const
{
	return mKey;
}

bool FVertex::IsValueSet() const
{
	return mValue.has_value();
}

void FVertex::ResetValue()
{
	mValue.reset();
}

FGraph & FVertex::GetGraph() const
{
	return mGraph;
}
