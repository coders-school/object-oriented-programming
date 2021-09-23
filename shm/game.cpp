#include "game.hpp"

#include <algorithm>
#include <cctype>
#include <iomanip>
#include <random>

#include "map.hpp"

template <typename inCheck>
void inStreamCheck(inCheck& val) {
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Bad Input! Try once again!\n";
        std::cin >> val;
    }
}
namespace {
    constexpr size_t CAPACITY = 1000;
    constexpr size_t MAXCREW = 40;
    constexpr size_t CREW = 10;
    constexpr size_t SPEED = 10;
    constexpr char NAME[] = "Black Widow";
    constexpr size_t ID = 1;
}

Game::Game(size_t money, size_t days, size_t goal)
    : money_(money),
      gameDayes_(days),
      finalGoal_(goal),
      time_(std::make_shared<Time>()),
      map_(Map(time_)),
      ship_(std::make_shared<Ship>(CAPACITY, MAXCREW, CREW, SPEED, NAME, ID, time_)),
      player_(std::make_shared<Player>(ship_, money)){};

Game::~Game(){};

void Game::startGame()
{
    printHeader();
    ship_->setOwner(player_);
    size_t option;
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
        std::cout.flush();
        printMenu();
        std::cout << "Write your choice: ";
        size_t choice;

        std::cin.clear();
        std::cin >> choice;
        inStreamCheck(choice);

        chooseOption(static_cast<MenuOption>(choice));
    }
    printLoseScreen();
    exit();
}

void Game::printMenu()
{
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "Your money: " << player_->getMoney() << "Days left: " << gameDayes_ - time_->getDays() << "\n";
    std::cout << " CHOOSE ACTION: \n";
    std::cout << '\n';
    std::cout << '\n';
    std::cout << " 1. TRAVEL: \n";
    std::cout << " 2. PRINT CARGO: \n";
    std::cout << " 3. BUY: \n";
    std::cout << " 4. SELL:\n";
    std::cout << " 5. WHERE AM I:\n";
    std::cout << " 6. EXIT:\n";
    std::cout << '\n';
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

void Game::sell() {
    if(!onIslandCheck(player_->getPlayerPosition())) {
        std::cout << "Captain, we are on the sea, you can not sell enything!\n";
        return;
    }
    const auto& vectorOfCargos = player_->getShip()->getCargosVector();
    if (vectorOfCargos.empty()) {
        std::cout << "You have nothing to sell!\n";
        return;
    }
    std::cout << "Your are selling. Remember that selling will take one day!\n";
    const auto& actualStore = map_.getIsland(player_->getPlayerPosition())->getStore();
    std::cout << "Cargo store and prices:\n" << *actualStore << "\nYour cargo to sell:\n";
    player_->printCargo();
    int choose = 0;
    std::cin >> choose;
    inStreamCheck(choose);
    while (choose > vectorOfCargos.size()) {
        std::cout << "Segmentation fault captain! Choose one more time:\n";
        std::cin >> choose;
        inStreamCheck(choose);
    }
    const auto& cargoToSell = player_->getShip()->getCargo(choose - 1);
    std::cout << "How much you want to sell?";
    int amount = 0;
    std::cin >> amount;
    inStreamCheck(amount);
    if (amount > cargoToSell->getAmount()) {
        std::cout << "We didn't have " << amount << " of " << cargoToSell->getName() << ". We sold only " << cargoToSell->getAmount() << '\n';
        amount = cargoToSell->getAmount(); 
    }
    responsesFromStore(actualStore->buy(cargoToSell, amount, player_.get()));
}

/*void Game::sell()
{
    std::cout << "Your are selling. Remember that selling will take one day!\n";
    if (!map_.getIsland(player_->getPlayerPosition()))
    {
        std::cout << "Captain, we are on the sea, you can not sell enything!\n";
        return;
    }
    if (player_->getAvailableSpace() == CAPACITY)
    {
        std::cout << "Captain, we have nothing to sell!\n";
        return;
    }
    std::cout << "What you want to sell?" << '\n';
    player_->printCargo();
    std::cout << "At store prices: \n";
    const auto &actualStoreVector = map_.getIsland(player_->getPlayerPosition())->getStore()->getCargoOfStore();
    std::vector<std::shared_ptr<Cargo>>::const_iterator atStore;
    for (auto object : ship_->getCargosVector())
    {
        atStore = std::find_if(actualStoreVector.begin(), actualStoreVector.end(), [&object](const auto &atStore)
                               { return object->getName() == atStore->getName(); });
        if (atStore != actualStoreVector.end())
        {
            std::cout << "Name: " << (*atStore)->getName() << ", Price: " << (*atStore)->getPrice() << '\n';
        }
    }
    std::cout << ship_->getCargosVector().size() + 1 << " Exit\n";
    int sellOption = 0;
    std::cin >> sellOption;
    inStreamCheck(sellOption);
    while (ship_->getCargosVector().size() < sellOption)
    {
        if (sellOption == ship_->getCargosVector().size() + 1)
        {
            std::cout << "Enough trade for today.\n";
            return;
        }
        std::cout << "Segmentation fault Captain, you have to change your decision!\n";
        std::cin >> sellOption;
        inStreamCheck(sellOption);
    }
    auto objectToSell = ship_->getCargosVector()[sellOption - 1];
    std::cout << "Amount of " << objectToSell->getName() << " to sell:\n";
    int amountOfCargoToSell = 0;
    std::cin >> amountOfCargoToSell;
    inStreamCheck(amountOfCargoToSell);
    while (objectToSell->getAmount() < amountOfCargoToSell)
    {
        std::cout << "Captain, we don't have so many of " << objectToSell->getName() << " What we do now?\n1. Change amount\n2. Exit" << '\n';
        std::cin >> sellOption;
        if (sellOption == 1)
        {
            std::cout << "Amount of " << objectToSell->getName() << " to sell:\n";
            std::cin >> amountOfCargoToSell;
            inStreamCheck(amountOfCargoToSell);
        }
        else
        {
            return;
        }
    }
    atStore = std::find_if(actualStoreVector.begin(), actualStoreVector.end(), [&objectToSell](const auto &atStore)
                           { return objectToSell->getName() == atStore->getName(); });
    ship_->unload(objectToSell, amountOfCargoToSell);
    player_->setMoney(player_->getMoney() + (*atStore)->getPrice() * amountOfCargoToSell);
    map_.getIsland(player_->getPlayerPosition())->getStore()->addCargo(objectToSell, amountOfCargoToSell);
    time_->onTimeChange();
}*/

void Game::printMap(const std::shared_ptr<Player> player)
{
    int currentIsland = 0;
    for (auto island : map_.getEveryIsland())
    {
        currentIsland++;
        if (island.getPosition() == player_->getPlayerPosition())
        {
            std::cout << "We are on Island " << currentIsland << '\n';
            return;
        }
    }
    std::cout << "We are on the sea!" << '\n';
}

void Game::travel()
{
    std::cout << "Where you want to travel?\n";
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
        std::cout << "Island " << islandCounter << " Travel time: " << daysToGo[islandCounter - 1] << " days\n";
    }
    std::cout << ++islandCounter << ". Exit\n";
    std::cout << "Where are we going captain?: ";
    islandCounter = 0;
    std::cin.clear();
    std::cin >> islandCounter;
    inStreamCheck(islandCounter);
    while (islandCounter > map_.getEveryIsland().size() + 1)
    {
        std::cout << "Captain you have old map! Here is new one, so where we are going?: \n";
        std::cin.clear();
        std::cin >> islandCounter;
        inStreamCheck(islandCounter);
    }
    if (islandCounter == map_.getEveryIsland().size() + 1)
    {
        std::cout << "I changed my mind, we stay here!\n";
        return;
    }
    player_->setPlayerPosition(map_.getEveryIsland()[islandCounter - 1].getPosition().getPositionX(), map_.getEveryIsland()[islandCounter - 1].getPosition().getPositionY());
    travel(daysToGo[islandCounter - 1]);
}

void Game::buy() {
    const auto& IslandWeAreOn = map_.getIsland(player_->getPlayerPosition());
    if (IslandWeAreOn) {
        std::cout << *IslandWeAreOn->getStore() << '\n';
        int choose = 0;
        std::cin >> choose;
        inStreamCheck(choose);
        const auto& cargoOfStore = IslandWeAreOn->getStore()->getCargoOfStore();
        while (cargoOfStore.size() + 1 < choose) {
            std::cout << "Wrong choice captain! Try once again!\n";
            std::cin >> choose;
            inStreamCheck(choose);
        }
        if (choose == cargoOfStore.size() + 1) {
            return;
        }
        std::cout << "Amount: ";
        size_t amount = 0;
        std::cin >> amount;
        inStreamCheck(amount);
        const auto& object = cargoOfStore[choose - 1];
        if (object->getAmount() < amount) {
            std::cout << "We bought only " << object->getAmount() << " of " << object->getName() << '\n';
        }
        responsesFromStore(IslandWeAreOn->getStore()->sell(object, amount, player_.get()));
    } else {
        std::cout << "We are on the sea!";
        return;
    }
}


/*void Game::buy()
{
    auto IslandWeAreOn = map_.getIsland(player_->getPlayerPosition());
    if (IslandWeAreOn)
    {
        std::cout << "Buy. Remember that buying will take one day!\n";
        std::cout.flush();
        std::cout << *IslandWeAreOn->getStore() << '\n';
        std::random_device rm;
        std::mt19937 gr(rm());
        int EasterEggPossibilities = 20;
        std::uniform_int_distribution<> EasterEgg(0, EasterEggPossibilities);
        int whahappen = EasterEgg(gr);
        if (whahappen == 10)
        {
            std::cout << IslandWeAreOn->getStore()->getCargoOfStore().size() + 2 << ". Maybe round of Gwent?\n";
        }
        std::cout << "What do you want to buy: \n";
        int storeIndex = 0;
        std::cin >> storeIndex;
        inStreamCheck(storeIndex);
        while (storeIndex > IslandWeAreOn->getStore()->getCargoOfStore().size())
        {
            if (storeIndex == IslandWeAreOn->getStore()->getCargoOfStore().size() + 1)
            {
                std::cout << "Get back on the ship, you scums!\n";
                return;
            }
            if (whahappen == 10 && storeIndex == IslandWeAreOn->getStore()->getCargoOfStore().size() + 2)
            {
                std::cout << "Winds howling... (O'Dimm theme starts playing...)\n";
                return;
            }
            std::cout << "Too much rum, captain?  Choose one more time: ";
            std::cin.clear();
            std::cin >> storeIndex;
            inStreamCheck(storeIndex);
        }
        auto CargoWeAreBuying = IslandWeAreOn->getStore()->getCargoOfStore()[storeIndex - 1];
        size_t amountOfCargo = CargoWeAreBuying->getAmount();
        std::cout << "Amount (from 1 to " << amountOfCargo << "): \n";
        int amountOfCargoToBuy = 0;
        std::cin.clear();
        std::cin >> amountOfCargoToBuy;
        inStreamCheck(amountOfCargoToBuy);
        if (amountOfCargoToBuy > amountOfCargo)
        {
            std::cout << "Captain, they didn't have " << amountOfCargoToBuy << " of " << CargoWeAreBuying->getName() << ". We bought only " << amountOfCargo << "\n";
            amountOfCargoToBuy = amountOfCargo;
        }
        int choose = 0;
        if (CargoWeAreBuying->getPrice() * static_cast<size_t>(amountOfCargoToBuy) > player_->getMoney())
        {
            std::cout << "Captain, we do not have enough money! We can only buy " << player_->getMoney() / CargoWeAreBuying->getPrice() << " of " << CargoWeAreBuying->getName();
            std::cout << ". What we do now? \n1. Buy other amount of " << CargoWeAreBuying->getName() << "\n2. Exit\n";
            std::cin.clear();
            std::cin >> choose;
            inStreamCheck(choose);
            if (choose == 1)
            {
                std::cout << "Amount (from 1 to " << player_->getMoney() / CargoWeAreBuying->getPrice() << "): \n";
                std::cin.clear();
                std::cin >> amountOfCargoToBuy;
                inStreamCheck(amountOfCargoToBuy);
            }
            else
            {
                return;
            }
        }
        while (player_->getAvailableSpace() - amountOfCargoToBuy < 0)
        {
            std::cout << "Captain, our cargo is full, we can only buy " << player_->getAvailableSpace() << " of " << CargoWeAreBuying->getName() << ". What we are doing now?\n";
            std::cout << "1. Set other value\n2. Exit\n";
            std::cin.clear();
            std::cin >> choose;
            inStreamCheck(choose);
            if (choose == 1)
            {
                std::cout << "New value: \n";
                std::cin.clear();
                std::cin >> amountOfCargoToBuy;
            }
            else
            {
                return;
            }
        }
        ship_->load(CargoWeAreBuying, amountOfCargoToBuy);
        IslandWeAreOn->getStore()->loadShip(CargoWeAreBuying, amountOfCargoToBuy);
        player_->setMoney(player_->getMoney() - CargoWeAreBuying->getPrice() * static_cast<size_t>(amountOfCargoToBuy) < 0 ? 0 : player_->getMoney() - CargoWeAreBuying->getPrice() * static_cast<size_t>(amountOfCargoToBuy));
        std::cout << player_->getMoney() << '\n';
        player_->countAvailableSpace();
        time_->onTimeChange();
    }
    else
    {
        std::cout << "Captain, we are not on any island!\n";
    }
}*/

void Game::printCargo()
{
    player_->printCargo();
    std::cin.get();
}

void Game::travel(int days) {
    while (days--) {
        time_->onTimeChange();
    }
}

bool Game::onIslandCheck(const Coordinates& coords) {
    return map_.getIsland(coords);
}

void responsesFromStore(const Response& res) {
    switch(res) {
        case Response::lack_of_cargo :
            std::cout << "There is problem with cargo captain!\n";
            break;
        case Response::lack_of_money :
            std::cout << "We have no money captain! \n";
            break;
        case Response::lack_of_space :
            std::cout << "We dont have enough space captain!\n";
            break;
        case Response::done :
            std::cout << "Everything went well!\n";
        break;
    };
}
