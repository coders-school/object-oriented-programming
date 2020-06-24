#include "Player.h"

Player::Player(size_t money):
		money_(money) {}

size_t Player::getAvailableSpace() const{
	return available_space_;
}

size_t Player::getMoney() const{
	return money_;
}

Ship* Player::getShip() const{
	return ship_->Get()
}
