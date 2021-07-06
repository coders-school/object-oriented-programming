#include "shm/inc/Store.hpp"

#include <iomanip>
#include <random>

#include "shm/inc/Cargo.hpp"
#include "shm/inc/Player.hpp"

std::ostream& operator<<(std::ostream& out, const Store& store){
    for (size_t i = 0; i < store.cargo_.size(); i++) {
        out << "|" << std::setfill('-') << std::setw (100) << "|\n";
        out << std::setw (10) << "| ID: " << i + 1;
        out << std::setw (30) << " | CARGO NAME: " << store.cargo_[i]->getName();
        out << std::setw (10) << " | AMOUNT: " << store.cargo_[i]->getAmount();
        out << std::setw (10) << " | PRICE: " << store.cargo_[i]->getPrice() << " |\n";
    }
    out << "|" << std::setfill('-') << std::setw (100) << "|\n";
    return out;
}

Store::Response Store::buy(Cargo* cargo, size_t amount, Player* player) {
    if (!cargo) {
        return Response::lack_of_cargo;
    }
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
    if (!cargo) {
        return Response::lack_of_cargo;
    }
    if (cargo->getAmount() + amount > STORE_CAPACITY) {
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

