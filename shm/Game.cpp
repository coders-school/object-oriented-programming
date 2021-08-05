#include "Game.hpp"

class Map;
Time *time_ptr = new Time();
Player playerOne(std::make_unique<Ship>(20, 300, 2, "Uboot", 3, time_ptr), 1000, 1000);
Map map1;

Game::Game(size_t money, size_t gameDays, size_t finalGoal)
    : money_(money)
    , gameDays_(gameDays)
    , finalGoal_(finalGoal)
    , menu_(std::make_unique<Menu>())
    , time_(new Time())
    , map_(new Map())
    {}

Game::Game() {}

void Game::startGame()
{
    printTitle();
    setPlayer(); 
    Store* store = new Store(1000, 1000, time_);
    do {
        menu_->printMenu();

        menu_->menuHandler(menu_->menuChoice(), store, map_, playerOne_);
        
    } while(menu_->menuChoice() == 4);
}

void Game::printTitle()
{
    std::cout << "Project SHM" << '\n';
}

void Game::setPlayer()
{

    std::cout << "Set your name captain!:" << '\n';
    std::string playerName;
    std::cin >> playerName;
    std::cout << "Welcome on board captain " << playerName << '\n';
    Player playerOne (std::make_unique<Ship>(20, 300, 2, "Uboot", 3, time_), 1000, 1000);
    mapa.changeCurrentPos(&map_->islands_.at(0));
    std::cout << "Your's ship Uboot is waiting! Good Luck!" << '\n';
    std::cout << "Yeou are in start point. Current coordinates: ";
    map1.PrintCurrentPosition();
    std::cout << "Choose Your next move!" << '\n';

    printMap(*map_);
    playerOne_= &playerOne;
}

void Game::printMap(Map &map)
{
    map.PrintCurrentPosition();
    map.DebugPrintIsland();
}

void Game::travel()
{
    auto i = 0;
    printMap(map1);
    std::cout << "Choose Your destination captain!" << '\n';
    std::cin >> i;
    if (i < map1.islands_.size() && i >= 0)
    {
        auto travelTime = map1.calculateDistance(map1.islands_.at(i)) / playerOne.getSpeed();
        std::cout << "Your travel will take " << travelTime << " days." << '\n';
        map1.changeCurrentPosition(&map1.islands_.at(i));
        map1.PrintCurrentPosition();
    }
    else
    {
        std::cout << "There is no such a island on the map! Choose another destination!" << '\n';
        Game::travel();
    }
}

// void Map::addIsland(Coordinates coordinate)
// {
//     addIsland(coordinate);
// }