#pragma once
#include "ship.hpp"
#include "cargo.hpp"
#include <memory>

class Player {
public:
    std::unique_ptr<Ship> getShip () { ship_.get(); }
    int getMoney () { return money_; }
    size_t getAvailableSpace () { return availableSpace_; }

    size_t getSpeed() const { return ship_.get()->getSpeed(); }
    

    Player::Player(std::unique_ptr<Ship> ship, int money, int availableSpace);

private:
    std::unique_ptr<Ship> ship_ = std::make_unique<Ship>();
    int money_;
    size_t availableSpace_;
};