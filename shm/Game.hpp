#pragma once

#include "Map.hpp"
#include "Player.hpp"
#include "Time.hpp"

enum class Action {
    buy = 1,
    sell = 2,
    travel = 3
};

class Game {
    uint16_t money_;
    uint16_t days_;
    uint16_t finalGoal_;
    uint16_t currentDay_;
    Map* map_;
    Time* time_;
    Player* player_;

    void CheckWinCondition() const;
    bool CheckLooseCondition() const;
    void PrintMenu();
    void PrintOptions();
    void PrintWinScreen();
    void PrintLooseScreen();
    void MakeAction(Action);
    void Travel();
    void Buy();
    void Sell();
    void PrintCargo();

public:
    Game(uint16_t, uint16_t, uint16_t);
    void StartGame();
};
