#include "Player.hpp"

#include <numeric>

Player::Player(std::unique_ptr<Ship>& ship, size_t money) {
    ship_ = std::move(ship); //it might be good to let the Player class to construct Ship for itself
    ship_->setDelegate(this);
    money_ = money;
    avaliableSpace_ = countAvailableSpace();
};

size_t Player::countAvailableSpace() {
    auto occupiedSpace = std::accumulate(begin(ship_->getAllCargos()),
                                         end(ship_->getAllCargos()),
                                         0,
                                         [](const Cargo& cargoFirst, const Cargo& cargoSecond) {
                                             return cargoFirst.getAmount() + cargoSecond.getAmount();
                                         });

    if (ship_->getCapacity() <= occupiedSpace) {
        return 0;
    }
    return ship_->getCapacity() - occupiedSpace;
}
