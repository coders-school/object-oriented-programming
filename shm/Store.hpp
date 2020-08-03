#pragma once

#include <iostream>

#include "Cargo.hpp"
#include "Item.hpp"
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

enum class Response {
    done,
    lack_of_money,
    lack_of_cargo,
    lack_of_space
};

class Store : public Observer {
private:
    CargoStock market_{};
    std::shared_ptr<Time> time_{nullptr};

    size_t genRand(size_t min, size_t max) const;
    void generateFruits();
    void generateAlcos();
    void generateItems();
    void makeStock();
    CargoPtr makeNewCargo(const CargoPtr& cargo, size_t amount) const;
    void removeFromStore(const CargoPtr& cargo, size_t amount);
    CargoPtr findCargo(const CargoPtr& cargo) const;
    void addToStore(const CargoPtr& cargo, size_t amount);

public:
    Store(std::shared_ptr<Time>& time);
    Response buy(const CargoPtr& cargo, size_t amount, const std::shared_ptr<Player>& player);
    Response sell(const CargoPtr& cargo, size_t amount, const std::shared_ptr<Player>& player);
    CargoPtr getCargo(size_t index) const;

    //Override from Observer
    void nextDay() override;

    friend std::ostream& operator<<(std::ostream& out, const Store& store);
};
