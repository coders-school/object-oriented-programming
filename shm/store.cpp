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

size_t Store::nextDay(std::vector<std::shared_ptr<Cargo>> cargosInStore) {
    std::shared_ptr<Cargo> ptrCargo;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(-10, 10);
    std::uniform_int_distribution<> distr1(0, 1);
    if(distr1(gen) == 0) {
        for(int i = 0; i < distr(gen); i++) {
            cargosInStore.push_back(ptrCargo);
        }
    } else {
        for(int i = 0; i < distr(gen); i++) {
            cargosInStore.pop_back();
        }
    }
}
