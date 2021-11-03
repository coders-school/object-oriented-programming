#include <limits>
#include "Menu.hpp"
#include "Game.hpp"

Menu::Menu(Game* game)
    : game_(game)
{}

Menu::~Menu() {}

void Menu::playerChoice()
{
    size_t option{};
    do {
        std::cin >> option;
    } while (!isPlayerChoiceValid(option));
    item_ = static_cast<MenuItem>(option);
    menuChoice(item_);
}

bool Menu::isPlayerChoiceValid(const size_t& playerAnswer) const
{
    if (std::cin.fail() || playerAnswer > 5)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wrong answer, please use numbers 0 - 5" << '\n';
        return false;
    }
    return true;
}

void Menu::menuChoice(MenuItem item) const
{
    switch (item)
    {
    case MenuItem::printPlayerCargo:
        game_->printPlayerCargo();
        break;
    case MenuItem::printStoreCargo:
        game_->printStoreCargo();
        break;
    case MenuItem::buyCargo:
        game_->printStoreCargo();
        game_->buyCargo();
        break;
    case MenuItem::sellCargo:
        game_->printPlayerCargo();
        game_->sellCargo();
        break;
    case MenuItem::travel:
        game_->travel();
        break;
    case MenuItem::Exit:
        game_->quitRequested();
        break;
    default:
        std::cout << "Undefined choice" << '\n';
        break;
    }
}

void Menu::printMenu() const
{
    std::cout << "What is your choice capt'n? " << '\n';
    std::cout << "==========================\n";
    std::cout << "0 - Print Cargo\n";
    std::cout << "1 - Print Store Cargo\n";
    std::cout << "2 - Buy Cargo\n";
    std::cout << "3 - Sell Cargo\n";
    std::cout << "4 - Travel\n";
    std::cout << "5 - Exit\n";
    std::cout << "==========================\n";
    game_->displayPlayerStats();
}
