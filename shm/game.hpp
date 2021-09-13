#pragma once
#include <iostream>
#include <memory>

#include "coordinates.hpp"
#include "iObserver.hpp"
#include "island.hpp"
#include "map.hpp"
#include "player.hpp"
#include "ship.hpp"
#include "time.hpp"

class Game {
    enum class MenuOption {
        Travel = 1,
        PrintCargo,
        Buy,
        Sell,
        Position,
        Exit
    };


public:
    Game(size_t money, size_t days, size_t goal);
    ~Game();
    void startGame();


    void printWinScreen();
    void printLoseScreen();
    void printHeader();
    void printMenu();

    bool checkLoseCondition();
    bool checkWinCondition();

    void setPlayer();

    void chooseOption(MenuOption option);
    void printMap(const std::shared_ptr<Player>);
    void printCargo();
    void travel();
    void sell();
    void exit();
    void buy();

protected:
    std::shared_ptr<Time> time_;
    std::shared_ptr<Ship> ship_;
    Map map_;
    std::shared_ptr<Player> player_;

private:
    size_t money_;
    size_t gameDayes_;
    size_t finalGoal_;
    size_t islandNo_;
};