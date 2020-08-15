#include "Player.hpp"

#include <numeric>
#include <ostream>
#include <string>

Player::Player(std::shared_ptr<Ship>& ship, size_t money) {
    ship_ = ship; /*std::move(ship);*/  //it might be good to let the Player class to construct Ship for itself
    ship_->setDelegate(this);
    money_ = money;
    availableSpace_ = countAvailableSpace();
};

void Player::payCrew(size_t money) {
    if (money > money_) {
        money_ = 0;
    } else {
        money_ -= money;
    }
}

size_t Player::countAvailableSpace() {
    auto occupiedSpace = std::accumulate(begin(ship_->getAllCargos()),
                                         end(ship_->getAllCargos()),
                                         0,
                                         [](int accumulated, const auto& cargo) {
                                             return accumulated + cargo->getAmount();
                                         });

    if (ship_->getCapacity() <= occupiedSpace) {
        return 0;
    }
    return ship_->getCapacity() - occupiedSpace;
}

void Player::purchaseCargo(const CargoPtr& cargo, size_t amount, size_t price) {
    ship_->load(cargo);
    money_ -= price;
    availableSpace_ -= amount;
}

void Player::sellCargo(const CargoPtr& cargo, size_t amount, size_t price) {
    ship_->unload(cargo, amount);
    money_ += price;
    availableSpace_ += amount;
}

std::ostream& operator<<(std::ostream& out, const Player& player) {
    out << "Money = " << player.money_ << "\tSpace = " << player.availableSpace_;
    out << " on ship named " << player.ship_->getName() << "\n";
    out << *(player.ship_);
    return out;
}
