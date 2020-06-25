#pragma once

#include <memory>
#include <vector>

#include "cargo.hpp"
#include "player.hpp"

enum class Response {
    done,
    lack_of_money,
    lack_of_cargo,
    lack_of_space
};

class Store : public CargoHolder {
public:
    Store();
    ~Store();

    /* Store.buys amount of cargo from a player */
    Response buy(Cargo* cargo, size_t amount, Player* player);
    /* Store.sells amount of cargo to a player */
    Response sell(Cargo* cargo, size_t amount, Player* player);

    /* override from CargoHolder */
    void receiveCargo(Cargo* cargo, size_t amount, CargoHolder* cargoHolder) override;
    void clearEmptyCargos() override;

    void nextDay();

private:
    std::vector<std::shared_ptr<Cargo>> cargo_;
};
