#pragma once
#include <utility>
#include <vector>

class KnapSack
{
public:
	int SolveKnapSack(int, std::vector<int>,std::vector<int>);
private:
	std::vector<std::vector<int>> knapSackDP;
	static int max(int, int);
};


