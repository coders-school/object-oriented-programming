#pragma once
#include <iostream>

enum MenuItem
{
    buyCargo,
    sellCargo,
    travel,
    Exit,
};

class Menu {
public:
    Menu();
    ~Menu();
    void printMenu();
    void menuChoice();
    void menuHandler(MenuItem item);
    int playerChoice();

private:

};