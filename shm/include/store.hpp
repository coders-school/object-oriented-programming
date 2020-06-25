#pragma once

#include "cargo.hpp"
#include "player.hpp"

#include <memory>
#include <vector>

class Store {
public:
    enum class Response { done, lack_of_money, lack_of_cargo, lack_of_space };

    explicit Store(const std::vector<std::shared_ptr<Cargo>>& stock);

    Response buy(Cargo* cargo, Player* player);
    Response sell(Cargo* cargo, Player* player);
    void nextDay();
    friend std::ostream & operator<<(std::ostream & str, const Store& store);

private:
    std::vector<std::shared_ptr<Cargo>> stock_;

    void load(std::shared_ptr<Cargo> cargo);
    void unload(Cargo* cargo);
    std::vector<std::shared_ptr<Cargo>>::iterator findStock(Cargo* cargo);
};
