#pragma once
#include <algorithm>
#include <vector>
#include <iostream>

#include "Fortune.hpp"
#include "Island.hpp"

class Map {
	size_t horizonLimit_;
	std::vector<Island> islands_;
	Island* currentPosition_;

public:
	Map():
		horizonLimit_(100),
		islands_(generateIslands(10)),
		currentPosition_()
	{}

	Map(const Map& map):
	 	horizonLimit_(map.horizonLimit_),
		islands_(map.islands_),
		currentPosition_(map.currentPosition_)	
	{}
	
	Map& operator=(const Map& map) {
		horizonLimit_ = map.horizonLimit_;
		islands_ = map.islands_;
		currentPosition_ = currentPosition_;
		return *this;
	}

private:
	std::vector<Island> generateIslands(const size_t numberOfIslands) const {
		if (numberOfIslands < 1) {
			return {};
		}
		auto xyPositions = generateRandomPositions(numberOfIslands);		
		std::vector<Island> islands;
		islands.reserve(xyPositions.size() / 2);
		for (size_t i = 1; i < xyPositions.size(); i += 2) {
			islands.emplace_back(Coordinates(xyPositions.at(i - 1), xyPositions.at(i)));
		}		
		return islands;
	}

	std::vector<int> generateRandomPositions(const size_t n) const {
		auto positions = Fortune::getNumbersEvenlyDistributed(0, static_cast<int>(horizonLimit_), static_cast<int>(n));
		auto yPositions = Fortune::getNumbersEvenlyDistributed(0, static_cast<int>(horizonLimit_), static_cast<int>(n));
		positions.insert(positions.end(), yPositions.begin(), yPositions.end());
		Fortune::shuffle(positions);
		return positions;
	}

};