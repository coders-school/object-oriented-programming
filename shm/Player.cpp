#include "Player.hpp"
#include <iostream>
#include <numeric>

Player::Player(std::unique_ptr<Ship>& ship, int money)
    : ship_(std::move(ship)), money_(money) {
    calculateAvailableSpace();
}

std::shared_ptr<Cargo> Player::getCargo(size_t index) const {
    return ship_->getCargo(index);
}

void Player::calculateAvailableSpace() {
    size_t cargoAmount = 0;
    size_t capacity = ship_->getCapacity();
    std::vector<std::shared_ptr<Cargo>> cargoList = ship_->getCargoList();

    cargoAmount = std::accumulate(cargoList.begin(),
                                  cargoList.end(),
                                  0,
                                  [](int amount, std::shared_ptr<Cargo> cargo) { return amount += cargo->getAmount(); });

    if (capacity - cargoAmount < 0) {
        availableSpace_ = 0;
    }

    availableSpace_ = capacity - cargoAmount;
}

void Player::printCargo() const {
    if (!ship_) {
        return;
    }
    std::cout << "\n"
              << ship_->getName() << "\n";
    std::cout << "Ship capacity: " << ship_->getCapacity() << "\n"
              << "Available space: " << availableSpace_ << "\n" << "\n"
              << "Goods in the cargo room: " << "\n";
    auto cargoList = ship_->getCargoList();
    if (cargoList.empty()) {
        std::cout << "\n"
                  << "( Cargo room is empty )"
                  << "\n";
    } else {
        size_t i{1};
        for (const auto& cargo : cargoList) {
            std::cout << i++ << ". Name: " << cargo->getName()
                      << ", Amount: " << cargo->getAmount()
                      << ", Base price: " << cargo->getBasePrice()
                      << '\n';
        }
    }

    std::cout << "\n";
}

void Player::PurchaseCargo(std::shared_ptr<Cargo> cargo, size_t price) {
    ship_->load(cargo);
    money_ -= price;
    calculateAvailableSpace();
}

void Player::SellCargo(std::shared_ptr<Cargo> cargo, size_t price) {
    ship_->unload(cargo);
    money_ += price;
    calculateAvailableSpace();
};