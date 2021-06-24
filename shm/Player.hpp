#pragma once
#include <memory>

#include "Ship.hpp"

class Player {
	std::unique_ptr<Ship> ship_;
	int money_;
	int availableSpace_;

public:
	Player():
		ship_(std::make_unique<Ship>()),
		money_(0),
		availableSpace_()
	{}

	int getMoney() const { return money_; }
	int getAvailableSpace() const { return availableSpace_; }
	size_t getSpeed() const { 
		if (ship_) {
			return ship_->getSpeed();
		}
		return 0;
	}
	Cargo* getCargo(size_t index) const {
		if (ship_) {
			return &ship_->getCargo(index);
		}
		return nullptr;
	}
	std::string takeOverShip(std::unique_ptr<Ship> someoneElsesShip) { 
		if (!someoneElsesShip) {
			return "there is no ship";
		}
		if (ship_) {
			return "already have one";
		}
		ship_ = std::move(someoneElsesShip);
		return "yarr";
	}
	std::unique_ptr<Ship> giveAwayShip() { 
		return std::move(ship_); 
	}
};