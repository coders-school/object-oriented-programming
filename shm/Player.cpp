#include "Player.hpp"

Player::Player(std::unique_ptr<Ship> ship, size_t money, size_t space) : money_(money), availableSpace_(space)
{
    ship_ = std::move(ship);
};

void Player::updateAvailableSpace()
{
    size_t loadTotal = 0;
    for (const auto cargo : ship_->getCargos())
    {
        loadTotal += cargo->getAmount();
    }
    availableSpace_ = ship_->getCapacity() - loadTotal;
}


