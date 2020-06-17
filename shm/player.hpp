#pragma once
#include <memory>

#include "cargo.hpp"
#include "ship.hpp"

class Player {
public:
    size_t getSpeed() const { return ship_->getSpeed(); }
    Cargo* getCargo(size_t index) const { return ship_->getCargo(index); }

private:
    std::shared_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;
};