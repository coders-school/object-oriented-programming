#include "Player.hpp"
#include "ShmExceptions.hpp"

void Player::Player::PayCrew(size_t money)
{
    if (money_ >= money)
    {
        money_ = money_ - money;
    }
    else
    {
        throw AmountException("Not enough money!");
    }
}

Player::Player(std::unique_ptr<Ship> ship, size_t money, size_t space) : money_(money), availableSpace_(space)
{
    ship_ = std::move(ship);
    ship_->addDelegate(this);
};

void Player::updateAvailableSpace()
{
    size_t loadTotal = 0;
    for (const auto cargo : ship_->getCargos())
    {
        loadTotal += cargo->GetAmount();
    }
    availableSpace_ = ship_->getCapacity() - loadTotal;
}

void Player::earnMoney(size_t amount)
{
    money_ += amount;
}

void Player::spendMoney(size_t amount)
{
    if (amount > money_)
    {
        throw AmountException("Not enough money");
    }
    else
    {
        money_ -= amount;
    }
}

Ship* Player::getShip() const
{
    return ship_.get();
}

std::vector<std::shared_ptr<Cargo>> Player::getCargos() const
{
    return ship_->getCargos();
}
