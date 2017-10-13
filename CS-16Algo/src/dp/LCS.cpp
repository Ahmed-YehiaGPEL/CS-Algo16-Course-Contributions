#include "../../inc/dp/LCS.h"

int LCS::GetLCS(char* str1, char* str2)
{
	int l1, l2;
	l1 = strlen(str1);
	l2 = strlen(str2);
	lcsDP = std::vector<std::vector<int>>(l1+1, std::vector<int>(l2+1));
	for ( auto i = 0; i <= l1; i++)
	{
		for (auto j = 0; j <= l2; j++)
		{
			if (i == 0 || j == 0)
			{
				lcsDP[i][j] = 0;
			}
			else if (str1[i - 1] == str2[j - 1])
				lcsDP[i][j] = 1 + lcsDP[i - 1][j - 1];
			else if (str1[i - 1] != str2[j - 1])
				lcsDP[i][j] = max(lcsDP[i - 1][j], lcsDP[i][j - 1]);
		}
	}
	return lcsDP[l1][l2];
}

int LCS::max(int a, int b)
{
	return (a > b) ? a : b;
}
