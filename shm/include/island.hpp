#pragma once

#include "coordinates.hpp"
#include "store.hpp"

#include <memory>

class Island {
public:
    Island(int positionX, int positionY);
    Coordinates getCoordinates() const { return position_; }
    std::shared_ptr<Store> getStore() const { return store_; }

private:
    Coordinates position_;
    std::shared_ptr<Store> store_;
};
