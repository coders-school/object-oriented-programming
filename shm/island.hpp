#pragma once

#include "coordinates.hpp"
#include "store.hpp"

class Island {
public:
    Island(Coordinates position);
    Coordinates getPosition() const;
    Store getStore() const;
	void createStore();

private:
    Coordinates position_;
    Store store_;
};
