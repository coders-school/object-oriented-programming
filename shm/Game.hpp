#pragma once

#include "Map.hpp"
#include "Player.hpp"
#include "Time.hpp"

enum class Action {
        Exit,
        Travel,
        Buy,
        Sell,
};

class Game {
private:
    size_t money_;
    const size_t days_;
    size_t final_goal_;
    size_t current_day_;
    Map* map_;
    Player* player_;
    Time* time_;

    bool checkWinCondition() const;
    bool checkLoseCondition() const;
    void printTheEnd() const;
    void printWinScreen() const;
    void printLoseScreen() const;

    void Travel();
    Coordinates getTravelLocation();
    void advanceTimeTraveling(size_t distance);
    void PrintOptions();
    void MakeAction(Action choice);
    void Exit();
    void Buy();
    void Sell();

public:
    Game(size_t money, size_t days, size_t final_goal);    
};
