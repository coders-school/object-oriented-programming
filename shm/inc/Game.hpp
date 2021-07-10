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
        NoChoice = 0,
        printMap,
        Travel,
        CheckCargo,
        Buy,
        Sell,
        HireCrew,
        Exit
    };

    enum class CheckAnswer {
        Yes,
        No,
        Error
    };

    void startGame();

private:
    void printWelcomeScreen();
    void printMenu();
    void printIntenface();
    size_t printMap();
    void printWinScreen();
    void printLoseScreen();
    size_t money_;
    size_t gameDays_;
    const size_t finalGoal_;
    size_t currentDay_{};
  
    void travel();      //NOT IMPLEMENTED
    void checkCargo();  //NOT IMPLEMENTED
    void buy();         //NOT IMPLEMENTED
    void sell();        //NOT IMPLEMENTED
    void hireCrew();
    MenuOption exitGame();
    
    std::unique_ptr<Player> player_;
    std::unique_ptr<Time> time_;
    std::unique_ptr<Ship> ship_;
    std::unique_ptr<Map> map_;

    bool isGameWon();
    bool isGameLost();
    bool isChoiceValid(const size_t & option);
    CheckAnswer checkAnswer(const std::string & announcemen);
    MenuOption selectOption();
    MenuOption actionMenu(MenuOption userAnswer);
    bool crewIsNumber(const size_t & crew);
    bool validCrewMoney(const size_t & crew);
    
    MenuOption menuOption_ { MenuOption::NoChoice };

};
