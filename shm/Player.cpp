#include "Player.hpp"

#include <numeric>

Player::Player(Ship ship, size_t money)
    : _ship(std::make_unique<Ship>(ship)),
      _money(money) {}

size_t Player::getSpeed() const {
    return _ship->getSpeed();
}

Cargo* Player::getCargo(size_t index) const {
    return _ship->getCargo(index).get();
}

void Player::updateAvailableSpace() {
    size_t cargoSize = std::accumulate(_ship->getCargos().begin(),
                                       _ship->getCargos().end(),
                                       0,
                                       [](size_t sum, auto item) {
                                           return sum + item->getAmount();
                                       });

    _availableSpace = _ship->getCapacity() - cargoSize;
}
