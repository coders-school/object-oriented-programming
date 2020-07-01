#pragma once

#include "alcohol.hpp"
#include "cargo.hpp"
#include "fruit.hpp"
#include "item.hpp"
#include "player.hpp"

class Store {
private:
    std::vector<std::shared_ptr<Cargo>> cargo_;
    friend std::ostream& operator<<(std::ostream& output, const Store& store);

public:
    enum class Response { done, lack_of_money, lack_of_cargo, lack_of_space };

    Store();
    Response buy(std::shared_ptr<Cargo> cargo, size_t amount, Player* player);
    Response sell(std::shared_ptr<Cargo> cargo, size_t amount, Player* player);

    std::shared_ptr<Cargo> getCargo(uint32_t index) const;
    void generateCargo();
    void printCargo() const;
    void loadToStore(std::shared_ptr<Cargo> cargo, uint32_t amount);
};
