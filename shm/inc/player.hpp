#pragma once

#include "delegate.hpp"
#include "ship.hpp"

class Player : public Delegate {
public:
    Player(Ship& ship, size_t money, size_t availableSpace);

    size_t getMoney() const { return money_; }
    size_t getAvailableSpace() const { return ship_->getAvailableSpace(); }
    size_t getSpeed() const { return ship_->getSpeed(); }
    std::shared_ptr<Cargo> getCargo(size_t index) const;
    Cargo* getCargo(const std::string& name) const;

    bool printShipCargo();

    void payCrew(size_t money) override;

    void purchaseCargo(std::unique_ptr<Cargo> cargo, size_t price);
    void sellCargo(std::unique_ptr<Cargo> cargo, size_t price);

private:
    Ship* ship_;
    size_t money_;
    size_t availableSpace_;
};
