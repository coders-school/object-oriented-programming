#include "player.hpp"
#include <iostream>
#include <numeric>
#include <utility>

#include "cargo.hpp"
#include "ship.hpp"

Player::Player(std::shared_ptr<Ship> ship, const size_t &money)
    : ship_(std::move(ship)), money_(money), playerCoordinates_(Coordinates(static_cast<size_t>(25), static_cast<size_t>(75)))
{
    countAvailableSpace();
}

size_t Player::getMoney() const
{
    return money_;
}
size_t Player::getAvailableSpace() const
{
    return availableSpace_;
}
std::shared_ptr<Ship> Player::getShip() const
{
    return ship_;
}

size_t Player::getSpeed() const
{
    return ship_->getSpeed();
}
std::shared_ptr<Cargo> Player::getCargo(size_t index) const
{
    return ship_->getCargo(index);
}

void Player::countAvailableSpace()
{
    if (!ship_)
    {
        return;
    };

    auto vectorOfCargos = ship_->getCargosVector();
    auto sum = std::accumulate(vectorOfCargos.begin(),
                               vectorOfCargos.end(),
                               0,
                               [](size_t amount, const auto &cargo)
                               { return amount += cargo->getAmount(); });

    const auto &cargoVector = ship_->getCapacity();

    availableSpace_ = cargoVector - sum;
}

void Player::printCargo() const
{
    std::cout << "Ship name: " << ship_->getName() << '\n'
              << "Ship capacity: " << ship_->getCapacity() << '\n'
              << "Available space: " << availableSpace_ << '\n'
              << '\n';
    int i = 0;
    std::cout << "Current ship's cargo\n";
    if (ship_->getCargosVector().empty()) {
        std::cout << "We have nothing captain! NOTHING!\n";
        return;
    }
    for (const auto &el : ship_->getCargosVector())
    {
        std::cout << ++i << " Name: " << el->getName() << ",\t\t Amount: " << el->getAmount() << ",\t\t Base price: " << el->getBasePrice() << ",\t\t Actual price: " << el->getPrice() << '\n';
    }
}

void Player::sell(std::shared_ptr<Cargo> cargo, const size_t &amount)
{
    if (!cargo)
    {
        return;
    }
    ship_->unload(cargo, amount);
    money_ += cargo->getPrice() * amount;
}

void Player::buy(std::shared_ptr<Cargo> cargo, const size_t &amount)
{
    if (!cargo)
    {
        return;
    }
    getShip()->load(cargo, amount);

    money_ -= cargo->getPrice() * amount;
}

void Player::setMoney(size_t money)
{
    money_ = money;
}

Coordinates Player::getPlayerPosition() const
{
    return playerCoordinates_;
}

void Player::setPlayerPosition(const size_t &X, const size_t &Y)
{
    playerCoordinates_.setPositionX(X);
    playerCoordinates_.setPositionY(Y);
}