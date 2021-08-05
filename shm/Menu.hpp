#pragma once
#include <iostream>
#include <memory>

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
    Menu();
    ~Menu();
    void printMenu();
    MenuItem menuChoice();
    void menuHandler(MenuItem item, Store* currentStore, Map* map, Player* player);
    int playerChoice();

private:
std::unique_ptr<Game> game_;
};