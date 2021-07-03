#pragma once
#include "coordinates.hpp"

//Class responsible for representing island in game
class Island {
private:
    Coordinates position_;

public:
    explicit Island(Coordinates position);
    Coordinates getPosition() { return position_; }
    void SetPosition(const Coordinates& position) { position_ = position; }
};