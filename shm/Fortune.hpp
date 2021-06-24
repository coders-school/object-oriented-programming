#pragma once
#include <exception>
#include <random>
#include <stdexcept>
#include <vector>

struct Fortune {
    static int getNumber(int first, int last) {
        const int result = makeRandomNumber(first, last);
        if (result < first || result > last) {
            throw std::logic_error("Fortune::getNumber(int,int): Result value out of scope");
        }
        return result;
    }

	static std::vector<int> getNumbersEvenlyDistributed(int first, int last, const int n) {
		if (n < 1) {
			return {};
		}
		std::vector<int> result(n); 
		for (int i = 0; i < n; ++i) {
			int localFirst = (last / n * i) + first;
			int localLast = (last / n * (i + 1)) + first;
			result.at(i) = (getNumber(localFirst, localLast));
		}
		return result;
	}

	static void shuffle(std::vector<int>& vector) {
		std::random_device random_device;
        std::mt19937 random_engine(random_device());
		std::shuffle(vector.begin(), vector.end(), random_engine);
	}

private:
    static int makeRandomNumber(const int first, const int last) {
        std::random_device random_device;
        std::mt19937 random_engine(random_device());
        std::uniform_int_distribution<int> distribution(first, last);
        return distribution(random_engine);
    }
};