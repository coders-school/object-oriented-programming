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
    void menuChoice();
    void menuHandler(MenuItem item);
    int playerChoice();

private:
std::unique_ptr<Game> game_;
};