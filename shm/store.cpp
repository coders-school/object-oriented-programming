#include "store.hpp"
#include "cargo.hpp"
#include "player.hpp"
#include "ship.hpp"

bool Store::checkAvaiablityCargoInStore(std::shared_ptr<Cargo> searchCargo) {
    auto result = find(cargosInStore.begin(), cargosInStore.end(), [&searchCargo](const Cargo& cargo){
        return   cargo.getName() == searchCargo->getName(); 
    }); 
    if(result != cargosInStore.end()) {
        return true;
    }
    return false;
}

Store::Response Store::buy(Cargo* cargo, size_t amount, Player* player) {
    
    
    return Response::lack_of_cargo;  //// ????
    
    // free space on Player ship_
    //check if add cargo amount is avaiable to add
    size_t getPlayerShipAmount = player->getAvailableSpace();
    size_t addCargoSize = cargo->getAmount() + amount;  
    if (getPlayerShipAmount <= addCargoSize) {
        return Response::lack_of_space;
    }

    auto ship = player->getShip();
    ship->getCargo();

    
    Response::lack_of_money;
    Response::done;
}
Store::Response Store::sell(Cargo*, size_t amount, Player*) {
    return Response::done;
}

