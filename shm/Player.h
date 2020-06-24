#pragma once
#include <memory>
#include "Cargo.hpp"
#include "Ship.hpp"

public class Player {
public:
	Player(size_t money, Ship ship, size_t space)
	~Player() = default;

	size_t getAvailableSpace() const;
	size_t getMoney() const;
	Ship* getShip() const;
	size_t getSpeed() const;
	Cargo* getCargo(size_t index) const;

private:
	std::unique_ptr<Ship> ship_;
	size_t money_;
	size_t available_space_;
};