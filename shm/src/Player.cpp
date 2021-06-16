#include "../inc/Player.hpp"

Player::Player(std::shared_ptr<Ship>& ptrShip, size_t money, size_t availableSpace)
    : ptrShip_(std::move(ptrShip)), money_(money), availableSpace_(availableSpace)
{}

//Foo f (std::make_shared<Stuff>());

size_t Player::getSpeed() const {
    //auto ptrShip_ = std::make_shared<Ship>(ship);
    return ptrShip_->getSpeed();
};
Cargo* getCargo(size_t index) const {

}
