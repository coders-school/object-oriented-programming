#pragma once

#include "map.hpp"
#include "player.hpp"
#include "time.hpp"

class Game {
public:
    enum class Action {
        Travel = 1,
        Sell = 2,
        Buy = 3,
        checkCargo = 4
    };

    Game(size_t money, size_t days, size_t finalGoal);
    void startGame();

private:
    struct BuySellAction {
        size_t option = 0;
        size_t amount = 0;
        bool valid = false;
    };

    bool checkWinCondition() const;
    bool checkLooseCondition() const;
    void printMenu();
    void printOptions();
    void printWinScreen();
    void printLooseScreen();
    void makeAction(Action action);
    void travel();
    void buy();
    void sell();
    void printCargo();
    BuySellAction buySellChoice(const CargoHolder* const sourceCargoHolder) const;

    size_t money_;
    size_t days_;
    size_t finalGoal_;
    size_t currentDay_;

    std::unique_ptr<Map> map_;
    std::shared_ptr<Time> time_;
    std::shared_ptr<Player> player_;
};
