#include "Player.hpp"

#include <numeric>

constexpr size_t SHIP_ID = 444;
constexpr char SHIP_NAME[] = "SUNNY";
constexpr size_t SHIP_SPEED = 26;
constexpr size_t SHIP_MAX_CREW = 78;
constexpr size_t SHIP_CAPACITY = 102;
constexpr size_t SPACE = 100;

Player::Player(Ship ship, size_t money)
    : _ship(std::make_unique<Ship>(ship)),
      _money(money),
      _availableSpace(SPACE) {
}

Player::Player(size_t money /*, Time* time*/)
    : _ship(std::make_unique<Ship>(SHIP_ID, SHIP_NAME, SHIP_SPEED, SHIP_MAX_CREW, SHIP_CAPACITY, this)),
      _money(money),
      _availableSpace(SPACE) {
}

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

void Player::showCargo() const {
    _ship->showCargo();
}

void Player::payCrew(size_t money) {
    if (money > _money)
        money = SIZE_MAX;
    else
        _money -= money;
}
