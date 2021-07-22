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
    Island* generateDestinationIsland();
    void setUserDestination();
    void countingCurrentDay(size_t travelTime);
    size_t getTravelDistance(Island* destinationIsland);
    void generatingTravelInfo();
    size_t money_;
    size_t gameDays_;
    const size_t finalGoal_;
    size_t currentDay_{};
  
    void travel();
    void printCargo();
    void printCargoFromStore();
    void printCargoFromShip();
    void buy();
    void sell();
    void manageCrew();
    void hireCrew();
    void dismissCrew();
    void printCrew();
    MenuOption exitGame();
    
    std::unique_ptr<Player> player_;
    std::unique_ptr<Time> time_;
    std::shared_ptr<Map> map_;

    bool isGameWon();
    bool isGameLost();
    bool isChoiceValid(const size_t & option);
    CheckAnswer checkAnswer(const std::string & announcement);
    MenuOption selectOption();
    MenuOption actionMenu(MenuOption userAnswer);
  
    bool isCrewNumber(const int crew);
    bool hasPlayerEnoughMoney(const int crew);
    bool isNumberLowerThanZero(const int crew);
  
    MenuOption menuOption_ { MenuOption::NoChoice };
    Island* destinationIsland { nullptr };
    size_t travelCoordX_ {};
    size_t travelCoordY_ {};
    size_t islandMax_ {};
    size_t islandNo_ {};
    size_t playerSpeed{};
    size_t travelTime{};
};
