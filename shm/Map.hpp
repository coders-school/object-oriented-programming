#pragma once

#include "Island.hpp"

#include <memory>
#include <vector>

class Map {
public:

private:
    std::vector<Island> islandsArrangement_;
    std::shared_ptr<Island> currentPosition_{};
};