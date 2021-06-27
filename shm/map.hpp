#pragma once
#include "island.hpp"
#include <vector>

class map {

  map() : map_(0) {}

  std::vector<Island> map_{};

  Island *currentPosition_{};
}