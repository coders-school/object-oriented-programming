#pragma once
#include "Cargo.hpp"
#include "Ship.hpp"
#include <memory>

class Player {
public:
    Player(Ship&, size_t, size_t);
 
    std::unique_ptr<Ship> getShip() { return std::move(ship_); };
    size_t getMoney() const { return money_; };
    size_t getAvailableSpace() const { return availableSpace_; };

    size_t getSpeed() const;
    Cargo* getCargo(size_t index) const;

private:
    std::unique_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;
};