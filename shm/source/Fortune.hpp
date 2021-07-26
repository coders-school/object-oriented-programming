#pragma once
#include <algorithm>
#include <random>
#include <vector>

namespace Fortune {	
	int getNumber(int first, int last);
	std::vector<int> getNumbersEvenlyDistributed(int first, int last, const int n);
	void shuffle(std::vector<int>& vector);
}