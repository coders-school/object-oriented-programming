#pragma once
#include <memory>

#include "ship.hpp"

class Player : public Ship::Delegate {
public:
    Player(std::shared_ptr<Ship> ship, size_t money);
    virtual ~Player() = default;

    std::shared_ptr<Ship> getShip() const { return ship_; }
    size_t getMoeny() const { return money_; }
    size_t getAvailableSpeed() const { return availableSpace_; }
    size_t getSpeed() const { return ship_->getSpeed(); }
    cargoPtr getCargo(size_t index) const { return ship_->getCargo()[index]; }

    void setShip(const std::shared_ptr<Ship>& ship);
    void addMoney(const size_t& money);
    void payCrew(size_t money) override;

private:
    std::shared_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;

    size_t countSpace();
};
