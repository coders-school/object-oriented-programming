#pragma once
#include <memory>
#include <numeric>

#include "ship.hpp"

class Player {
public:
    Player(std::shared_ptr<Ship> ship, size_t money, size_t availableSpace);

    std::shared_ptr<Ship> getShip() const { return ship_; }
    size_t getMoeny() const { return money_; }
    size_t getAvailableSpeed() const { return availableSpace_; }
    size_t getSpeed() const { return ship_->getSpeed(); }
    Cargo* getCargo(size_t index) const { return ship_->getCargo()[index]; }

    void setShip(const std::shared_ptr<Ship>& ship);
    void addMoney(const size_t& money);
    void setAvailableSpace(const size_t& space);

private:
    std::shared_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;

    size_t countSpace() {
        size_t totalAmount = std::accumulate(ship_->getCargo().begin(), ship_->getCargo().end(), 0,
                                             [](const Cargo& item1, const Cargo& item2) {
                                                 return item1.getAmmount() + item2.getAmmount();
                                             });

        return ship_->getCapacity() - totalAmount;
    }
};
