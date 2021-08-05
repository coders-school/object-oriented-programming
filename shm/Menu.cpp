#include "Menu.hpp"
#include "Map.hpp"
#include "Game.hpp"



Menu::Menu(){}
Menu::~Menu(){}

Menu::Menu()
:game_(std::make_unique<Game>())
{}
Menu::~Menu(){}

int Menu::playerChoice()
{
    return 1;
}

void Menu::menuHandler(MenuItem item, Store* currentStore, Map* map, Player* player) 
{
    
    switch(item)
    {
        case MenuItem::buyCargo:
                std::cout << "Welcome captain, what business brings you here?\n";
                std::cout << "Choose a cargo to buy: " << '\n';
                currentStore->printStoreCargo();
                currentStore->buy(currentStore->storeCargo.at(1), 1, player);
                printMenu();

        case MenuItem::sellCargo:
                std::cout << "Welcome captain, what business brings you here?\n";
                std::cout << "Choose a cargo to sell: " << '\n';
                currentStore->printStoreCargo();
                currentStore->sell(currentStore->storeCargo.at(0), 1, player);
                printMenu();

        case MenuItem::travel:
                std::cout << "Where should we travel now?\n";
                std::cout << "Set sails!" << '\n';
                map->DebugPrintIsland();
                printMenu();

        case MenuItem::Exit:
                std::cout << "Get me out of this game, I'm done\n";
                break;
    }
}


MenuItem Menu::menuChoice(){
    int input;
    std:: cin >> input;

    switch(input)
    {
        case 1:
            return MenuItem::buyCargo;
            break;
        case 2:
            return MenuItem::sellCargo;
            break;
        case 3:
            return MenuItem::travel;
            break;
        case 4:
            return MenuItem::Exit;
            break;
        default:
            std::cout << "Please use 1 - 4" << '\n';
            // printMenu();
    }
}

void Menu::printMenu() {
    std::cout << "1 - Buy Cargo\n";
    std::cout << "2 - Sell Cargo\n";
    std::cout << "3 - Travel\n";
    std::cout << "4 - Exit\n";
}

