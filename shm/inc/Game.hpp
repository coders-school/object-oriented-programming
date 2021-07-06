#pragma once

#include <stddef.h>
#include "shm/inc/Ship.hpp"
#include "shm/inc/Player.hpp"

class Game {
public:
    Game(size_t money, size_t game_days, size_t final_goal);

    void startGame();

private:
    void printWelcomeScreen();
    void printMenu();
    
    size_t money_ {};
    size_t game_days_ {};
    const size_t final_goal_ {};
};