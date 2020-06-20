#pragma once

#include <cstdlib>

class Game {
public:
    Game();
    Game(size_t start_money, size_t game_days, size_t final_goal)
        : start_money_(start_money), game_days_(game_days), final_goal_(final_goal) {
        Game();
    };
    void startGame();

private:
    size_t start_money_ = 1'000;
    size_t game_days_ = 100;
    size_t final_goal_ = 2'000;
};
