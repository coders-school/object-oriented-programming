#pragma once
#include <memory>

#include "cargo.hpp"
#include "ship.hpp"

class Player {
public:
    size_t getSpeed() const { return ship_->getSpeed(); }

private:
    std::shared_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;
};