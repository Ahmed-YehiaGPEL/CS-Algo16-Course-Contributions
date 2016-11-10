#pragma once
#include <algorithm>
#include <vector>

class AssemblyLine
{
public:
	/*
	
	Algorithm:
		First time combute entry + station time
		T1[0] = e[0] + a[0][0]
		T2[0] = e[1] + a[1][0];
		Recur:
		T1[i] = min(T1[i-1] + a[0][i], T2[i-1] + t[1][i] + a[0][i]);
		T2[i] = min(T2[i-1] + a[1][i], T1[i-1] + t[0][i] + a[1][i]);
		Final Get the min solution with adding exit time:
		min(T1[NUM] + x[0], T2[NUM] + x[1]);
	*/
	int CalculateMinTime(std::vector<std::vector<int> >, std::vector<std::vector<int> >, int*, int*) const;
};
