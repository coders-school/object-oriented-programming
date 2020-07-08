#pragma once

#include "map.hpp"
#include "player.hpp"
#include "ship.hpp"
#include "timeSHM.hpp"
#include "constValues.hpp"

class Game {
public:
    enum class Action {
        exit = 0,
        travel = 1,
        buy = 2,
        sell = 3,
        hireCrew = 4,
        printCargo = 5
    };

    Game(size_t money, size_t days, size_t finalGoal);

    void startGame();

private:
    size_t money_ {0};
    size_t days_ {0};
    const size_t finalGoal_ {0};
    size_t currentDay_ {0};
    std::shared_ptr<Time> publisher_;
    std::shared_ptr<Ship> ship_;
    std::shared_ptr<Player> player_;
    std::shared_ptr<Map> map_;

    void gameLoop();
    void inputValidator();
    void printTrail(char sign);
    void printStars(size_t amountOfGalaxy);
    void printHeader();
    void printWelcomePage();
    bool checkWinConditions() const;
    void printWinScreen();
    bool checkLoseConditions() const;
    void printLoseScreen();
    void printStats();
    void printOptions();
    void makeAction(Action pickAction);
    Island* pickTargetIsland();
    size_t countDaysOfTravel(Island* island);
    char userTravelDecision(size_t daysOfTravel);
    void travel();
    void makeTravel(Island* island, size_t daysOfTravel);
    void buy();
    void sell();
    void showCargo();
    void hireAction();
    void hireFullCrew();
    void fireSailors();
    void hireSailors();
};
