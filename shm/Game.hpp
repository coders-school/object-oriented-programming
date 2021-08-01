#pragma once
#include <iostream>
#include "Map.hpp"
#include "Menu.hpp"
#include "player.hpp"
#include "Time.hpp"
class Game
{
public:
    Game(size_t money, size_t gameDays, size_t finalGoal);

    void setPlayer();
    void startGame();
    void menu();
    void printTitle();
    void printMap();
    friend void Map::DebugPrintIsland();

private:
    size_t money_;
    size_t gameDays_;
    size_t finalGoal_;
    std::unique_ptr<Menu> menu_;
};