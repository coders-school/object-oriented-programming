#include "player.hpp"

#include <numeric>

constexpr size_t START_MONEY = 1000;
constexpr size_t START_SPACE = 0;

Player::Player(std::unique_ptr<Ship> ship, size_t money, size_t space)
    : ship_(std::move(ship)), money_(money), availableSpace_(space) {}

Player::Player(std::unique_ptr<Ship> ship)
    : Player(std::move(ship), START_MONEY, START_SPACE) {}

size_t Player::getSpeed() const{
    if (ship_) {
        return ship_->getSpeed();
    }
    return 0;
}

Cargo* Player::getCargo(size_t cargo) const{
    if (ship_) {
        return ship_->getCargo(cargo);
    }
    return nullptr;
}
size_t Player::countAvailableSpace() {
     return ship_->countAvailableSpace(); 
}

size_t countFreeSpace() { 
    size_t loadedSpace = std::accumulate(ship->getAllCargo.begin(), ship->getAllCargo.end(), 0);
    return ship->getCapacity() - loadedSpace;
}
