#include "shm/inc/Game.hpp"

#include "shm/inc/Player.hpp"
#include "shm/inc/Time.hpp"

Game::Game(size_t money, size_t game_days, size_t final_goal)
    : money_(money)
    , game_days_(game_days)
    , final_goal_(final_goal)
    , time_(std::make_unique<Time>())
{
    current_day_ = time_->getElapsedTime();
}

void Game::startGame() {
    while (game_days_ > current_day_) {
        if (isGameWon()) {
            // YOU WON!
            return;
        }
        // CONTUNUE GAME
    }
    // YOU LOST!
}

bool Game::isGameWon() const {
    return player_->getMoney() >= final_goal_;
}

bool Game::isGameLost() const {
    // probably not needed (any suggestions?)
    return false;
}
