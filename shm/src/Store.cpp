#include "shm/inc/Store.hpp"

#include "shm/inc/Cargo.hpp"
#include "shm/inc/Player.hpp"

Store::Response Store::buy(Cargo* cargo, size_t amount, Player* player) {
    if (amount * cargo->getPrice() > player->getMoney()){
        return Response::lack_of_money;
    }
    if (cargo->getAmount() < amount) {
        return Response::lack_of_cargo;
    }
    if (player->getAvailableSpace() < amount) {
        return Response::lack_of_space;
    }
    return Response::done;   
}

Store::Response Store::sell(Cargo* cargo, size_t amount, Player* player) {
    if (cargo->getAmount() + amount > Store::STORE_CAPACITY) {
        return Response::lack_of_space;
    }
    return Response::done;
}

void Store::nextDay() {
    // TODO:
}
