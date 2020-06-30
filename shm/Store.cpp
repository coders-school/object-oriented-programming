#include "Store.hpp"

Response Store::buy(Cargo* cargo, size_t amount, Player* player){
    const size_t price = amount * cargo->getBasePrice();
    if (cargo -> getAmount() < amount){
        return Response::lack_of_cargo;
    }
    if (player -> getMoney() < price){
        return Response::lack_of_money;
    }
    if (player -> getAvaliableSpace() < amount){
        return Response::lack_of_space;
    }
    player->buyCargo(cargo, amount, price);
    return Response::done;
}

Response Store::sell(Cargo* cargo, size_t amount, Player* player){
    const size_t price = amount * cargo->getPrice();
    player->sellCargo(cargo, amount, price);
    return Response::done;
}

