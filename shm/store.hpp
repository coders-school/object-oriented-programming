#pragma once

#include "cargo.hpp"
#include "item.hpp"
#include "player.hpp"
#include "timeSHM.hpp"

using randomVal = std::uniform_int_distribution<size_t>;

enum class Response { done, lack_of_money, lack_of_cargo, lack_of_space };

class Store {
public:
    Store(Time* gameTime);
    Response buy(Alcohol* alco, size_t amount, Player* player);
    Response buy(Fruit* fruit, size_t amount, Player* player);
    Response buy(Item* item, size_t amount, Player* player);
    Response sell(Alcohol* alco, size_t amount, Player* player);
    Response sell(Fruit* fruit, size_t amount, Player* player);
    Response sell(Item* item, size_t amount, Player* player);
    void generateGoods();
    friend std::ostream& operator<<(std::ostream& print, const Store& store);

private:
    Time* timeTracker_;

    Response buys(Cargo* cargo, size_t amount, Player* player, size_t totalPrice);
    Response sells(Cargo* cargo, size_t amount, Player* player, size_t totalPrice);
    std::vector<std::shared_ptr<Cargo>> cargoToSell_;
    void AddGeneratedStore(size_t expiryDate, size_t amount, size_t pos);
};
