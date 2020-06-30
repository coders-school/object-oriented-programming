#pragma once

#include "cargo.hpp"
#include "player.hpp"

class Store {
public:
    Store();
    ~Store();

    enum class Response { done, lack_of_money, lack_of_cargo, lack_of_space };

    Response buy(std::shared_ptr<Cargo> cargo, uint32_t amount, Player* player);
    Response sell(std::shared_ptr<Cargo> cargo, uint32_t amount, Player* player);

    std::shared_ptr<Cargo> getCargo(uint32_t index) const;
    void generateCargo(Time* time);
    void printCargo() const;
    void loadToStore(std::shared_ptr<Cargo> cargo);

private:
    std::vector<std::shared_ptr<Cargo>> cargo_;
    friend std::ostream& operator<<(std::ostream& output, const Store& store);
};
