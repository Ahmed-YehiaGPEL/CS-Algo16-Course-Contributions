#pragma once
#include <vector>

class LCS
{
public:
	int GetLCS(char*,char*);
private:
	static int max(int, int);
	std::vector<std::vector<int>> lcsDP;
};
