#pragma once


#include "FVertex.h"
#include <unordered_map>
#include <initializer_list>


class FOperator : public FVertex
{
protected:
	std::optional<double> mGrediant;
	std::unordered_map<int, double> mEdgeGrediant;

public:
	FOperator(int Key, FGraph & Graph, const std::initializer_list<int>& InputKeys);
	virtual ~FOperator();

	void SetEdgeGrediantPair(int InputKey, double Value);
	double GetEdgeGrediantOrZero(int InputKey);
	double GetGrediant() const;
	void SetGrediant(double Grediant);
	void ResetGrediant();
	void ResetEdgeGrediant();
};

