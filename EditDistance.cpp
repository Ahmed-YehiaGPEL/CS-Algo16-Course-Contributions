#include "EditDistance.h"

int EditDistance::minOfThree(int x, int y, int z)
{
	return std::min(std::min(x, y), z);
}
int EditDistance::GetEditDistance(char* str1, char* str2, int l1, int l2,const int MaxSize)
{
	std::vector<std::vector<int>> dp(MaxSize, std::vector<int>(MaxSize));
	/*Start algorithm*/
	for (auto i = 0; i <= l1; i++)
	{
		for (auto j = 0; j <= l2; j++)
		{
			if (i == 0)
				dp[i][j] = j;
			else if (j == 0)
				dp[i][j] = i;
			else if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = 1 + minOfThree
				(
					dp[i][j - 1], // Insert
					dp[i - 1][j], //Remove
					dp[i - 1][j - 1] //Replace
				);
				
		}
	}
	return dp[l1][l2];
}
