#pragma once

#include "coordinates.hpp"
#include "store.hpp"

class Island {
public:
    Island(int positionX, int positionY);
    Island(const Island& island);

    Coordinates getPosition() const { return position_; }
    Store* getStore() const { return store_.get(); }

private:
    Coordinates position_;
    std::shared_ptr<Store> store_;
};
