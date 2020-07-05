#include "game.hpp"
#include "player.hpp"
#include "ship.hpp"
#include "store.hpp"

constexpr size_t start_money = 1'000;
constexpr size_t game_days = 100;
constexpr size_t final_goal = 2'000;

int main() {
    Time gameTime;
    Game game(start_money, game_days, final_goal, &gameTime);
    game.startGame();
    return 0;
}
