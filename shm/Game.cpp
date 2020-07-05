#include "Game.h";

#include "Map.h"
#include "Player.h"
#include "Store.h"
#include "Time.h"

Game::Game(size_t start_money, size_t game_days, size_t final_goal)
    : start_money_(start_money), game_days_(game_days), final_goal_(final_goal) {}

void Game::startGame() {
    Time time;
    Ship ship(10, 3, 3, "Titanic", 0, &time);
    Player player(ship, start_money_);
    Map map(&time);
}
