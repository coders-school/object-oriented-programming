#pragma once

#include "cargo.hpp"
#include "player.hpp"
#include "timeSHM.hpp"

using randomVal = std::uniform_int_distribution<size_t>;

enum class Response { done, lack_of_money, lack_of_cargo, lack_of_space };

class Store {
public:
    Store(Time* gameTime);

    Response buy(std::shared_ptr<Cargo> cargo, size_t amount, Player* player);
    Response sell(std::shared_ptr<Cargo> cargo, size_t amount, Player* player);
    void generateGoods();
    std::shared_ptr<Cargo> getCargo(const std::string& name);
    size_t getTotalBuyPrice(std::shared_ptr<Cargo> cargo, size_t amount);
    size_t getTotalSellPrice(std::shared_ptr<Cargo> cargo, size_t amount);
    friend std::ostream& operator<<(std::ostream& print, const Store& store);

private:
    Time* timeTracker_;

    std::vector<std::shared_ptr<Cargo>> cargoToSell_;
    void AddGeneratedCargo(size_t expiryDate, size_t amount, size_t pos);
};
