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

class Store : public Cargo {
    Store();
    cargoPtr GetCargo(const size_t pos);
    Response buy(cargoPtr cargo, size_t amount, Player* player);
    Response sell(cargoPtr cargo, size_t amount, Player* player);
    void nextDay() override;

private:
    void GenerateCargo();
    cargoPtr FindMatchCargo(cargoPtr cargo);
    std::vector<cargoPtr> cargo_;
    Time* time_;
};
