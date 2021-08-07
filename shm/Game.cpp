#include "Game.hpp"

class Map;

Game::Game(size_t money, size_t gameDays, size_t finalGoal)
    : money_(money)
    , gameDays_(gameDays)
    , finalGoal_(finalGoal)
    , menu_(std::make_unique<Menu>(this))
    , time_(new Time())
    , map_(new Map())
    , playerOne_(new Player(std::make_unique<Ship>(20, 300, 10, "Dar Pomorza", 3, time_), 1000, 1000))
    {}

Game::Game() {}

void Game::startGame()
{
    printTitle();
    setPlayer(); 
    Store* store = new Store(1000, 1000, time_);
    
    while(menu_->menuChoice() != MenuItem::Exit)
    {
        // menu_->printMenu();
        menu_->menuHandler(menu_->menuChoice(), store, map_, playerOne_);
    }
    // do {
    //     menu_->printMenu();

    //     menu_->menuHandler(menu_->menuChoice(), store, map_, playerOne_);

    // } while(menu_->menuChoice() != MenuItem::Exit);
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
    playerOne_->setName(playerName);
    std::cout << "Welcome on board captain " << playerOne_->getName() << '\n';
    map_->changeCurrentPosition(&map_->islands_.at(0));
    std::cout << "Your's ship " << playerOne_->getShip()->getName() <<  " is waiting! Good Luck!" << '\n';
    std::cout << "Yeou are in start point. Current coordinates: ";
    map_->PrintCurrentPosition();
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
    printMap(*map_);
    std::cout << "Choose Your destination captain!" << '\n';
    std::cin >> i;
    if (i < map_->islands_.size() && i >= 0)
    {
        auto travelTime = map_->calculateDistance(map_->islands_.at(i)) / playerOne_->getSpeed();
        std::cout << "Your travel will take " << travelTime << " days." << '\n';
        map_->changeCurrentPosition(&map_->islands_.at(i));
        map_->PrintCurrentPosition();
    }
    else
    {
        std::cout << "There is no such a island on the map! Choose another destination!" << '\n';
        Game::travel();
    }
}

void Game::buyAllCargo()
{

}

void Game::sellAllCargo()
{

}
// void Map::addIsland(Coordinates coordinate)
// {
//     addIsland(coordinate);
// }