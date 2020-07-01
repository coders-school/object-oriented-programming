#include <iostream>

#include "Game.hpp"
#include "Testing.hpp"

constexpr size_t startMoney = 1'000;
constexpr size_t gameDays = 100;
constexpr size_t finalGoal = 2'000;


int main() {
    RunSelfTests(false);

    Game game(startMoney, gameDays, finalGoal);
    game.StartGame();

    return 0;
}
