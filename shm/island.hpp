#pragma once
#include "coordinates.hpp"
#include "store.hpp"

class Island {    
public:
    Island() {
     
    }

    Island(Coordinates position, Store store)
    : position_(position), store_(store)
    {}

    Coordinates getPosition() const;
    void setPosition(Coordinates);
    std::shared_ptr<Store> getStore();
   //int getName() const;

private:
    Coordinates position_;
    Store store_;
   // int name_;
};