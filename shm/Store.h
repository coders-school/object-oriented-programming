#pragma once

#include <memory>
#include <vector>

#include "Alcohol.h"
#include "Cargo.h"
#include "Fruit.h"
#include "Item.h"
#include "Observer.h"
#include "Player.h"
#include "Time.h"

enum class Response {
    done,
    lack_of_money,
    lack_of_cargo,
    lack_of_space
};

int min_cargo_amount = 0;
int max_cargo_amount = 100;

int min_price = 0;
int max_price = 100;

std::vector<ItemData> available_items = {
    {"Excalibur", Rarity::legendary},
    {"Pistol", Rarity::rare},
    {"Barrel", Rarity::common},
    {"Wooden Chest", Rarity::common},
    {"Canon", Rarity::epic},
    {"Eyepatch", Rarity::common},
};

std::vector<AlcoholData> available_alcohols = {
    {"Pure alcohol", 96},
    {"Rum", 30},
    {"Ale", 8},
    {"Beer", 3},
};

std::vector<FruitData> available_fruits = {
    {"Banana", 10},
    {"Apple", 5},
    {"Watermelon", 3},
};

class Store : public Observer {
    friend std::ostream& operator<<(std::ostream& out, const Store& store);

public:
    Store(Time* time);
    ~Store() override;

    Response buy(Cargo* cargo, size_t amount, Player* player);
    Response sell(Cargo* cargo, size_t amount, Player* player);
    void nextDay();
    void update() override;

private:
    void generateCargos();
    std::vector<std::shared_ptr<Cargo>> available_cargos_;
    std::string getDescription() const;
    Time* time_;
};
