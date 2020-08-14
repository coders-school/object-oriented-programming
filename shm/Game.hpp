#pragma once

#include "Map.hpp"
#include "Player.hpp"
#include "Time.hpp"

enum class Action {
        Exit,
        Travel,
        Buy,
        Sell
};

class Game {
private:
    size_t money_;
    const size_t timeLimit_;
    size_t finalGoal_;
    Map* map_{nullptr};
    std::shared_ptr<Player> player_{nullptr};
    Time* time_{nullptr};

    bool checkWinCondition() const;
    bool checkLoseCondition() const;
    void printTheEnd() const;
    void printWinScreen() const;
    void printLoseScreen() const;
    void printEndGameScreen() const;
    void getKeyPress() const;
    void printPromptInvalidDestination() const;
    void printCurrentPositionOnMap() const;

    void travel();
    Coordinates getTravelLocation();
    void advanceTimeTraveling(size_t distance);
    void printOptions() const;
    void printHomeScreen() const;
    void makeAction(Action choice);
    void exit() const;
    void buy();
    void sell();

public:
    Game(size_t money, size_t timeLimit, size_t finalGoal);    
    Action chooseAction();
    void startGame();
};
