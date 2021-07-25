#pragma once
#include "cargo.hpp"
#include "player.hpp"
#include "ship.hpp"
#include <iostream>
#include <random>
#include <algorithm>

class Player;
class Cargo;

class Store {
public:
    enum class Response { done,
                          lack_of_money,
                          lack_of_cargo,
                          lack_of_space };

    Response buy(Cargo*, size_t amount, Player*);
    Response sell(Cargo*, size_t amount, Player*);

    void addToVecOfCargos(std::shared_ptr<Cargo>);
    void dellFromVecOfCargos(std::shared_ptr<Cargo>);
    bool checkAvaiablityCargoInStore(std::shared_ptr<Cargo> searchCargo);
    std::vector<std::shared_ptr<Cargo>> nextDay(Cargo* cargo, std::vector<std::shared_ptr<Cargo>> cargosInStore);
    friend std::ostream& operator<<(std::ostream& out, const Store& store);
    std::vector<std::shared_ptr<Cargo>> returnCargosVector() const { return cargosInStore; }

private:
    std::vector<std::shared_ptr<Cargo>> cargosInStore{};
};