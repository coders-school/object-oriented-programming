#include "shm/inc/Game.hpp"
#include <iostream>
#include <memory>

Game::Game(size_t money, size_t game_days, size_t final_goal)
    : money_(money)
    , game_days_(game_days)
    , final_goal_(final_goal)
{}

void Game::startGame() {

}