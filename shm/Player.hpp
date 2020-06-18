#pragma once

#include <memory>

#include "Cargo.hpp"
#include "Ship.hpp"

class Player {
public:
    Player(std::unique_ptr<Ship> ship, size_t money) {
        ship_ = std::move(ship);
        money_ = money;
        avaliableSpace_ = countAvailableSpace();
    };

    size_t getMoney() const { return money_; };
    size_t getAvaliableSpace() const { return avaliableSpace_; };
    size_t getSpeed() const { return ship_->getSpeed(); };
    Cargo* getCargo(size_t index) { return ship_->getCargo(index); };

private:
    std::unique_ptr<Ship> ship_;
    size_t money_;
    size_t avaliableSpace_;

    size_t countAvailableSpace();
};
