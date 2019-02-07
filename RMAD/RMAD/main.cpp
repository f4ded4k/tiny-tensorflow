#include <iostream>
#include "Framework.h"



int main()
{
	auto G = FGraph();
	G.SetAsDefault();

	auto X = variable();
	auto P = placeholder();

	auto Z = X * X + 2 * X + P;

	double LearningRate = 0.005;

	FGraph::FeedMap FeedMap = { {P,4} };

	for (int i = 0; i < 50; i++)
	{
		G.Train(Z, LearningRate, 10, FeedMap);
		std::cout << G.Evaluate(Z, FeedMap) << std::endl;
	}

	return 0;
}