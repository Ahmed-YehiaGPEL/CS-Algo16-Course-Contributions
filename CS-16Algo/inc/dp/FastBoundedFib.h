#pragma once
#include <vector>
#include <map>
#define ulong unsigned long long

class FastBoundedFibonacci
{
public:
	FastBoundedFibonacci();
	ulong CalculateBoundedFibonacci(ulong);

private:
	static std::vector<std::vector<ulong> > multiplyMatrices(std::vector<std::vector<unsigned long long>>, std::vector<std::vector<unsigned long long>>);
	std::vector<std::vector<unsigned long long>> powerMatrix(std::vector<std::vector<unsigned long long>>, int n);
	std::map<int, std::vector<std::vector<ulong> > > _memory;
	const std::vector<std::vector<ulong>> identityMatrix = { { 1,0 },{ 0,1 } };
	const std::vector<std::vector<ulong>> baseMatrix = { { 1,1 },{ 1,0 } };
	const static int B = 1000000;
};

