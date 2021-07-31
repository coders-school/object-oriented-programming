#pragma once

#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>

#include "cargo.hpp"
#include "player.hpp"

enum class Response {
    done,
    lack_of_money,
    lack_of_cargo,
    lack_of_space
};

class Store {
public:
    Store();

    Response buy(std::shared_ptr<Cargo> cargo, size_t amount, Player* player);
    Response sell(std::shared_ptr<Cargo> cargo, size_t amount, Player* player);

    std::vector<std::shared_ptr<Cargo>>::iterator  findCargoInStore(const std::shared_ptr<Cargo>& wantedCargo);
    // function loading cargos to store
    void load(const std::shared_ptr<Cargo>& cargo);
    // function ulnoading cargos from store
    void unload(const std::shared_ptr<Cargo>& cargo);
    void addCargosOfStore(std::shared_ptr<Cargo>);
    // void ereasFromCargosOfStore(std::shared_ptr<Cargo>);

    

    friend std::ostream& operator<<(std::ostream& os, const Store& store);
    std::vector<std::shared_ptr<Cargo>> getCargoOfStore() const { return stock_; };

private:
    std::vector<std::shared_ptr<Cargo>> stock_{};
    void generateDefaultCargo();
};
