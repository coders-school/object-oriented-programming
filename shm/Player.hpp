#pragma once

#include "Ship.hpp"
#include "Cargo.hpp"

#include <memory>

class Player {
public:
    Player(std::shared_ptr<Ship> s = nullptr, size_t m = 0, size_t as = 0)
            :ship_(s), money_(m), availableSpace_(as) {}

    std::shared_ptr<Ship> getShip() const { return ship_; }
    size_t getMoney()               const { return money_; }
    size_t getAvailableSpace()      const { return availableSpace_; }

    size_t getSpeed() const { return ship_->getSpeed(); }
    Cargo* getCargo(size_t index) const;

private:
    std::shared_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;

    void countAvailableSpace();
};
