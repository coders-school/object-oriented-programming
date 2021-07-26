#include "Fortune.hpp"

std::random_device randomDevice;
std::mt19937 randomEngine(randomDevice());

int Fortune::getNumber(int first, int last) {
    if (first > last) {
        std::swap(first, last);
    }
    std::uniform_int_distribution<int> distribution(first, last);
    return distribution(randomEngine);
}

std::vector<int> Fortune::getNumbersEvenlyDistributed(int first, int last, const int n) {
	if (n < 1) {
		return {};
	}
    if (first > last) {
        std::swap(first, last);
    }
	std::vector<int> result(n); 
	for (int i = 0; i < n; ++i) {
		int localFirst = (last / n * i) + first;
		int localLast = (last / n * (i + 1)) + first;
		result.at(i) = (getNumber(localFirst, localLast));
	}
	return result;
}

void Fortune::shuffle(std::vector<int>& vector) {
	std::shuffle(vector.begin(), vector.end(), randomEngine);
}
