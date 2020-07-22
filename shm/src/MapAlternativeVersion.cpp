#include "MapAlternativeVersion.hpp"

#include <algorithm>
#include <random>
#include <string>

constexpr uint16_t numberOfIslands = 10;
constexpr uint16_t axisX = 100;
constexpr uint16_t axisY = 100;

Map::Map() {
    std::vector<Island> islands_(numberOfIslands);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> genPositionX(0, axisX);
    std::uniform_int_distribution<> genPositionY(0, axisY);
    std::vector<std::pair<uint16_t, uint16_t>> positionsBefore;
    uint16_t counter{};

    do {
        uint16_t positionX = genPositionX(gen);
        uint16_t positionY = genPositionY(gen);

        if (std::find_if(positionsBefore.begin(), positionsBefore.end(),
                         [positionX, positionY](const auto& position) {
                             return position.first == positionX && position.second == positionY;
                         }) == positionsBefore.end()) {
            positionsBefore.push_back({positionX, positionY});
            islands_.push_back(Island(positionX, positionY));
            counter++;
        }

    } while (counter != numberOfIslands);

    currentPosition_ = &islands_.front();
}

Island* Map::getIsland(const Coordinates& coordinates) {
    auto soughtIsland = std::find_if(islands_.begin(), islands_.end(),
                                     [&coordinates](auto& island) {
                                         return coordinates == island.getPosition();
                                     });
    if (soughtIsland != islands_.end()) {
        return &*soughtIsland;
    }
    return nullptr;
}
