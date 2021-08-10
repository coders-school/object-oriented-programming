#include <numeric>
#include <iostream>
#include "cargo.hpp"
#include "player.hpp"
#include "ship.hpp"

Player::Player(std::unique_ptr<Ship> ship, int money, int availableSpace) : Storable(money, availableSpace)
{
    ship_ = std::move(ship);
    ship_.get()->setOwner(this);

}

Player::~Player() {}

const std::unique_ptr<Ship> &Player::getShip()
{
    return ship_;
}

size_t Player::getSpeed() const
{
    if (ship_->getSpeed() > 0)
    {
        return ship_->getSpeed();
    }
    return 0;
}

Cargo * Player::getCargo(size_t index) const
{
    if (ship_->getCargo().at(index) >= 0)
    {
        return ship_->getCargo().at(index);
    }
    return nullptr;
}

size_t Player::calculateAvailableSpace()
{
    int cargoAmount = 0;
    int capacity = ship_->getCapacity();
    std::vector<Cargo*>  shipCargo = ship_->getCargo();

    cargoAmount = std::accumulate(shipCargo.begin(), shipCargo.end(), 0, [](int i, Cargo * c)
                                  { return i += c->getAmount(); });

    if (capacity - cargoAmount < 0)
    {
        return 0;
    }
    return capacity - cargoAmount;
}

void Player::setCrew(size_t newCrewSize)
{
    ship_.get()->setCrew(newCrewSize);
}
