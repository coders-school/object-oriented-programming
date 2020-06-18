#pragma once
#include <memory>

#include "ship.hpp"

class Player {
public:
    Player(std::unique_ptr<Ship> ship, size_t money, size_t availableSpace);

    size_t getAvailableSpace_() const { return availableSpace_; }
    size_t getMoney() const { return money_; }
    size_t getSpeed() const { return ship_->getSpeed(); }
    Cargo* getCargo(size_t index) const;

private:
    std::unique_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;

    void countAvailableSpace();
};
