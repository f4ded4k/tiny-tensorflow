#include "FForwardVisitor.h"
#include "FAdd.h"
#include "FMultiply.h"
#include "FSubstract.h"
#include "FDivide.h"
#include "FSin.h"
#include "FCos.h"
#include "FPower.h"
#include <cmath>


FForwardVisitor::FForwardVisitor()
{
}


FForwardVisitor::~FForwardVisitor() = default;

void FForwardVisitor::Visit(FOperand & Operand)
{
}

void FForwardVisitor::Visit(FAdd & Add)
{
	auto&& InputVertices = Add.GetInputVertices();
	double Result = 0.0;

	for (auto&& InputVertex : InputVertices)
	{
		Result += InputVertex->GetValue();
	}

	Add.SetValue(Result);

	for (auto&& InputVertex : InputVertices)
	{
		Add.SetEdgeGrediantPair(InputVertex->GetKey(), 1.0);
	}
}


void FForwardVisitor::Visit(FMultiply & Multiply)
{
	auto&& InputVertices = Multiply.GetInputVertices();
	double Result = 1.0;

	for (auto&& InputVertex : InputVertices)
	{
		Result *= InputVertex->GetValue();
	}

	Multiply.SetValue(Result);

	for (auto&& InputVertex : InputVertices)
	{
		Multiply.SetEdgeGrediantPair(InputVertex->GetKey(), Result / InputVertex->GetValue());
	}
}

void FForwardVisitor::Visit(FSubstract & Substract)
{
	auto&& InputVertices = Substract.GetInputVertices();
	double Result = InputVertices[0]->GetValue() - InputVertices[1]->GetValue();
	
	Substract.SetValue(Result);

	Substract.SetEdgeGrediantPair(InputVertices[0]->GetKey(), 1.0);
	Substract.SetEdgeGrediantPair(InputVertices[0]->GetKey(), -1.0);
}

void FForwardVisitor::Visit(FDivide & Divide)
{
	auto&& InputVertices = Divide.GetInputVertices();
	double UpValue = InputVertices[0]->GetValue();
	double DownValue = InputVertices[1]->GetValue();
	double Result = UpValue / DownValue;

	Divide.SetValue(Result);

	Divide.SetEdgeGrediantPair(InputVertices[0]->GetKey(), 1 / DownValue);
	Divide.SetEdgeGrediantPair(InputVertices[0]->GetKey(), - UpValue / (DownValue * DownValue));
}

void FForwardVisitor::Visit(FSin & Sin)
{
	auto&& InputVertex = Sin.GetInputVertices()[0];
	double InputValue = InputVertex->GetValue();
	double Result = std::sin(InputValue);

	Sin.SetValue(Result);

	Sin.SetEdgeGrediantPair(InputVertex->GetKey(), std::cos(InputValue));
}

void FForwardVisitor::Visit(FCos & Cos)
{
	auto&& InputVertex = Cos.GetInputVertices()[0];
	double InputValue = InputVertex->GetValue();
	double Result = std::cos(InputValue);

	Cos.SetValue(Result);

	Cos.SetEdgeGrediantPair(InputVertex->GetKey(), -std::sin(InputValue));
}

void FForwardVisitor::Visit(FPower & Power)
{
	auto&& InputVertices = Power.GetInputVertices();
	double BaseValue = InputVertices[0]->GetValue();
	double ExponentValue = InputVertices[1]->GetValue();
	double Result = std::pow(BaseValue, ExponentValue);

	Power.SetValue(Result);

	Power.SetEdgeGrediantPair(InputVertices[0]->GetKey(), ExponentValue * Result / BaseValue);
	Power.SetEdgeGrediantPair(InputVertices[1]->GetKey(), Result * std::log(BaseValue));
}
