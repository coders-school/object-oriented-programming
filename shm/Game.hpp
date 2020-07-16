#pragma once

#include "Map.hpp"
#include "Player.hpp"

enum class Action {
        Exit,
        Travel,
        Buy,
        Sell,
};

class Game {
private:
    size_t money_;
    size_t days_;
    size_t final_goal_;
    size_t current_day_;
    Map* map_;
    Player* player_;

    bool checkWinCondition() const;
    bool checkLoseCondition() const;
    void PrintOptions();
    void MakeAction(Action choice);
    void Exit();
    void Travel();
    void Buy();
    void Sell();

public:
    Game(size_t money, size_t days, size_t final_goal);    
};
