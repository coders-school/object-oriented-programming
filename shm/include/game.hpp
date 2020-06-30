#pragma once

#include "commands.hpp"
#include "map.hpp"
#include "player.hpp"
#include "ship.hpp"
#include "time.hpp"

#include <memory>

enum class Action {
    Buy,
    Sell,
    Travel,
    PrintCargo,
};

class Game {
public:
    Game(size_t money,
         size_t days,
         size_t finalGoal,
         size_t availableSpace);  // TODO: this is not specified in uml
    void startGame();

private:
    void checkWinCondition() const;
    void checkLooseCondition() const;
    void printMenu();
    void printOptions();
    void printWinScreen();
    void printLooseScreen();
    void makeAction(Action action);
    void printCargo();

    size_t money_;
    size_t days_;
    size_t final_goal_;
    size_t current_day_;
    std::unique_ptr<Map> map_;
    std::unique_ptr<Time> time_;
    std::unique_ptr<Player> player_;
    std::unique_ptr<Travel> travel_command_;
    std::unique_ptr<Buy> buy_command_;
    std::unique_ptr<Sell> sell_command_;
    std::unique_ptr<PrintCargo> print_cargo_command_;
};
