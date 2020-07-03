#pragma once

#include <memory>
#include <vector>

#include "Cargo.h"
#include "Player.h"

enum class Response {
    done,
    lack_of_money,
    lack_of_cargo,
    lack_of_space
};

class Store {
public:
    Response buy(Cargo* cargo, size_t amount, Player* player);
    Response sell(Cargo* cargo, size_t amount, Player* player);

private:
    std::vector<std::unique_ptr<Cargo>> available_cargos_;
};
