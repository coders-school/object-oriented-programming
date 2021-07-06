#pragma once

#include <cstddef>
#include <memory>

#include "shm/inc/Delegate.hpp"
#include "shm/inc/Ship.hpp"

class Cargo;

class Player : public Delegate {
public:
    Player(std::unique_ptr<Ship> ship, size_t money, size_t availableSpace);

    std::unique_ptr<Ship> getShip() { return std::move(ship_); };
    size_t getMoney() const { return money_; };
    size_t getAvailableSpace() const { return availableSpace_; };
    size_t getSpeed() const;
    std::shared_ptr<Cargo> getCargo(size_t index) const;

    //override from Delegate
    void payCrew(const size_t payCrew) override;

private:
    std::unique_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;
    size_t countAvailableSpace() const;
};
