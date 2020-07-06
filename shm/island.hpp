#pragma once

#include "coordinates.hpp"
#include "store.hpp"
#include "time.hpp"

class Island {
public:
    Island(Coordinates position, Time* time);
    Coordinates getPosition() const;
    std::shared_ptr<Store> getStore() const;
    void createStore();

private:
    Coordinates position_;
    std::shared_ptr<Store> store_;
    Time* time_;
};
