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

class Store : public Observer {
    Store();
    cargoPtr GetCargo(const size_t pos);
    std::vector<cargoPtr> getCargoContainer() const {return cargo_;}
    Response buy(cargoPtr cargo, size_t amount, Player* player);
    Response sell(cargoPtr cargo, size_t amount, Player* player);
    void nextDay() override;

    friend std::ostream& operator<<(std::ostream& out, const Store& store);

private:
    void GenerateCargo();
    size_t GenerateRandom(size_t minValue, size_t maxValue);
    cargoPtr FindMatchCargo(cargoPtr cargo);
    void RemoveFromStore(cargoPtr cargo);
    std::array<std::string, 3> fruitsNames{"apple", "raspberry", "lemon"};
    std::array<std::string, 3> alcoNames{"vodka", "whiskey", "beer"};
    std::array<std::string, 3> itemNames{"tools", "wood", "material"};
    void GenerateFruits();
    void GenerateAlco();
    void GenerateItems();

    std::vector<cargoPtr> cargo_;
    Time* time_;
};
