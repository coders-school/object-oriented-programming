#pragma once

#include <memory>

#include "ship.hpp"

class Player {
public:
    Player(Ship& ship, size_t money, size_t availableSpace);

    std::unique_ptr<Ship> getShip() { return std::move(ship_); }
    size_t getMoney() const { return money_; }
    size_t getAvailableSpace() const { return availableSpace_; }
    size_t getSpeed() const { return this->ship_->getSpeed(); }

private:
    std::unique_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;
};
