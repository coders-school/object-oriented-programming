#pragma once

#include "cargo.hpp"
#include "player.hpp"
#include "time.hpp"

#include <memory>

enum class Response {
    done,
    lack_of_money,
    lack_of_cargo,
    lack_of_space
};

class Store : public Observer {
public:
    Store(std::shared_ptr<Time> time);
    ~Store();
    cargoPtr GetCargo(const size_t pos);
    std::vector<cargoPtr> getCargoContainer() const { return cargo_; }
    Response buy(cargoPtr cargo, size_t amount, std::unique_ptr<Player>& player);
    Response sell(cargoPtr cargo, size_t amount, std::unique_ptr<Player>& player);
    void nextDay() override;

    friend std::ostream& operator<<(std::ostream& out, const Store& store);

private:
    void GenerateCargo();
    size_t GenerateRandom(size_t minValue, size_t maxValue);
    cargoPtr FindMatchCargo(cargoPtr cargo);
    void RemoveFromStore(cargoPtr cargo);
    const std::array<std::string, 3> fruitsNames{"apple", "raspberry", "lemon"};
    const std::array<std::string, 3> alcoNames{"vodka", "whiskey", "beer"};
    const std::array<std::string, 3> itemNames{"tools", "wood", "material"};
    void GenerateFruits();
    void GenerateAlco();
    void GenerateItems();

    std::vector<cargoPtr> cargo_;
    std::shared_ptr<Time> time_;
};
