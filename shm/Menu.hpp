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
        printPlayerCargo,
        printStoreCargo,
        buyCargo,
        sellCargo,
        travel,
        Exit,
    };

    Menu(Game*);
    ~Menu();

    bool isPlayerChoiceValid(const size_t &playerAnswer);
    void menuChoice(MenuItem);
    void printMenu();
    void playerChoice();

private:
    MenuItem item_;
    Game* game_;
};
