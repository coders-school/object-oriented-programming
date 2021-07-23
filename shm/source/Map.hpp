#pragma once
#include <algorithm>
#include <vector>

#include "Fortune.hpp"
#include "Island.hpp"

class Map {
	size_t horizonLimit_;
	std::vector<Island> islands_;
	Island* currentPosition_;

public:
	Map();

	Island* getIsland(const Island::Coordinates& coordinate);

private:
	std::vector<Island> generateIslands(const size_t numberOfIslands) const;
	std::vector<int> generateRandomPositions(const size_t n) const;
};