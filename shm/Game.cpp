#include "Game.hpp"

#include <iostream>

Game::Game(size_t money, size_t days, size_t final_goal)
    : _money(money), _days(days), _final_goal(final_goal) {
}

void Game::StartGame() {
    std::cout << "Welcome in game SHM (made by The Diggers)\n" <<
        << "-= This is demo version =-";
}
