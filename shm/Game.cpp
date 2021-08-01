#include "Game.hpp"

Game::Game(size_t money, size_t days, size_t final_goal)
: money_(money), days_(days), final_goal_(final_goal) {
    map_ = std::make_unique<Map>(new Map());
    std::unique_ptr<Ship> ship (new Ship(1000, 50, 10, "HMS Terror", 1));
    //player_ = std::make_unique<Player>(new Player(ship, money_));
    ///time_ = std::make_unique<Time>(new Time());
}

void Game::StartGame(){};