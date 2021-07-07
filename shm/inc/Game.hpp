#pragma once

#include <memory>

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
  
    void selectOption();
    void showMap();     //NOT IMPLEMENTED
    void travel();      //NOT IMPLEMENTED
    void checkCargo();  //NOT IMPLEMENTED
    void buy();         //NOT IMPLEMENTED
    void sell();        //NOT IMPLEMENTED
    
    size_t money_;
    size_t game_days_;
    const size_t final_goal_;
    size_t current_day_;
    std::unique_ptr<Player> player_;
    std::unique_ptr<Time> time_;
    std::unique_ptr<Ship> ship_;
    std::unique_ptr<Map> map_;

    bool isGameWon() const;
    bool isGameLost() const;
    
};
