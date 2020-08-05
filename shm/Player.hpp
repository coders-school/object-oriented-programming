#pragma once

#include <memory>

#include "Cargo.hpp"
#include "Delegate.hpp"
#include "Ship.hpp"

class Player : public Delegate {
private:
    std::shared_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;

    size_t countAvailableSpace();

public:
    Player(std::shared_ptr<Ship>& ship, size_t money);

    size_t getMoney() const { return money_; };
    size_t getAvailableSpace() const { return availableSpace_; };
    size_t getSpeed() const { return ship_->getSpeed(); };
    
    void purchaseCargo(const CargoPtr& cargo, size_t amount, size_t price);
    void sellCargo(const CargoPtr& cargo, size_t amount, size_t price);

    //override from Delegate
    void payCrew(size_t money) override;
};
