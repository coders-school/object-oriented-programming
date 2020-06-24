#pragma once
#include <iostream>
#include <memory>

#include "cargo.hpp"
#include "ship.hpp"

class Player {
public:
    Player(std::shared_ptr<Ship> ship, uint32_t money, uint32_t availableSpace);

    std::shared_ptr<Ship> getShip();
    uint32_t getMoney() const;
    uint32_t getAvailableSpace() const;
    uint32_t getSpeed() const;

    Cargo* getCargo(uint32_t index) const;
    void purchaseCargo(std::shared_ptr<Cargo> cargo, uint32_t amount, uint32_t price);
    void sellCargo(Cargo* cargo, uint32_t price);

private:
    std::shared_ptr<Ship> ship_;
    uint32_t availableSpace_;
    uint32_t money_;

    uint32_t CountAvailableSpace() const;
};
