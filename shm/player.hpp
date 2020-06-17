#pragma once
#include <memory>
#include <iostream>

#include "ship.hpp"
#include "cargo.hpp"

class Player{
private:

std::unique_ptr<Ship> ship_; 
size_t availableSpace_;
size_t money_;

size_t CountAvailableSpace(Ship ship) const;
public:

Player(std::unique_ptr<Ship> ship, size_t money, size_t availableSpace); 


size_t getShip() const;
size_t getMoney() const; 
size_t getAvailableSpace() const;

size_t getSpeed(Ship ship) const;
Cargo* getCargo(Ship ship, size_t index) const;

};
