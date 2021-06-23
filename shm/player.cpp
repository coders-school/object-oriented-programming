#include "player.hpp"

    Player::Player(std::shared_ptr<Ship> ship, uint16_t money, uint8_t availableSpace) 
        : ship_(ship)
        , money_(money)
        , availableSpace_(availableSpace)
        {}

    Player::~Player() {};

    
    uint16_t Player::getMoney() const               { return money_ ;}
    uint16_t Player::getAvailableSpace() const      { return availableSpace_;}
    std::shared_ptr<Ship>Player::getShip() const    { return ship_ ;};
