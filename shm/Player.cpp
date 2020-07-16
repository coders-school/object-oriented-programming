#include "Player.hpp"

#include <iterator>
#include <numeric>
#include <utility>

Player::Player(std::unique_ptr<Ship> ship, size_t money) {
    ship_ = std::move(ship);
    money_ = money;
    availableSpace_ = getAvailableSpace();
}

size_t Player::getMoney() const {
    return money_;
}
int Player::getSpeed() const {
    return ship_->getSpeed();
}
Cargo* Player::getCargo(size_t index) const {
    return ship_->getCargo(index);
}
std::vector<std::shared_ptr<Cargo>> Player::getCargos() const {
    return ship_->getCargos();
}
size_t Player::getAvailableSpace() {
        auto cargos = ship_->getCargos();
        const size_t startingSumValue{0};
        auto sumOfCargoAmount = std::accumulate(std::begin(cargos),
                                                std::end(cargos),
                                                startingSumValue,
                                                [](size_t sum, const auto& element) {
                                                    return sum + element->getAmount();
                                                });
    return ship_->getCapacity() - sumOfCargoAmount;
}
