#include "store.hpp"
#include "cargo.hpp"
#include "player.hpp"
#include "ship.hpp"

//check if present in store
bool Store::checkAvaiablityCargoInStore(std::shared_ptr<Cargo> searchCargo) {
    auto result = find(cargosInStore.begin(), cargosInStore.end(), [&searchCargo](const Cargo& cargo) {
        return cargo.getName() == searchCargo->getName();
    });
    if (result != cargosInStore.end()) {
        return true;
    }
    return false;
}

Store::Response Store::buy(Cargo* cargo, size_t amount, Player* player) {
    std::shared_ptr<Cargo> ptrCargo(cargo);
    if (!checkAvaiablityCargoInStore(ptrCargo)) {
        return Response::lack_of_cargo;  //// ????
    }
    // free space on Player ship_
    //check if add cargo amount is avaiable to add
    size_t getPlayerShipAmount = player->getAvailableSpace();
    size_t addCargoSize = cargo->getAmount() + amount;
    if (getPlayerShipAmount <= addCargoSize) {
        return Response::lack_of_space;
    }

    if ((cargo->getPrice() * amount) > player->getMoney()) {
        return Response::lack_of_money;
    }

    auto ship = player->getShip();
    ship->addAmounntToShipCargo(ptrCargo, amount);
    player->getMoney() - (cargo->getPrice() * amount);
    return Response::done;
}
Store::Response Store::sell(Cargo* cargo, size_t amount, Player* player) {
    std::shared_ptr<Cargo> ptrCargo(cargo);
    auto ship = player->getShip();
    ship->dellAmounntFromShipCargo(ptrCargo,amount);
    player->getMoney() + (cargo->getPrice() * amount);

    return Response::done;  
}
