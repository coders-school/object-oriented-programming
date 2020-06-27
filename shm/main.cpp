#include <iostream>

#include "Game.hpp"

constexpr size_t startMoney = 1'000;
constexpr size_t gameDays = 100;
constexpr size_t finalGoal = 2'000;

int main() {
    Game game(startMoney, gameDays, finalGoal);
    game.StartGame();

    return 0;
}
