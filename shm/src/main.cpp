#include <alcohol.hpp>

#include "game.hpp"

constexpr size_t money = 100;
constexpr size_t days = 10;
constexpr size_t finalGoal = 150;

int main() {
    auto game = Game(money, days, finalGoal);
    game.startGame();

    return 0;
}
