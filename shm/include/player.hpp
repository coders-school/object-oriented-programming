#pragma once

#include <memory>

#include "ship.hpp"

class Player :public Ship::Delegate {
public:
    Player(std::unique_ptr<Ship> ship, size_t money, size_t availableSpace);

    size_t getAvailableSpace() const { return availableSpace_; }
    size_t getMoney() const { return money_; }
    size_t getSpeed() const { return ship_->getSpeed(); }
    Cargo* getCargo(size_t index) const;

    void setMoney(size_t money) { money_ = money; }
    void payCrew(size_t money) override;

    void loadShip(std::shared_ptr<Cargo> cargo);
    void unloadShip(Cargo* cargo);

private:
    std::unique_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;

    void countAvailableSpace();
};
