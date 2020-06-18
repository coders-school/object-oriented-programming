#pragma once
#include <iostream>
#include <memory>

#include "cargo.hpp"
#include "ship.hpp"

class Player {
private:
    std::unique_ptr<Ship> ship_;
    size_t availableSpace_;
    size_t money_;

    size_t CountAvailableSpace() const;

public:
    Player(std::unique_ptr<Ship> ship, size_t money, size_t availableSpace);

    std::unique_ptr<Ship> getShip();
    size_t getMoney() const;
    size_t getAvailableSpace() const;

    size_t getSpeed() const;
    Cargo* getCargo(size_t index) const;
};
