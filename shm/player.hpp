#pragma once

#include <memory>

#include "cargo.hpp"
#include "ship.hpp"

class Player {
public:
    Player(const Ship& ship, int money, size_t availableSpace);

    std::shared_ptr<Ship> getShip() const { return ship_; };
    int getMoney() const { return money_; };
    size_t getAvailableSpace() const { return availableSpace_; };

    size_t getSpeed() const { return ship_->getSpeed(); };
    Cargo* getCargo(size_t index) const { return ship_->getCargo(index); };

private:
    std::shared_ptr<Ship> ship_{};
    int money_{};
    size_t availableSpace_{};

    size_t calcAvailableSpace();
};
