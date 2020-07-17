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
        if(space>cargo->getAmount())
        {
            space -= cargo->getAmount();
        }
        else 
        {
            availableSpace_=0;
            return;
        }
    }
    availableSpace_ = space;
}
int Player::getMoney() const { return money_; }
int Player::getAvalibleSpace() const {return availableSpace_;}
size_t Player::getSpeed() const { return ship_->getSpeed(); }
Cargo* Player::getCargo(size_t index) const { return ship_->getCargo(index); };
