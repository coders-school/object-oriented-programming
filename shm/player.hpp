#pragma once
#include <memory>

#include "cargo.hpp"
#include "ship.hpp"

size_t constexpr START_MONEY = 1000;
size_t constexpr START_SPACE = 0;

class Player {
public:
    Player(std::unique_ptr<Ship> ship, size_t money, size_t space);
    Player(std::unique_ptr<Ship> ship);

    size_t getMoney() const { return money_; }
    size_t getAvailableSpace() const { return availableSpace_; }
    size_t getSpeed() const;
    Cargo getCargo(size_t index) const;

private:
    std::unique_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;
};
