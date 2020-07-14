#pragma once

#include <memory>

#include "cargoHolder.hpp"
#include "ship.hpp"

class Player : public CargoHolder,
               public Ship::Delegate {
public:
    Player(Ship& ship, size_t money, size_t availableSpace);

    std::shared_ptr<Ship> getShip() { return ship_; }
    size_t getMoney() const { return money_; }
    size_t getavailableSpace() const { return availableSpace_; }
    size_t getSpeed() const { return ship_->getSpeed(); }
    std::shared_ptr<Cargo> getCargo(size_t index) const { return ship_->getCargo(index); }
    //Override from Ship::Delegate
    void payCrew(size_t money) override;

    virtual ~Player() {}

    void changeMoney(size_t amount);
    void clearEmptyCargo() { ship_->clearEmptyCargo(); };

    /* override from CargoHolder through its ship */
    const std::vector<std::shared_ptr<Cargo>>& getAllCargo() const override { return ship_->getAllCargo(); }
    void receiveCargo(Cargo* cargo, size_t amount, CargoHolder* cargoHolder) override;
    void clearEmptyCargos() override;

private:
    size_t getAvailableSpace() { return ship_->getAvailableSpace(); }

    std::shared_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;
};
