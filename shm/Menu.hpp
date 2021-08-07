#pragma once
#include <iostream>
#include <memory>
#include "Map.hpp"
#include "Store.hpp"

class Game;

enum MenuItem
{
    buyCargo,
    sellCargo,
    travel,
    Exit,
    wrongChoice
};
class Menu 
{
public:
    Menu(Game*);
    ~Menu();
    void printMenu();
    MenuItem menuChoice();
    void menuHandler(MenuItem item, Store* currentStore, Map* map, Player* player);
    // int playerChoice();

private:
    Game* game_;
};