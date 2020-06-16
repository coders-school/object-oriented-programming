#pragma once

#include "island.hpp"

#include <vector>

class Coordinates
{
public:
    Coordinates();
    Coordinates(const int positionX, const int positionY);

    Coordinates& operator==(std::vector<int> currentPosition) {
        currentPosition == position_;
        return *this;
    };

    int getPositionX() const { return positionX_; }
    int getPositionY() const { return positionY_; }
    std::vector<int> position_ = {getPositionX(), getPositionY()};

private:
    const int positionX_;
    const int positionY_;
};
