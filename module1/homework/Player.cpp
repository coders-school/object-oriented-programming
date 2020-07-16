#include "Player.hpp"

Player::Player(std::shared_ptr<Ship> ship,int money,size_t space):money_(money),availableSpace_(space)
{
    ship_=ship;
};

void Player::updateAvailableSpace()
{
    size_t space=ship_->getCapacity();
    for (const auto cargo : ship_->getCargos())
    {
        space -= cargo->getAmount();
    }
    availableSpace_ = space;
}
