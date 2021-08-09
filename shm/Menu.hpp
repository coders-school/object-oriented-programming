#pragma once
#include <iostream>
#include <memory>
#include "Map.hpp"
#include "Store.hpp"

class Game;


class Menu 
{
public:
    enum MenuItem
    {
        wrongChoice,
        printPlayerCargo,
        buyCargo,
        sellCargo,
        travel,
        Exit,
    };

    Menu(Game*);
    ~Menu();

    bool isPlayerChoiceValid(const size_t &playerAnswer);
    void menuChoice(MenuItem);
    void menuHandler(MenuItem item, Store* currentStore, Map* map, Player* player);
    void printMenu();
    void playerChoice();

private:
    MenuItem item_;
    Game* game_;
};
