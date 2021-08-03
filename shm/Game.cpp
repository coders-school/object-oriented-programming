#include "Game.hpp"


class Map;

Map mapa;

Game::Game(size_t money, size_t gameDays, size_t finalGoal)
    : money_(money)
    , gameDays_(gameDays)
    , finalGoal_(finalGoal)
    , menu_(std::make_unique<Menu>())
    {}

Game::Game() {}

void Game::startGame()
{
    printTitle();
    setPlayer(); 
    menu_->printMenu();
    menu_->menuChoice();
}

void Game::printTitle()
{
    std::cout << "Project SHM" << '\n';
}

void Game::setPlayer()
{
    Time *time_ptr = new Time();
    
    std::cout << "Set your name captain!:" << '\n';
    std::string playerName;
    std::cin >> playerName;
    std::cout << "Welcome on board captain " << playerName << '\n';
    Player playerOne (std::make_unique<Ship>(20, 300, 2, "Uboot", 3, time_ptr), 1000, 1000);
    mapa.changeCurrentPos(&mapa.islands_.at(0));
    std::cout << "Your's ship Uboot is waiting! Good Luck!" << '\n';
    std::cout << "Yeou are in start point. Current coordinates: ";
    mapa.PrintCurrentPosition();
    std::cout << "Choose Your next move!" << '\n';
}

void Game::printMap(Map &map)
{   
    map.PrintCurrentPosition();
    map.DebugPrintIsland();
}

void Game::travel()
{
    auto i = 0;
    printMap(mapa);
    std::cout << "Choose Your destination captain!" << '\n';
    std::cin >> i;
    mapa.getIsland(&mapa.islands_.at(i));
    //TODO add travel to menu
    //TODO add travel time by using pitagoras trójkąt

}

// void Map::addIsland(Coordinates coordinate)
// {
//     addIsland(coordinate);
// }