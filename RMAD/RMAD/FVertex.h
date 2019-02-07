#pragma once

#include <optional>
#include <vector>

class IVisitor;
class FGraph;
class FOperator;

class FVertex
{
private:
	int mKey;
	FGraph& mGraph;
	std::optional<double> mValue;
	std::vector<FOperator*> mOutputVertices;

protected:
	std::vector<FVertex*> mInputVertices;
	FGraph& GetGraph() const;

public:
	FVertex(int Key, FGraph& Graph, const std::optional<double> & Value = std::nullopt);
	virtual ~FVertex();

	virtual void Accept(IVisitor& Visitor) = 0;
	const std::vector<FVertex*>& GetInputVertices() const;
	const std::vector<FOperator*>& GetOutputOperators() const;
	void SetValue(double Value);
	double GetValue() const;
	int GetKey() const;
	bool IsValueSet() const;
	void ResetValue();

	friend class FOperator;
};

