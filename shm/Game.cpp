#include "Game.hpp"

class Map;

Game::Game(size_t money, size_t gameDays, size_t finalGoal)
    : time_(new Time())
    , money_(money)
    , gameDays_(gameDays)
    , finalGoal_(finalGoal)
    , map_(new Map(time_))
    , playerOne_(new Player(std::make_unique<Ship>(20, 300, 10, "Dar Pomorza", 3, time_), 1000, 1000))
    , menu_(std::make_unique<Menu>(this))
    {}

Game::Game() {}

void Game::startGame()
{
    printTitle();
    setPlayer(); 
    currentStore_ = new Store(1000, 1000, time_);   
    do{
        menu_->printMenu();
        menu_->playerChoice();   
    }while(!quitRequest);
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
    setStartingCargo();
    std::cout << "Welcome on board captain " << playerOne_->getName() << '\n';
    map_->changeCurrentPosition(&map_->islands_.at(0));
    std::cout << "Your's ship " << playerOne_->getShip()->getName() <<  " is waiting! Good Luck!" << '\n';
    std::cout << "You are in start point. ";
    map_->PrintCurrentPosition();
    std::cout << "You have " << playerOne_->getMoney() << " gold in Your treasure chest!" << '\n';
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
        time_->changeTime(travelTime);
    }
    else
    {
        std::cout << "There is no such island on the map! Choose another destination!" << '\n';
        Game::travel();
    }
}

void Game::buyAllCargo()
{
    auto storeCargo = currentStore_->storeCargo;
    for(const auto &el : storeCargo)
    {
        if(el->getAmount() > 0)
        {
            currentStore_->buy(el, el->getAmount(), playerOne_);
        }
        std::cout << "This cargo does not exist!" << '\n';
    }
}

void Game::sellAllCargo()
{
    auto playerCargo = playerOne_->getShip()->shipCargo;
    for(const auto &el : playerCargo)
    {
        currentStore_->sell(el, el->getAmount(), playerOne_);
    }
}

void Game::printPlayerCargo()
{
    playerOne_->getShip()->printShipCargo();
}

void Game::setStartingCargo()
{
    playerOne_->getShip()->shipCargo.push_back(new Fruit("Banany", 1, 20, time_, 15, 0)); 
    playerOne_->getShip()->shipCargo.push_back(new Fruit("Apple", 1, 14, time_, 20, 0));
    playerOne_->getShip()->shipCargo.push_back(new Alcohol("Rum", 1, 60, time_, 70));        
    playerOne_->getShip()->shipCargo.push_back(new Item("Hook", 1, 100, time_, Rarity::common)); 
}

void Game::quitRequested()
{
    quitRequest = true;
}

void Game::displayPlayerStats()
{
    std::cout << "(Little reminder)" << '\n';
    std::cout << "Available gold: " << playerOne_->getMoney() << '\n';
    std::cout << "Your position on the map:\n";
    map_->PrintCurrentPosition();
    std::cout << "Day " << time_->getCurrentTime() << "/" << gameDays_ << '\n';
    std::cout << "==========================\n";
}

void Game::printStoreCargo()
{
    std::cout << "This store contains: " << '\n';
    currentStore_->printStoreCargo();
}

void Game::buyCargo()
{
    int cargoElement = 0;
    size_t amount = 0;
    std::cout << "Choose cargo;";
    std::cin >> cargoElement;
    std::cout <<  "Choose amount";
    std::cin >> amount;
    
    currentStore_->buy(currentStore_->storeCargo.at(cargoElement),amount,playerOne_ );
}

void Game::sellCargo()
{
    int cargoElement = 0;
    size_t amount = 0;
    std::cout << "Choose cargo;";
    std::cin >> cargoElement;
    std::cout <<  "Choose amount";
    std::cin >> amount;

    currentStore_->sell(playerOne_->getCargo(cargoElement), amount, playerOne_);
}