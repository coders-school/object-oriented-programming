#pragma once

#include "Map.hpp"
#include "Player.hpp"
#include "Time.hpp"

class Game {
private:
    size_t money_;
    size_t days_;
    size_t final_goal_;
    size_t current_day_;
    Map* map_;
    Player* player_;
    Time* time_;

    bool checkWinCondition() const;
    bool checkLoseCondition() const;
    void Travel();
    Coordinates getTravelLocation();
    void advanceTimeTraveling(size_t distance);



public:
    Game(size_t money, size_t days, size_t final_goal);

    enum class Action {
        buy,
        sell,
        travel,
    };
};