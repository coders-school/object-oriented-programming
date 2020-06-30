#pragma once

#include "cargo.hpp"
#include "player.hpp"
#include "time.hpp"

enum class Response {
    done,
    lack_of_money,
    lack_of_cargo,
    lack_of_space
};

class Store : Observer{
    Store();
    Response buy(cargoPtr cargo, size_t amount, Player* player);
    Response sell(cargoPtr cargo, size_t amount, Player* player);
    void nextDay() override;
    std::vector<cargoPtr> cargo_;

    // dopisać składowe - towar jaki sklep przetrzymuje i obsługa nextday ;)
};
