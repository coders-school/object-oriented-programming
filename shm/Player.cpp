#include "Player.hpp"

#include <numeric>

Player::Player(std::unique_ptr<Ship> ship, size_t money) {
    ship_ = std::move(ship);
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

void Player::buyCargo(Cargo* cargo, size_t amount, size_t price) {
    ship_->load(cargo);
    money_ = money_ - price;
    avaliableSpace_ = avaliableSpace_ - amount;
}
void Player::sellCargo(Cargo* cargo, size_t amount, size_t price) {
    ship_->unload(cargo);
    oney_ = money_ + price;
    avaliableSpace_ = avaliableSpace_ + amount;
}
