#pragma once

#include <memory>

#include "Delegate.hpp"

class Ship;
class Cargo;

class Player : Delegate {
	Ship* ship_;
	size_t money_;
	std::pair<size_t, bool> availableSpace_;

public:
	Player();

	size_t getMoney() const;

	size_t getAvailableSpace();

	size_t getSpeed() const;

	Cargo* getCargo(size_t index) const;

	void payCrew(size_t price) override;

	// void PurchaseCargo(std::unique_ptr<Cargo> cargo, size_t price);

	// void SellCargo(Cargo* cargo, size_t price);

	// void PrintCargo() const;

private:
	void calculateAvailableSpace();
};
