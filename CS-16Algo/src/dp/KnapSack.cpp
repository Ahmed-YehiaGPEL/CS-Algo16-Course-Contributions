#include "../../inc/dp/KnapSack.h"

int KnapSack::SolveKnapSack(int totalWeight, std::vector<int> weight, std::vector<int>value)
{
	auto n = weight.size();
	if (n != value.size()) return - 1;
	knapSackDP = std::vector<std::vector<int>>(n+1, std::vector<int>(totalWeight+1));
	for (auto i = 0; i <= n;i++)
	{
		for (auto w = 0; w <= totalWeight;w++)
		{
			if (i == 0 || w == 0)
				knapSackDP[i][w] = 0;
			else if (weight[i - 1] <= w)
			{
				knapSackDP[i][w] = max(value[i - 1] + knapSackDP[i - 1][w - weight[i - 1]], knapSackDP[i - 1][w]);

			}
			else
				knapSackDP[i][w] = knapSackDP[i - 1][w];
		}
	}
	return knapSackDP[n][totalWeight];
}

int KnapSack::max(int a, int b)
{
	return a > b ? a : b;
}
