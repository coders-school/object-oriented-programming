#pragma once

#include <memory>

#include "shm/inc/Player.hpp"
#include "shm/inc/Ship.hpp"
#include "shm/inc/Time.hpp"
#include "shm/inc/Map.hpp"

class Ship;
class Game {
public:
    Game(size_t money, size_t gameDays, size_t finalGoal);

    enum class MenuOption {
        NoChoose = 0,
        printMap,
        Travel,
        CheckCargo,
        Buy,
        Sell,
        Exit
    };

    void startGame();

private:
    void printWelcomeScreen();
    void printMenu();
    void printIntenface();
    void printMap();
    size_t money_;
    size_t gameDays_;
    const size_t finalGoal_;
    size_t currentDay_{};
  
    void selectOption();
    void travel();      //NOT IMPLEMENTED
    void checkCargo();  //NOT IMPLEMENTED
    void buy();         //NOT IMPLEMENTED
    void sell();        //NOT IMPLEMENTED
    
    std::unique_ptr<Player> player_;
    std::unique_ptr<Time> time_;
    std::unique_ptr<Ship> ship_;
    std::unique_ptr<Map> map_;

    bool isGameWon() const;
    bool isGameLost() const;

    MenuOption menuOption_ { MenuOption::NoChoose };
};
