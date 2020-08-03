#pragma once

#include "Coordinates.hpp"
#include "Store.hpp"
#include "Time.hpp"

class Island {
private:
    Coordinates position_;
    std::shared_ptr<Store> store_;

public:
    Island(size_t positionX, size_t positionY, std::shared_ptr<Time>& time);
    Coordinates getPosition() const { return position_; };
};
