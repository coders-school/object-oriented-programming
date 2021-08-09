#pragma once

#include <array>
#include <cmath>
#include <iostream>
#include <map>
#include "Command.hpp"
#include "GeneralPrint.hpp"
#include "Map.hpp"

std::unique_ptr<Cargo> generateCargo();

class Game {
public:
    constexpr static size_t startingPlayerCargoNumber{5ul};
    constexpr static size_t storeCargoNumber{5ul};

    Game(size_t startMoney, size_t daysLimit, size_t goal);

    void startGame();
    void init();

    void fillCargo(Warehouse& holder, size_t number);

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
