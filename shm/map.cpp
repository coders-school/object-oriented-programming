#include "map.hpp"
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <random>

map::map() {
    auto returnPaired = generateIslandPosition();
    std::vector<Island> vecofIslands{};
    map_.reserve(MAX_ISLANDS);
    for (int i = 0; i < MAX_ISLANDS; ++i) {
        map_.push_back(std::make_shared<Island>(Coordinates(returnPaired[i].first, returnPaired[i].second)));
    }
}

void map::printIslands() const {
    for (auto& a : map_) {
        std::cout << a.get()->getPosition().getPositionX() << ' ' << a.get()->getPosition().getPositionY() << '\n';
    }
}

std::vector<std::pair<int, int>> map::generateIslandPosition() {
    std::map<int, int> vecOfPairs{};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 16);
    while (vecOfPairs.size() < MAX_ISLANDS) {
        vecOfPairs[distrib(gen)] = distrib(gen);
    }
    std::vector<std::pair<int, int>> returnPair{};
    for (auto& a : vecOfPairs) {
        returnPair.push_back(std::make_pair(a.first, a.second));
    }
    returnPair.shrink_to_fit();
    return returnPair;
}

Island* map::getIsland(const Coordinates& position) const {
    if (map_.size() != 0) {
        auto it = std::find_if(map_.begin(), map_.end(), [&](std::shared_ptr<Island> const& search) {
            return search->getPosition().getPositionX() == position.getPositionX() && search->getPosition().getPositionY() == position.getPositionY();
        });
        if(it != map_.end()) {
            return map_[std::distance(map_.begin(),it)].get();
        }
    }
    return nullptr;
}
