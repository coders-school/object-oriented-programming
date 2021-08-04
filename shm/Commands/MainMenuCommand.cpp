#include "MainMenuCommand.hpp"
#include "../GeneralPrint.hpp"

void Menu::operator()(Player &player, Store &store) {
    printStoreCargoList(store);
    printShipCargoList(player);
}

std::string Menu::getName() const { 
    return "Show menu"; 
}
