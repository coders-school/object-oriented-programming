#include "Menu.hpp"

Menu::Menu(){}
Menu::~Menu(){}


int Menu::playerChoice()
{
    
}

void Menu::menuHandler(MenuItem item) 
{
    switch(item)
    {
        case MenuItem::buyCargo:
                std::cout << "Welcome captain, what business brings you here?\n";
                std::cout << "Choose a cargo to buy: " << '\n';
                break;
        case MenuItem::sellCargo:
                std::cout << "Welcome captain, what business brings you here?\n";
                std::cout << "Choose a cargo to sell: " << '\n';
                break;
        case MenuItem::travel:
                std::cout << "Where should we travel now?\n";
                std::cout << "Set sails!" << '\n';
                break;
        case MenuItem::Exit:
                std::cout << "Get me out of this game, I'm done\n";
                break;
    }
}

void Menu::menuChoice(){
    int input;
    std:: cin >> input;

    switch(input)
    {
        case 1:
            menuHandler(buyCargo);
            break;
        case 2:
            menuHandler(sellCargo);
            break;
        case 3:
            menuHandler(travel);
            break;
        case 4:
            menuHandler(Exit);
            break;
        default:
            std::cout << "Please use 1 - 4" << '\n';
            printMenu();
    }
}

void Menu::printMenu() {
    std::cout << "1 - Buy Cargo\n";
    std::cout << "2 - Sell Cargo\n";
    std::cout << "3 - Travel\n";
    std::cout << "4 - Exit\n";
}