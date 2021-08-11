#pragma once
#include "coordinates.hpp"
#include "Store.hpp"

//Class responsible for representing island in game
class Island {
private:
    Coordinates position_;
    Store store_;

public:
    explicit Island(Coordinates position, Time  * time);
    Coordinates getPosition() { return position_; }
    void SetPosition(const Coordinates &position) { position_ = position; }
};
