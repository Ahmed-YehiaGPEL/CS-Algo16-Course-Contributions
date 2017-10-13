#include "../../inc/dp/FastBoundedFib.h"

FastBoundedFibonacci::FastBoundedFibonacci()
{
	_memory[0] = identityMatrix;
}

unsigned long long FastBoundedFibonacci::CalculateBoundedFibonacci(ulong n)
{
	if (n <= 1) return n;
	auto res = powerMatrix(baseMatrix, n);
	return res[0][1] % B;
}
std::vector<std::vector<ulong>> FastBoundedFibonacci::multiplyMatrices(std::vector<std::vector<unsigned long long>>  m1, std::vector<std::vector<unsigned long long>>  m2)
{
	auto m11 = m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0];
	auto m12 = m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1];
	auto m21 = m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0];
	auto m22 = m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1];
	std::vector<std::vector<ulong>> res = { {m11,m12},{m21,m22} };
	return res;
}
std::vector<std::vector<unsigned long long>> FastBoundedFibonacci::powerMatrix(std::vector<std::vector<unsigned long long>>  pM, int n)
{
	if(_memory.find(n) != _memory.end())
		return _memory.find(n)->second;
	auto m1 = powerMatrix(pM, (int(n) / 2));
	auto m2 = multiplyMatrices(m1, m1);
	auto result = (n % 2 != 0) ? multiplyMatrices(m2, baseMatrix) : m2;
	_memory.insert(std::pair<int, std::vector<std::vector<ulong> > >(n, result));
	return result;
}

