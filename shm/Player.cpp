#include "Player.hpp"

Player::Player(std::unique_ptr<Ship> &ship, int money, int availableSpace)
    : ship_(std::move(ship)), money_(money), availableSpace_(calculateAvailableSpace())
{}

std::unique_ptr<Ship> &Player::getShip()
{
    return ship_;
}

int Player::getMoney()
{
    return money_;
}

size_t Player::getAvailableSpace()
{
    return availableSpace_;
}

size_t Player::getSpeed() const
{
    return ship_->getSpeed();
}

Cargo *Player::getCargo(size_t index) const
{
    return ship_->getCargo()[index];
}

size_t Player::calculateAvailableSpace()
{
    int cargoAmount = 0;
    int capacity = ship_->getCapacity();
    std::vector<Cargo *> shipCargo = ship_->getCargo();
    
    for (int i = 0; i < shipCargo.size(); i++)
    {
        cargoAmount += getCargo(i)->getAmount();
    }

    if (capacity - cargoAmount < 0)
    {
        return 0;
    }

    return capacity - cargoAmount;
}