#pragma once
#include <iostream>
#include "Map.hpp"
#include "player.hpp"
#include "Time.hpp"
class Game
{
public:
    Game(size_t money, size_t gameDays, size_t finalGoal);

    enum class Menu
    {
        buyCargo,
        sellCargo,
        travel,
        Exit
    };

    void setPlayer();
    void startGame();
    void menu();
    void printTitle();
    void printMap();

private:
    size_t money_;
    size_t gameDays_;
    size_t finalGoal_;
};