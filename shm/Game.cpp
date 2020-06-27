#include "Game.hpp"

#include <iostream>

Game::Game(size_t money, size_t days, size_t finalGoal)
    : _money(money), _days(days), _finalGoal(finalGoal) {
}

void Game::StartGame() {
    std::cout << "Welcome in game SHM (made by The Diggers)\n"
        << "-= This is demo version =-\n\n";
}
