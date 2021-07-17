#include "Player.hpp"
#include <numeric>

Player::Player(std::unique_ptr<Ship>& ship, int money, int availableSpace)
    : ship_(std::move(ship)), money_(money), availableSpace_(calculateAvailableSpace()) {}

std::shared_ptr<Cargo> Player::getCargo(size_t index) const {
    return ship_->getCargo(index);
}

size_t Player::calculateAvailableSpace() {
    int cargoAmount = 0;
    int capacity = ship_->getCapacity();
    std::vector<std::shared_ptr<Cargo>> cargoList = ship_->getCargoList();

    std::accumulate(cargoList.begin(), cargoList.end(),0);

    if (capacity - cargoAmount < 0) {
        return 0;
    }

    return capacity - cargoAmount;
}