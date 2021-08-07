#include "Menu.hpp"
#include "Game.hpp"

Menu::Menu(Game* game)
    : game_(game)
{}
Menu::~Menu(){}

// int Menu::playerChoice()
// {
//     return 1;
// }

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
                break;

        case MenuItem::sellCargo:
                std::cout << "Welcome captain, what business brings you here?\n";
                std::cout << "Choose a cargo to sell: " << '\n';
                currentStore->printStoreCargo();
                currentStore->sell(currentStore->storeCargo.at(0), 1, player);
                printMenu();
                break;
        case MenuItem::travel:
                std::cout << "Where should we travel now?\n";
                std::cout << "Set sails!" << '\n';
                game_->travel();
                std::cout << "Choose Your next move Captain!" << '\n';
                printMenu();
                break;
        case MenuItem::wrongChoice:
                std::cout << "Wrong choice, please use 1 - 4" << '\n';
                printMenu();
                break;
    }
}

MenuItem Menu::menuChoice(){
    int input;
    printMenu();
    std::cin >> input;

    switch(input)
    {
        case 1:
            return MenuItem::buyCargo;
        case 2:
            return MenuItem::sellCargo;
        case 3:
            return MenuItem::travel;
        case 4:
            std::cout << "Get me out of this game, I'm done\n";
            return MenuItem::Exit;
        default:
            return MenuItem::wrongChoice;
    }
}

void Menu::printMenu() {
    std::cout << "1 - Buy Cargo\n";
    std::cout << "2 - Sell Cargo\n";
    std::cout << "3 - Travel\n";
    std::cout << "4 - Exit\n";
}

