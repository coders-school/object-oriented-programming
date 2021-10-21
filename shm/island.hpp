#pragma once
#include "coordinates.hpp"
#include "store.hpp"

class Island{    
public:
    Island() = default;

    Island(Coordinates position, const std::shared_ptr<Store>& store);

    Coordinates getPosition() const;
    void setPosition(Coordinates);
    std::shared_ptr<Store> getStore();

protected:
    std::shared_ptr<Store> store_;

private:
    Coordinates position_;
};
