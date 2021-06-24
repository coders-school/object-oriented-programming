#pragma once
#include <vector>

#include "Island.hpp"

class Map {
	std::vector<Island> islands_;
	Island* currentPosition_;

};