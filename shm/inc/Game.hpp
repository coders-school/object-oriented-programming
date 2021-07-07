#pragma once

#include <map>
#include <memory>
#include <utility>

#include "shm/inc/Player.hpp"
#include "shm/inc/Ship.hpp"
#include "shm/inc/Time.hpp"
#include "shm/inc/Map.hpp"


class Ship;
class Game {
public:
    Game(size_t money, size_t game_days, size_t final_goal);

    void startGame();

private:
    void printWelcomeScreen();
    void printMenu();
    void printMap();
    
    size_t money_ {};
    size_t game_days_ {};
    const size_t final_goal_ {};
    size_t current_day_;
    std::unique_ptr<Player> player_;
    std::unique_ptr<Time> time_;
    std::unique_ptr<Ship> ship_;
    std::unique_ptr<Map> map_;

    bool isGameWon() const;
    bool isGameLost() const;
    
};
