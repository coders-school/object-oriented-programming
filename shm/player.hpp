#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "ship.hpp"
#include "cargo.hpp"

class Player {
private:
    std::shared_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;
public:
    Player(std::shared_ptr<Ship> ship, size_t money, size_t availableSpace)
        : ship_(ship)
        , money_(money)
        , availableSpace_(availableSpace)
    {}
    Player(std::shared_ptr<Ship> ship)
        : Player(ship, 0, 0)
    {}
    ~Player();

    std::shared_ptr<Ship> getShip() const;
    size_t getMoney() const;
    size_t getAvailableSpace() const;
    size_t getSpeed() const;
    std::shared_ptr<Cargo> getCargo(size_t index) const;
};
