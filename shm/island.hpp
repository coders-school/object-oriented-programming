#pragma once
#include "coordinates.hpp"
#include "Store.hpp"

//Class responsible for representing island in game

class Island {
private:
    Store store_;
    Coordinates position_;
public:
    explicit Island(Coordinates, Time*);
    Coordinates getPosition() { return position_; }
    void SetPosition(const Coordinates& position) { position_ = position; }
    Store* returnIslandStore();
};
