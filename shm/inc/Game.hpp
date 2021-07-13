#pragma once

#include <cstddef>
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
        NoChoice,
        PrintMap,
        Travel,
        PrintCargo,
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
    void printHeader();
    void printMap();

    void printWinScreen();
    void printLoseScreen();
    void announcementGenerate(const std::string & announcenent);
    void printResponse(const Store::Response& response,
                       const std::string& message);
    void setUserCargo(std::string& cargoName, size_t& cargoAmount);
    void setUserDestination(size_t& islandNo, size_t islandMax);
    size_t money_;
    size_t gameDays_;
    const size_t finalGoal_;
    size_t currentDay_{};
  
    void travel();
    void printCargo();  //NOT IMPLEMENTED
    void buy();
    void sell();
    void hireCrew();
    MenuOption exitGame();
    
    std::unique_ptr<Player> player_;
    std::unique_ptr<Time> time_;
    std::unique_ptr<Map> map_;

    bool isGameWon();
    bool isGameLost();
    bool isChoiceValid(const size_t & option);
    CheckAnswer checkAnswer(const std::string & announcement);
    MenuOption selectOption();
    MenuOption actionMenu(MenuOption userAnswer);
    bool isCrewNumber(const size_t & crew);
    bool hasPlayerEnoughMoney(const size_t & crew);
    
    MenuOption menuOption_ { MenuOption::NoChoice };
};
