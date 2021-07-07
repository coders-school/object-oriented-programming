#pragma once

#include <map>
#include <memory>
#include <utility>

#include "shm/inc/Player.hpp"
#include "shm/inc/Ship.hpp"
#include "shm/inc/Time.hpp"
#include "shm/inc/Map.hpp"
//#include "shm/inc/Island.hpp"


class Ship;
class Game {
public:
    Game(size_t money, size_t game_days, size_t final_goal);

    void startGame();

private:
    void printWelcomeScreen();
    void printMenu();
    void mapGenerate();
    void printMap();
    
    size_t money_ {};
    size_t game_days_ {};
    const size_t final_goal_ {};
    size_t current_day_;
    std::unique_ptr<Player> player_;
    std::unique_ptr<Time> time_;
    std::unique_ptr<Ship> ship_;
    std::unique_ptr<Map> map_;
    std::map<size_t, std::pair<size_t, size_t>> island;

    bool isGameWon() const;
    bool isGameLost() const;
    
};
