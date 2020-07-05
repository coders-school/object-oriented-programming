#pragma once

#include <memory>

#include "map.hpp"
#include "player.hpp"
#include "ship.hpp"
#include "time.hpp"

class Game {
public:
    Game();
    Game(size_t start_money, size_t game_days, size_t final_goal);
    void startGame();
    enum class Action {
        Exit,
        Travel,
        Buy,
        Sell,
        PrintCargo,
    };

private:
    size_t start_money_ = 1000;
    size_t game_days_ = 100;
    size_t final_goal_ = 2000;
    std::unique_ptr<Map> map_;
    std::shared_ptr<Time> time_;
    std::shared_ptr<Ship> ship_;
    std::unique_ptr<Player> player_;

    std::shared_ptr<Ship> generateShip();
    bool checkWinCondition() const;
    bool checkLooseCondition() const;
    void printTopBar() const;
    void printOptions() const;
    void printWinScreen() const;
    void printLooseScreen() const;
    void makeAction(Action action);
    void travel();
    void buy();
    void sell();
    void printCargo() const;
    void exit();
};
