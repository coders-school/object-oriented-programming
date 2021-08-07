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
    Exit
};
class Menu 
{
public:
    Menu(std::unique_ptr<Game>);
    ~Menu();
    void printMenu();
    MenuItem menuChoice();
    void menuHandler(MenuItem item, Store* currentStore, Map* map, Player* player);
    int playerChoice();

private:
    std::unique_ptr<Game> game_;
};