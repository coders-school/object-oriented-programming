#pragma once

#include <cstddef>

class Game {
public:
    Game(size_t start_money, size_t game_days, size_t final_goal);
    void startGame();

private:
    size_t start_money_;
    size_t game_days_;
    size_t final_goal_;
};
