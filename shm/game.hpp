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
        Exit
    };


public:
    // Game();
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
  //  void printMap(std::shared_ptr<Map>);
   // void printCargo();
    void travel();
    void sell();
    void exit();
    void buy();

private:
    size_t money_;
    size_t gameDayes_;
    size_t finalGoal_;

    // std::shared_ptr<Player> player_{nullptr};
    // std::shared_ptr<Ship> ship_{nullptr};
    // std::shared_ptr<Time> time_{nullptr};
    // std::shared_ptr<Map> map_{nullptr};

    // Player player_;
     Ship ship_;
     Map map_{};
    Time time_{};
    size_t islandNo_;
};