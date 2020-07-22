#pragma once

#include "Cargo.hpp"
#include "Observer.hpp"
#include "Player.hpp"

const std::vector<std::string> fruitNames = {
    "apple",
    "pineapple",
    "coconut",
    "orange",
    "banana",
    "watermelon"};

const std::vector<std::string> alcoNames = {
    "whiskey",
    "rum",
    "beer",
    "ale",
    "vodka",
    "absinthe"};

const std::vector<std::string> itemNames = {
    "cutlass",
    "chest",
    "parrot",
    "old coin",
    "rusty gun",
    "pirate's flag"};

constexpr size_t marketSection = 4;
using Cargos = std::vector<::std::shared_ptr<Cargo>>;

enum class Response {
    done,
    lack_of_money,
    lack_of_cargo,
    lack_of_space
};

class Store : public Observer {
private:
    Cargos market_;
    std::shared_ptr<Time> time_{nullptr};

    size_t generateRandom(int min, int max) const;
    Cargos generateFruits() const;
    Cargos generateAlcos() const;
    Cargos generateItems() const;
    Cargos makeStock(const Cargos& fruits, const Cargos& alcos, const Cargos& items);

public:
    Store(std::shared_ptr<Time>& time);
    Response buy(Cargo* cargo, size_t amount, Player* player);
    Response sell(Cargo* cargo, size_t amount, Player* player);

    //Override from Observer
    void nextDay() override;
};
