#pragma once

#include <memory>

#include "Cargo.hpp"
#include "Delegate.hpp"
#include "Ship.hpp"

class Player : public Delegate {
public:
    Player(std::unique_ptr<Ship>& ship, size_t money);

    size_t getMoney() const { return money_; };
    size_t getAvailableSpace() const { return availableSpace_; };
    size_t getSpeed() const { return ship_->getSpeed(); };
    Cargo* getCargo(size_t index) const { return ship_->getCargo(index); };
    void buyCargo(std::shared_ptr<Cargo> cargo, size_t amount, size_t price);
    void sellCargo(std::shared_ptr<Cargo> cargo, size_t amount, size_t price);

    //override from Delegate
    void payCrew(size_t money) override;

private:
    std::unique_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;

    size_t countAvailableSpace();
};
