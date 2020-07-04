#include "Game.hpp"

Game::Game(size_t money, size_t days, size_t final_goal)
    : money_(money), days_(days), final_goal_(final_goal) {}

bool Game::checkWinCondition() const {
    return (player_->getMoney() >= final_goal_);
}

bool Game::checkLoseCondition() const {
    return (player_->getMoney() == 0);
}