#include "../../inc/dp/AssemblyLine.h"

int AssemblyLine::CalculateMinTime(std::vector<std::vector<int>> stationTime, std::vector<std::vector<int>> lineTime, int *entryTime, int *exitTime) const
{
	std::vector<int>  T1(stationTime[0].size()), T2(stationTime[0].size());
	T1[0] = (stationTime[0][0] + entryTime[0]);
	T2[0] = (stationTime[1][0] + entryTime[1]);
	int i = 0;
	for (i = 1; i < stationTime[0].size(); ++i)
	{
		T1[i] = std::min(T1[i - 1] + stationTime[0][i], T2[i - 1] + lineTime[1][i] + stationTime[0][i]);
		T2[i] = std::min(T2[i - 1] + stationTime[1][i], T1[i - 1] + lineTime[0][i] + stationTime[1][i]);
	}
	return std::min(T1[stationTime[0].size()-1] + exitTime[0], T2[stationTime[0].size()-1] + exitTime[1]);
}	
