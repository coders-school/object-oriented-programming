#pragma once

#include "cargo.hpp"
#include "player.hpp"

enum class Response {
    done,
    lack_of_money,
    lack_of_cargo,
    lack_of_space
};

class Store {
    Store();
    Response buy(Cargo* cargo, size_t amount, Player* player);
    Response sell(Cargo* cargo, size_t amount, Player* player);
    // dopisać składowe - towar jaki sklep przetrzymuje i obsługa nextday ;)
};