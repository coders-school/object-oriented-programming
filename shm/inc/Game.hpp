#pragma once

#include <memory>

#include "shm/inc/Player.hpp"
#include "shm/inc/Ship.hpp"
#include "shm/inc/Time.hpp"

class Ship;
class Game {
public:
    Game(size_t money, size_t gameDays, size_t finalGoal);

    void startGame();

private:
    void printWelcomeScreen();
    void printMenu();
    void printIntenface();
    
    size_t money_ {};
    size_t gameDays_ {};
    const size_t finalGoal_ {};
    size_t currentDay_ {};
    std::unique_ptr<Player> player_;
    std::unique_ptr<Time> time_;
    std::unique_ptr<Ship> ship_;

    bool isGameWon() const;
    bool isGameLost() const;
};
