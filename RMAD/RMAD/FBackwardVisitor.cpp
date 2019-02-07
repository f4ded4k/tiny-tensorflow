#include "FBackwardVisitor.h"
#include "FOperand.h"
#include "FAdd.h"
#include "FMultiply.h"
#include "FSubstract.h"
#include "FDivide.h"
#include "FSin.h"
#include "FCos.h"
#include "FPower.h"


void FBackwardVisitor::VisitOperator(FOperator & Operator)
{
	if (Operator.GetKey() == mSeedKey)
	{
		Operator.SetGrediant(1.0);
	}
	else
	{
		double FinalGrediant = 0.0;
		int InputKey = Operator.GetKey();
		auto&& OutputOperators = Operator.GetOutputOperators();

		for (FOperator* OutputOperator : OutputOperators)
		{
			FinalGrediant += OutputOperator->GetEdgeGrediantOrZero(InputKey) * OutputOperator->GetGrediant();
		}

		Operator.SetGrediant(FinalGrediant);
	}
}


FBackwardVisitor::FBackwardVisitor(double LearningRate, int SeedKey)
	: mLearningRate(LearningRate), mSeedKey(SeedKey)
{
}

FBackwardVisitor::~FBackwardVisitor() = default;

void FBackwardVisitor::Visit(FOperand & Operand)
{
	if (Operand.GetType() == EType::Variable)
	{
		double FinalGrediant = 0.0;

		if (Operand.GetKey() == mSeedKey)
		{
			FinalGrediant = 1.0;
		}
		else
		{
			int InputKey = Operand.GetKey();
			auto&& OutputOperators = Operand.GetOutputOperators();

			for (FOperator* Operator : OutputOperators)
			{
				FinalGrediant += Operator->GetEdgeGrediantOrZero(InputKey) * Operator->GetGrediant();
			}
		}

		Operand.SetValue(Operand.GetValue() - mLearningRate * FinalGrediant);
	}
}

void FBackwardVisitor::Visit(FAdd & Add)
{
	VisitOperator(Add);
}

void FBackwardVisitor::Visit(FMultiply & Multiply)
{
	VisitOperator(Multiply);
}

void FBackwardVisitor::Visit(FSubstract & Substract)
{
	VisitOperator(Substract);
}

void FBackwardVisitor::Visit(FDivide & Divide)
{
	VisitOperator(Divide);
}

void FBackwardVisitor::Visit(FSin & Sin)
{
	VisitOperator(Sin);
}

void FBackwardVisitor::Visit(FCos & Cos)
{
	VisitOperator(Cos);
}

void FBackwardVisitor::Visit(FPower & Power)
{
	VisitOperator(Power);
}
