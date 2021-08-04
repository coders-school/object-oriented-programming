#pragma once

#include "Map.hpp"
#include "GeneralPrint.hpp"
#include "Command.hpp"
#include <array>
#include <cmath>
#include <iostream>
#include <map>

std::unique_ptr<Cargo> generateCargo();

class Game
{
public:
    Game(size_t startMoney, size_t daysLimit, size_t goal)
        : startMoney_(startMoney), daysLimit_(daysLimit), goal_(goal) {}

    void startGame();
    void init();

    constexpr static size_t startingPlayerCargoNumber = 5;
    constexpr static size_t storeCargoNumber = 5;

    void fillCargo(Warehouse &holder, size_t number);
   
private:
    size_t startMoney_;
    size_t daysLimit_;
    size_t goal_;
    bool endGame{false};
    bool playerWin{false};

    std::map<std::string, std::unique_ptr<Command>> commands{};
    Map map{};
    Player player{std::make_unique<Ship>(), startMoney_};
    Store store{};
};
