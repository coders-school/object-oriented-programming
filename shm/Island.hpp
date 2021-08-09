#ifndef ISLAND_HPP
#define ISLAND_HPP
#include "Coordinates.hpp"
#include <memory>
#include "Store.hpp"

// Class used to represent island on the game map
class Island
{
private:
    Coordinates position_;
    std::unique_ptr<Store> store_;

public:
    explicit Island(Coordinates coordinates);
    Coordinates getPosition() const { return position_; };
    Store * getStore() const {return store_.get();};
};

#endif