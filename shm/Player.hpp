#pragma once

#include <memory>

#include "Cargo.hpp"
#include "Ship.hpp"
#include "IDelegate.hpp"

class Player : public IDelegate
{
public:
    Player(std::unique_ptr<Ship> ship, size_t money, size_t space);

    [[nodiscard]] size_t getMoney() const { return money_; }
    [[nodiscard]] size_t getSpeed() const { return ship_->getSpeed(); }
    [[nodiscard]] std::shared_ptr<Cargo> getCargo(size_t index) const { return ship_->getCargo(index); };
    [[nodiscard]] std::vector<std::shared_ptr<Cargo>> getCargos() const;
    [[nodiscard]] size_t getAvailableSpace() const { return availableSpace_; }
    void setMoney(size_t amount) { money_ = amount; }
    void spendMoney(size_t amount);

    void earnMoney(size_t amount);
    void PayCrew(size_t amount) override;

    [[nodiscard]] Ship* getShip() const;

private:
    std::unique_ptr<Ship> ship_;

    size_t money_;

    size_t availableSpace_;
    void updateAvailableSpace();
};
