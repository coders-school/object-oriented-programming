#pragma once

#include <memory>

#include "delegate.hpp"
#include "ship.hpp"

class Player : public Delegate {
public:
    Player(Ship& ship, size_t money, size_t availableSpace);

    std::unique_ptr<Ship> getShip() { return std::move(ship_); }
    size_t getMoney() const { return money_; }
    size_t getAvailableSpace() const { return ship_->getAvailableSpace(); }
    size_t getSpeed() const { return ship_->getSpeed(); }
    std::shared_ptr<Cargo> getCargo(size_t index) const;
    Cargo* getCargo(const std::string& name) const;

    void setMoney(const size_t amount) { money_ = amount; }
    void setAvaiableSpace(const size_t amount) { availableSpace_ = amount; }
    void printShipCargo();
    bool addCargo(Cargo* cargo) { return ship_->addCargo(cargo); }
    bool removeCargo(Cargo* cargo) { return ship_->removeCargo(cargo); }

    void cloneCargo(Cargo* cargo){ 
        ship_->cloneCargo(cargo);
    
    }
    void payCrew(size_t money) override;

private:
    std::unique_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;
};
