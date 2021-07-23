#include "Map.hpp"


Map::Map():
	horizonLimit_(100),
	islands_(generateIslands(10)),
	currentPosition_()
{}

Island* Map::getIsland(const Island::Coordinates& coordinate) {
	auto result = std::find_if(islands_.begin(), islands_.end(), [coordinate](const Island& island){ return island.getPosition() == coordinate; });
	if (result != islands_.end()) {
		return &(*result);
	}
	return nullptr;
}

std::vector<Island> Map::generateIslands(const size_t numberOfIslands) const {
	if (numberOfIslands < 1) {
		return {};
	}
	auto xyPositions = generateRandomPositions(numberOfIslands * 2);		
	std::vector<Island> islands;
	islands.reserve(xyPositions.size() / 2);
	for (size_t i = 1; i < xyPositions.size(); i += 2) {
		islands.emplace_back(Island::Coordinates(xyPositions.at(i - 1), xyPositions.at(i)));
	}		
	return islands;
}

std::vector<int> Map::generateRandomPositions(const size_t numberOfPositions) const {
	auto positions = Fortune::getNumbersEvenlyDistributed(0, static_cast<int>(horizonLimit_), static_cast<int>(numberOfPositions));
	Fortune::shuffle(positions);
	return positions;
}