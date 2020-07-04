#pragma once

#include "cargo.hpp"
#include "item.hpp"
#include "player.hpp"
#include "timeSHM.hpp"

enum class Response {
    done,
    lack_of_money,
    lack_of_cargo, 
    lack_of_space
};

class Store {
public:
    Store(Time* gameTime);
    Response buy(Cargo* cargo, size_t amount, Player* player);
    Response sell(Cargo* cargo, size_t amount, Player* player);

private:
    Time* timeTracker_;
    std::vector<Item> cargoToSell_;
    std::vector<Item> cargoSold_;
};
