#pragma once
#include "Ship.hpp"
#include <memory>

class Player {
public:
    explicit Player(std::shared_ptr<Ship>, size_t, size_t); 
 
    std::shared_ptr<const Ship> getShip() const { return ptrShip; };
    size_t getMoney() const { return money_; };
    size_t getAvailableSpace() const { return availableSpace_; };

    size_t getSpeed() const;
    Cargo* getCargo(size_t index) const;

private:
    std::shared_ptr<Ship> ptrShip;
    size_t money_;
    size_t availableSpace_;
};