#include "Player.hpp"

void Player::updateAvailableSpace()
{
    size_t loadTotal = 0;
    for (const auto cargo : ship_->getCargos())
    {
        loadTotal += cargo->GetAmount();
    }
    availableSpace_ = ship_->getCapacity() - loadTotal;
}

[[nodiscard]] size_t Player::getMoney() const
{
    return money_;
}
[[nodiscard]] size_t Player::getSpeed() const
{
    return ship_->getSpeed();
}
Cargo* Player::getCargo(size_t index) const
{
    return ship_->getCargo(index);
};

void Player::setMoney(size_t amount)
{
    money_ = amount;
}

size_t Player::getAvailableSpace() const
{
    return availableSpace_;
}
