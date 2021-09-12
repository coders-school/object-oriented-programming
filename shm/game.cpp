#include "game.hpp"
#include <iomanip>
#include <algorithm>
#include "map.hpp"

constexpr size_t CAPACITY = 1000;
constexpr size_t MAXCREW = 40;
constexpr size_t CREW = 10;
constexpr size_t SPEED = 20;
constexpr char NAME[] = "Black Widow";
constexpr size_t ID = 1;

Game::Game(size_t money, size_t days, size_t goal)
    : money_(money),
      gameDayes_(days),
      finalGoal_(goal),
      time_(std::make_shared<Time>()),
      map_(Map(time_)),
      ship_(std::make_shared<Ship>(CAPACITY, MAXCREW, CREW, SPEED, NAME, ID, time_)), // <--- Segmentation fault
      player_(std::make_shared<Player>(ship_, money)){};

Game::~Game(){};

void Game::startGame()
{
    ///// PROBLEM WITH ALCOHOL IN CARGO (VECTOR OF CARGO ALWAYS EMPTY) AND WITH LIST OF OBSERVER (ALSO EMPTY AFTER CONSTRUCTING EVERYTHING)///
    std::cout << "I co może nagle działa: " << time_->getList().size() << std::endl;
    printHeader();
    //printMenu();
    ship_->setOwner(player_);
    size_t option;

    //  std::cin >> option;

    while (true)
    {
        if (checkWinCondition())
        {
            printWinScreen();
            exit();
        }
        else if (checkLoseCondition())
        {
            break;
        }
        printMenu();
        std::cout << "Write your choice: ";
        size_t choice;

        std::cin.clear();
        std::cin >> choice;

        chooseOption(static_cast<MenuOption>(choice));
    }
    printLoseScreen();
    exit();
}

void Game::printMenu()
{
    std::cout << "/" << std::setfill(' ') << std::setw(40) << "Your money: " << player_->getMoney() << std::setw(40) << "Days gone: " << time_->getDays() << std::endl;
    std::cout << "/" << std::setfill('-') << std::setw(100) << "/\n";
    std::cout << "*" << std::setfill(' ') << std::setw(58) << " CHOOSE ACTION: " << std::setw(42) << "/\n";
    std::cout << "/" << std::setfill('-') << std::setw(100) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(100) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(55) << " 1. TRAVEL: " << std::setw(45) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(60) << " 2. PRINT CARGO: " << std::setw(40) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(52) << " 3. BUY: " << std::setw(48) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(53) << " 4. SELL: " << std::setw(47) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(59) << " 5. WHERE AM I: " << std::setw(41) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(53) << " 6. EXIT: " << std::setw(47) << "/\n";
    std::cout << "/" << std::setfill('-') << std::setw(100) << "/\n";
}

void Game::printHeader()
{
    std::cout << "/" << std::setfill('-') << std::setw(100) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(100) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(62) << "Welcome to the game SHM" << std::setw(38) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(100) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(55) << "YOUR MONEY: " << std::setw(4) << money_ << std::setw(41) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(54) << "YOUR GOAL: " << std::setw(5) << finalGoal_ << std::setw(41) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(54) << "TIME LEFT: " << std::setw(5) << gameDayes_ << std::setw(41) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(100) << "/\n";
    std::cout << "/" << std::setfill('-') << std::setw(100) << "/\n";
}

void Game::printWinScreen()
{
    std::cout << "/" << std::setfill('-') << std::setw(100) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(100) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(60) << "CONGRATULATION!!!!" << std::setw(40) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(100) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(55) << "YOU WIN!!" << std::setw(45) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(100) << "/\n";
    std::cout << "/" << std::setfill('-') << std::setw(100) << "/\n";
}

void Game::printLoseScreen()
{
    std::cout << "/" << std::setfill('-') << std::setw(100) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(100) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(60) << "YOU HAVE LOST!!!!" << std::setw(40) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(100) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(55) << "SORRY!!!" << std::setw(45) << "/\n";
    std::cout << "/" << std::setfill(' ') << std::setw(100) << "/\n";
    std::cout << "/" << std::setfill('-') << std::setw(100) << "/\n";
}

bool Game::checkWinCondition()
{
    if (player_->getMoney() >= finalGoal_)
    {
        return true;
    }
    return false;
}

bool Game::checkLoseCondition()
{
    return player_->getMoney() == 0 || (time_->getDays() >= gameDayes_ && player_->getMoney() < finalGoal_);
}

void Game::chooseOption(Game::MenuOption option)
{
    switch (option)
    {
    case MenuOption::Travel:
        travel();
        break;
    case MenuOption::PrintCargo:
        printCargo();
        break;
    case MenuOption::Buy:
        buy();
        break;
    case MenuOption::Sell:
        sell();
        break;
    case MenuOption::Position:
        printMap(player_);
        break;
    case MenuOption::Exit:
        exit();
        break;
    default:
        std::cout << "Try again\n";
        break;
    }
}

void Game::exit()
{
    std::exit(0);
}

void Game::sell()
{   
    std::cout << "your are selling\n";
    if (!map_.getIsland(player_->getPlayerPosition())) {
        std::cout << "Captain, we are on the sea, you can not sell enything!\n";
        return;
    }
    if (player_->getAvailableSpace() == CAPACITY) {
        std::cout << "Captain, we have nothing to sell!\n";
        return;
    }
    std::cout << "What you want to sell?" << std::endl;
    player_->printCargo();
    int sellOption = 0;
    std::cin >> sellOption;
    while (ship_->getCargosVector().size() < sellOption) {
        std::cout << "We do not own this place, you have to change your decision, Captain!\n";
        std::cin >> sellOption;
    }
    int amountOfCargoToSell = 0;
    std::cin >> amountOfCargoToSell;
    auto objectToSell = ship_->getCargosVector()[sellOption - 1];
    while (objectToSell->getAmount() < amountOfCargoToSell) {
        std::cout << "Captain, we don't have so many of " << objectToSell->getName() << " What we do now?\n1. Change amount\n2. Exit" << std::endl;
        std::cin >> sellOption;
        if (sellOption == 1) {
            std::cin >> amountOfCargoToSell;
        } else {
            return;
        }
    }
    ship_->unload(objectToSell, amountOfCargoToSell);
    player_->setMoney(player_->getMoney() + objectToSell->getBasePrice() * amountOfCargoToSell);
    map_.getIsland(player_->getPlayerPosition())->getStore()->addCargo(objectToSell, amountOfCargoToSell);
}

void Game::printMap(const std::shared_ptr<Player> player)
{
    //Segmentation fault -->//auto currentIsland = map_.getIsland((*std::find_if(map_.getEveryIsland().begin(), map_.getEveryIsland().end(), [&player](const auto& island){ return island.getPosition() == player.getPlayerPosition(); })).getPosition());
    int currentIsland = 0;
    for (auto island : map_.getEveryIsland())
    {
        currentIsland++;
        if (island.getPosition() == player_->getPlayerPosition())
        {
            std::cout << "We are on Island " << currentIsland << std::endl;
            return;
        }
    }
    std::cout << "We are on the sea!" << std::endl;
}

void Game::travel()
{
    std::cout << "Where you want to travel?" << std::endl;
    int islandCounter = 0;
    std::vector<int> daysToGo;
    daysToGo.reserve(map_.getEveryIsland().size());
    for (auto island : map_.getEveryIsland())
    {
        int amountOfDays = island.getPosition().distance(player_->getPlayerPosition()) / ship_->getSpeed();
        if (amountOfDays == 0 && !(island.getPosition() == player_->getPlayerPosition()))
        {
            daysToGo.push_back(1);
        }
        else
        {
            daysToGo.push_back(amountOfDays);
        }
        islandCounter++;
        std::cout << "Island " << islandCounter << " Travel time: " << daysToGo[islandCounter - 1] << " days" << std::endl;
    }
    std::cout << "Where are we going captain?: ";
    islandCounter = 0;
    std::cin >> islandCounter; //Zabezpieczenie przed wpisywaniem większej artości od ilości wyspy, do zrobienia
    while (islandCounter > map_.getEveryIsland().size()) {
        std::cout << "Captain you have old map! Here is new one, so where we are going?: " << std::endl;
        std::cin >> islandCounter;
    }
    player_->setPlayerPosition(map_.getEveryIsland()[islandCounter - 1].getPosition().getPositionX(), map_.getEveryIsland()[islandCounter - 1].getPosition().getPositionY());
    for (int i = 0; i < daysToGo[islandCounter - 1]; i++)
    {
        // time_.onTimeChange();
        ship_->getTime()->onTimeChange();
    }
    // std::cout << "Player X: " << player_.getPlayerPosition().getPositionX() << std::endl;
    // std::cout << "Player Y: " << player_.getPlayerPosition().getPositionY() << std::endl;
}

void Game::buy()
{
    auto IslandWeAreOn = map_.getIsland(player_->getPlayerPosition());
    if (IslandWeAreOn)
    {
        std::cout << "Buy. Remember that buying will take one day!" << std::endl;
        std::cout << *IslandWeAreOn->getStore() << std::endl;
        std::cout << "What do you want to buy: " << std::endl;
        int storeIndex = 0;
        std::cin >> storeIndex;
        while (storeIndex > IslandWeAreOn->getStore()->getCargoOfStore().size())
        {
            std::cout << "Too much rum, captain?  Choose one more time: ";
            std::cin >> storeIndex;
        }
        auto CargoWeAreBuying = IslandWeAreOn->getStore()->getCargoOfStore()[storeIndex - 1];
        size_t amountOfCargo = CargoWeAreBuying->getAmount();
        std::cout << "Amount (from 1 to " << amountOfCargo << "): " << std::endl;
        int amountOfCargoToBuy = 0;
        std::cin >> amountOfCargoToBuy;
        if (amountOfCargoToBuy > amountOfCargo)
        {
            std::cout << "Captain, they didn't have " << amountOfCargoToBuy << " of " << CargoWeAreBuying->getName() << ". We bought only " << amountOfCargo << std::endl;
            amountOfCargoToBuy = amountOfCargo;
        }
        int choose = 0;
        if (CargoWeAreBuying->getPrice() * static_cast<size_t>(amountOfCargoToBuy) > player_->getMoney())
        {
            std::cout << "Captain, we does not have enough money! We can only buy " << player_->getMoney() / CargoWeAreBuying->getPrice() << " of " << CargoWeAreBuying->getName();
            std::cout << ". What we do now? \n1. Buy other amount of " << CargoWeAreBuying->getName() << "\n2. Exit\n";
            
            std::cin >> choose;
            if (choose == 1)
            {
                std::cout << "Amount (from 1 to " << player_->getMoney() / CargoWeAreBuying->getPrice() << "): " << std::endl;
                std::cin >> amountOfCargoToBuy;
            }
            else
            {
                return;
            }
        }
        while (player_->getAvailableSpace() - amountOfCargoToBuy < 0) {
            std::cout << "Captain, our cargo is full, we can only buy " << player_->getAvailableSpace() << " of " << CargoWeAreBuying->getName() << ". What we are doing now?\n";
            std::cout << "1. Set otehr value\n2. Exit\n";
            std::cin >> choose;
            if (choose == 1) {
                std::cout << "New value: \n";
                std::cin >> amountOfCargoToBuy;
            } else {
                return;
            }
        }
        IslandWeAreOn->getStore()->loadShip(CargoWeAreBuying, amountOfCargoToBuy);
        ship_->load(CargoWeAreBuying, amountOfCargoToBuy);
        player_->setMoney(player_->getMoney() - CargoWeAreBuying->getPrice() * static_cast<size_t>(amountOfCargoToBuy) < 0 ? 0 : player_->getMoney() - CargoWeAreBuying->getPrice() * static_cast<size_t>(amountOfCargoToBuy));
        std::cout << player_->getMoney() << std::endl;
        player_->countAvailableSpace();
        time_->onTimeChange();
    }
    else
    {
        std::cout << "Captain, we are not on any island!" << std::endl;
    }
}

void Game::printCargo()
{
    std::cout << "Chuj, dupa i kamienia kupa\n";
    player_->printCargo();
    std::cin.get();
}

// void Game::setPlayer() {
//     std::cout << "Set ship name!";
//     std::string shipName;
//     std::cin >> shipName;
//     ship_->setName(shipName);
// }