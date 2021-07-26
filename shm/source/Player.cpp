#include "Player.hpp"
#include "Ship.hpp"
#include "Cargo.hpp"

#include <numeric>
#include <memory>

Player::Player():
	ship_(nullptr),
	money_(0),
	availableSpace_({0, false})
{}

size_t Player::getMoney() const { 
	return money_; 
}

size_t Player::getAvailableSpace() { 
	if (!availableSpace_.second) {
		calculateAvailableSpace();
	}
	return availableSpace_.first;
}

size_t Player::getSpeed() const { 
	if (ship_) {
		return ship_->getSpeed();
	}
	return 0;
}

Cargo* Player::getCargo(size_t index) const {
	if (ship_) {
		return ship_->getCargo(index);
	}
	return nullptr;
}

void Player::payCrew(size_t price) {
	money_ = (money_ > price)? money_ - price : 0;
}

// void Player::PurchaseCargo(std::unique_ptr<Cargo> cargo, size_t price);

// void Player::SellCargo(Cargo* cargo, size_t price);

// void Player::PrintCargo() const;

void Player::calculateAvailableSpace() {
	if (!ship_) {
		return;
	} 
	const auto& allCargo = ship_->getCargo();
	size_t count = std::accumulate(allCargo.begin(), allCargo.end(), 0, [](int sum, const auto& cargo) { return sum + cargo->getAmount(); }); 
	availableSpace_.first = ship_->getCapacity() - count;
	availableSpace_.second = true;
}
