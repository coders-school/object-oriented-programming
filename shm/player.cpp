#include <numeric>
#include <iostream>
#include "cargo.hpp"
#include "player.hpp"
#include "ship.hpp"

Player::Player(std::unique_ptr<Ship> ship, int money, int availableSpace) : Storable(money, availableSpace) {
    ship_ = std::move(ship);
}

const std::unique_ptr<Ship>& Player::getShip() { 
    return ship_; 
}

size_t Player::getSpeed() const {
    if(ship_->getSpeed() > 0)
    {
        return ship_->getSpeed(); 
    }
    
    std::cout << "Something went wrong, we set your speed at 0" << '\n';
    return 0; // TODO add something better
}

std::shared_ptr<Cargo> Player::getCargo(size_t index) const {
    if(ship_->getCargo().at(index) > 0)
    {
        return ship_->getCargo().at(index);
    }
    std::cout << "Something went wrong and you lost your cargo" << '\n';
    return nullptr; // TODO add something better
}


size_t Player::calculateAvailableSpace() {

    int cargoAmount = 0;
    int capacity = ship_->getCapacity();
    std::vector<std::shared_ptr<Cargo>> shipCargo = ship_->getCargo();
     
    cargoAmount = std::accumulate(shipCargo.begin(), shipCargo.end(), 0, [](int i, std::shared_ptr<Cargo> c) { return i += c->getAmount(); });
    std::cout << "Cargo amount(po obliczeniach): "<< capacity - cargoAmount << '\n';
   
    if(capacity - cargoAmount < 0){
        std::cout << "something went wrong and you have lost your cargo" << '\n';
        return 0;
    }
    return capacity - cargoAmount;
}

void Player::load(std::shared_ptr<Cargo> loadCargo, size_t amount)
{
    std::cout << "wywołuje sie? " << '\n';
}
void Player::unload(std::shared_ptr<Cargo> unloadCargo, size_t amount)
{

}
