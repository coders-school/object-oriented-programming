#include "Store.hpp"

Store::Response Store::Buy(Cargo* cargo, size_t amount, Player* player) {
    if (amount > cargo->getAmount()) {
        return Response::lack_of_cargo;
    }
    if (amount > player->getAvailableSpace()) {
        return Response::lack_of_space;
    }
    const size_t price = amount * cargo->getBasePrice();

    if (price > player->getMoney()) {
        return Response::lack_of_money;
    }
    return Response::done;
};

Store::Response Store::Sell(Cargo* cargo, size_t amount, Player* player) {
    return Response::done;
};
