#include "map.hpp"

#include <algorithm>
#include <random>

Map::Map() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 255);
    for (size_t i = 0; i < 10; ++i) {
        Island temp(distrib(gen), distrib(gen));
        if (std::none_of(Islands_.begin(), Islands_.end(), [temp](const Island& islnd) {
                return islnd.getCoordinates() == temp.getCoordinates();
            })) {
            Islands_.push_back(temp);
        } else {
            Island temp2(distrib(gen), distrib(gen));
            Islands_.push_back(temp2);
        }
    }
}
