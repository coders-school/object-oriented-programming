#pragma once

#include <cstddef>

class Game {
public:
    Game(size_t money, size_t days, size_t finalGoal);
    void StartGame();

private:
    size_t _money;
    size_t _days;
    size_t _finalGoal;
};
