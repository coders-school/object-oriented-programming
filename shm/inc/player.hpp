#include <iostream>
#include <memory>

#include "ship.hpp"

class Player {
public:
    Player(Ship& ship, size_t money, size_t availableSpace)
        : ship_(std::make_unique<Ship>(ship)), money_(money), availableSpace_(availableSpace) {}

    std::unique_ptr<Ship> getShip() { return std::move(ship_); }
    size_t getMoney() const { return money_; }
    size_t getavailableSpace() const { return availableSpace_; }

    size_t getSpeed() const { return ship_->getSpeed(); }
    Cargo getCargo(size_t index) const { return ship_->getCargo(index); }

private:
    size_t calculateavailableSpace();

    std::unique_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;
};
