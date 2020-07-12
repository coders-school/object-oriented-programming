#pragma once

#include <memory>
#include <vector>

#include "cargo.hpp"
#include "player.hpp"
#include "time.hpp"

class Store : public Observer {
public:
    enum class Response { done, lack_of_money, lack_of_cargo, lack_of_space };
    Store();
    Store(const std::vector<std::shared_ptr<Cargo>>& stock);

    // override from Observer
    ~Store() override;

    Response buy(Cargo* cargo, size_t amount, Player* player);
    Response sell(Cargo* cargo, size_t amount, Player* player);
    Cargo* getCargo(const size_t position);
    // override from Observer
    void nextDay() override;
    friend std::ostream& operator<<(std::ostream& str, const Store& store);

private:
    std::vector<std::shared_ptr<Cargo>> stock_;
    void load(std::shared_ptr<Cargo> cargo, size_t amount);
    void unload(Cargo* cargo, size_t amount);
    std::vector<std::shared_ptr<Cargo>>::iterator findStock(Cargo* cargo);
    void randomizeRegularCargo(
        const std::vector<std::shared_ptr<Cargo>>& possibleRegularCargo);
    void randomizeItems(const std::vector<std::shared_ptr<Cargo>>& items);
    void generateRegularCargo();
    void generateItems();
};
