#include "game.hpp"

constexpr size_t START_MONEY = 500;
constexpr size_t GAME_DAYS = 100;
constexpr size_t FINAL_GOAL = 5000;

int main() {
    Game game(START_MONEY, GAME_DAYS, FINAL_GOAL);
    game.startGame();
    
    return 0;
}
