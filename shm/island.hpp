#pragma once
#include "coordinates.hpp"
#include "store.hpp"

class Island{    
public:
    Island() {
     
    }

    Island(Coordinates position, std::shared_ptr<Store> store)
    : position_(position), store_(store)
    {}

    Coordinates getPosition() const;
    void setPosition(Coordinates);
    std::shared_ptr<Store> getStore();

protected:
    std::shared_ptr<Store> store_;

private:
    Coordinates position_;
};