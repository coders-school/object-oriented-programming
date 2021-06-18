#pragma once
#include "inc/Cargo.hpp"
#include "inc/Ship.hpp"
#include <memory>
#include <numeric>

class Player {
public:
    Player(std::unique_ptr<Ship>, size_t, size_t);

    Ship* getShip() const { return ship_.get(); };
    size_t getMoney() const { return money_; };
    size_t getAvailableSpace() const { return availableSpace_; };

    size_t getSpeed() const;
    std::shared_ptr<Cargo> getCargo(size_t index) const;

private:
    std::unique_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;
    size_t countAvailableSpace() const;
};