#pragma once

#include <memory>
#include <ostream>

#include "coordinates.hpp"
#include "store.hpp"

class Time;

class Island : public Coordinates {
public:
    Island() {}
    Island(int posX, int posY, Time* gameTime);
    Coordinates getCoordinates() const { return position_; }
    std::shared_ptr<Store> getStore() const { return store_;}

private:
    Time* timeTracker_;
    Coordinates position_;
    std::shared_ptr<Store> store_;
};
