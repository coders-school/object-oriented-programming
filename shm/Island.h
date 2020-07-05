#pragma once

#include "Coordinates.h"
#include "Store.h"
#include "Time.h"

class Island {
public:
    Island() = default;
    Island(size_t position_x, size_t position_y, Time* time);
    Coordinates getCoordinates() const;
    Store* getStore();

private:
    Store* store_;
    Coordinates position_;
};
