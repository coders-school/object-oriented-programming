#pragma once

#include <memory>

class Ship;
class Cargo;

class Player {
	Ship* ship_;
	size_t money_;
	size_t maxAvailableSpace_;
	std::pair<size_t, bool> availableSpace_;

public:
	Player();

	size_t getMoney() const;

	size_t getAvailableSpace();

	size_t getSpeed() const;

	Cargo* getCargo(size_t index) const;

	// void PayCrew(size_t money) override;

	//void PurchaseCargo(std::unique_ptr<Cargo> cargo, size_t price);

	//void SellCargo(Cargo* cargo, size_t price);

	//void PrintCargo() const;

private:
	void calculateAvailableSpace();
};
