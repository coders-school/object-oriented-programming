#pragma once

#include <memory>
#include "Ship.hpp"

class Player
{
public:
    Player(Ship ship, size_t money, size_t space) : money_(money), availableSpace_(space)
    {
        ship_ = std::make_unique<Ship>(std::move(ship));
    };

    [[nodiscard]] size_t getMoney() const { return money_; }
    [[nodiscard]] size_t getAvailableSpace() const { return availableSpace_; }
    [[nodiscard]] size_t getSpeed() const { return ship_->getSpeed(); }
    [[nodiscard]] Cargo* getCargo(size_t index) const { return ship_->getCargo(index); };

    void setMoney(size_t amount) { money_ = amount; }
    void setAvailableSpace(size_t space) { availableSpace_ = space; }

private:
    std::unique_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;
};
