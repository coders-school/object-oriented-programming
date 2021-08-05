#pragma once
#include <iostream>
#include <memory>
#include "Map.hpp"
#include "Menu.hpp"
#include "player.hpp"
#include "Time.hpp"
#include "coordinates.hpp"
class Game
{
public:
    Game(size_t money, size_t gameDays, size_t finalGoal);
    Game();

    void setPlayer();
    void startGame();
    void printTitle();
    void printMap(Map &);
    void travel();
    
private:
    size_t money_;
    size_t gameDays_;
    size_t finalGoal_;
    std::unique_ptr<Menu> menu_;
    Map* map_;
    Store* store_;
    Time* time_;
    Player* playerOne_;
};