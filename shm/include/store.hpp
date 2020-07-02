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

class Store : public Cargo,
              public Observer {
    Store();
    cargoPtr GetCargo(const size_t pos);
    Response buy(cargoPtr cargo, size_t amount, Player* player);
    Response sell(cargoPtr cargo, size_t amount, Player* player);
    void nextDay() override;

    //friend std::ostream& operator<<(std::ostream& out, const Store& store);

private:
    void GenerateCargo();
    size_t GenerateRandom(size_t range);
    cargoPtr FindMatchCargo(cargoPtr cargo);
    void RemoveFromStore(cargoPtr cargo);
    std::array<std::string, 3> fruitsNames{"apple", "raspberry", "lemon"};
    std::array<std::string, 3> alcoNames{"vodka", "whiskey", "beer"};
    std::array<std::string, 3> itemNames{"tools", "wood", "material"};

    std::vector<cargoPtr> cargo_;
    Time* time_;
};
