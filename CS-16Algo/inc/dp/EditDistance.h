#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class EditDistance {
private:
	int minOfThree(int, int, int) const;
public:
	int GetEditDistance(char*, char*, int, int,const int) const;
};
