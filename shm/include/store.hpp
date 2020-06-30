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

class Store {
    Store();
    Cargo* GetCargo(const size_t pos);
    Response buy(Cargo* cargo, size_t amount, Player* player);
    Response sell(Cargo* cargo, size_t amount, Player* player);
    void nextDay() override;

private:
    void GenerateCargo();
    Cargo* FindMatchCargo(Cargo* cargo);
    std::vector<cargoPtr> cargo_;
    Time* time_;
};
