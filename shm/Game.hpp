#ifndef GAME_HPP
#define GAME_HPP
#include <memory>
#include "Action.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "Time.hpp"

class Game {
private:
    size_t money_;
    size_t days_;
    size_t finalGoal_;
    size_t currentDay_;
    std::unique_ptr<Map> map_;
    std::unique_ptr<Time> time_;
    std::unique_ptr<Player> player_;

    void checkWinCondition() ;
    bool checkLooseCodition() ;
    void printStats();
    void printMenu();
    void printOptions();
    void printWinScreen();
    void printLooseScreen();
    void makeAction(const Action &choice);
    void travel();
    void buy();
    void sell();
    void printCargo();
    Action readCharacter();

public:
    Game(size_t money, size_t days, size_t finalGoal);
    void startGame();
};

#endif