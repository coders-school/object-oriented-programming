#pragma once
#include <vector>
#include "Island.h"

public class Map {
private:
	std::vector<Island> islands_;
	Island* currentPosition_;
};