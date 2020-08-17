#pragma once

#include <ostream>
#include <vector>

#include "Island.hpp"
#include "Time.hpp"


constexpr size_t amountOfIslands{10};
constexpr size_t minPositionXY{1};
constexpr size_t maxPositionXY{10};


class Map {
private:
    void generateIslands(int numOfIslandsToGenerate, std::shared_ptr<Time>& time);
    Island* currentPosition_{nullptr};
    std::vector<Island> islandsLocations_;
    void populateMapScreen(std::ostream& out) const;

public:
    Map(std::shared_ptr<Time>& time);
    void setCurrentPosition(Island* const currentPosition);
    Island* getCurrentPosition() const { return currentPosition_; };
    void addIsland(const Island& newIsland);
    Island* getIsland(const Coordinates& coordinate);
    friend std::ostream& operator<<(std::ostream& out, const Map& map);
    size_t getDistanceToIsland(Island* destination);
};
