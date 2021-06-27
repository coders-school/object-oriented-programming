#pragma once

#include "ship.hpp"
#include "cargo.hpp"
#include <memory>

class Player {
private:
    std::unique_ptr<Ship> ship_;
    int money_;
    size_t availableSpace_;
    size_t calculateAvailableSpace();

public:
    Player(std::unique_ptr<Ship>& ship, int money, int availableSpace);

    std::unique_ptr<Ship>& getShip();
    int getMoney();
    size_t getAvailableSpace();

    size_t getSpeed() const;
    Cargo* getCargo(size_t index) const;
};