#include "shm/inc/Store.hpp"

#include <random>

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

void Store::nextDay() {
    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<size_t> distribution{
        MIN_CARGO_IN_STORE, MAX_CARGO_IN_STORE
    };

    for (const auto& cargo : cargo_) {
        cargo->setAmount(distribution(generator));
    }
}

Store::Response Store::sell(Cargo* cargo, size_t amount, Player* player) {
    if (cargo->getAmount() + amount > MAX_CARGO_IN_STORE) {
        return Response::lack_of_space;
    }
    return Response::done;
}
