#pragma once

#include <iomanip>
#include <iostream>

#include "cargo.hpp"
#include "common.hpp"
#include "player.hpp"

constexpr size_t DEFAULT_CAPACITY = 1000;
constexpr size_t DEFAULT_FUNDS = 1000;

class Store {
public:
    enum class Response {
        invalid_cargo_name,
        done,
        lack_of_money,
        lack_of_cargo,
        lack_of_space
    };

    enum updateMode {
        BUY = 0,
        SELL = 1
    };

    Store();
    Store(size_t capacity, size_t avaiableFunds);
    ~Store() = default;

    Response buy(Cargo* cargo, size_t amount, Player* player);
    Response sell(Cargo* cargo, size_t amount, Player* player);
    bool addCargo(Cargo* cargo);
    size_t getAvaiableSpace() const;
    size_t getAvaiableFunds() const { return avaiableFunds_; };
    void setCapacity(const size_t amount) { capacity_ = amount; }
    void setAvaiableFunds(const size_t amount) { avaiableFunds_ = amount; }

    Cargo* getCargo(const std::string& name);
    void printCargo();
    void printResponseMessage(Response& response);

private:
    size_t capacity_;
    size_t avaiableFunds_;
    std::vector<Cargo*> cargoVec;

    void updateCargo(Cargo* cargo, size_t amount, updateMode mode, Player* player);
};
