#include "Game.hpp"
#include "Ship.hpp"

#include <iostream>

constexpr size_t distancePerDay{2};

Game::Game(size_t money, size_t timeLimit, size_t finalGoal)
    : money_(money), timeLimit_(timeLimit), finalGoal_(finalGoal) {
    auto timePtr = std::make_shared<Time>();
    time_ = timePtr.get();

    map_ = new Map(timePtr);

    auto shipPtr = std::make_shared<Ship>(100, 100, 10, "Best Tratwa Ever", 42, timePtr);
    size_t crewAmount = 5;
    (*shipPtr) += crewAmount;

    player_ = std::make_shared<Player>(shipPtr, money_);
}

bool Game::checkWinCondition() const {
    return (player_->getMoney() >= finalGoal_);
}

bool Game::checkLoseCondition() const {
    return (player_->getMoney() == 0 || time_->getElapsedTime() >= timeLimit_);
}

void Game::getKeyPress() const {
    std::cin.get();
    do {
        std::cout << '\n' << "Press enter to continue...";
    } while (std::cin.get() != '\n');
}

void Game::printTheEnd() const {
    std::cout <<
        "######## ##     ## ########     ######## ##    ## ######## " << "\n" << 
        "   ##    ##     ## ##           ##       ###   ## ##     ##" << "\n" <<  
        "   ##    ##     ## ##           ##       ####  ## ##     ##" << "\n" <<  
        "   ##    ######### ######       ######   ## ## ## ##     ##" << "\n" << 
        "   ##    ##     ## ##           ##       ##  #### ##     ##" << "\n" << 
        "   ##    ##     ## ##           ##       ##   ### ##     ##" << "\n" << 
        "   ##    ##     ## ########     ######## ##    ## ######## " << "\n";
}

void Game::printWinScreen() const {
    system("clear");
    std::string horizontalSeparator(59, '=');
    std::cout << horizontalSeparator << "\n";
    printTheEnd();
    std::cout << horizontalSeparator << "\n"
              << std::string(4, ' ') 
              << "YOU WIN THE GAME AFTER " 
              << time_->getElapsedTime() 
              << " DAYS WITH SCORE " 
              << player_->getMoney() 
              << "\n"
              << std::string(20, ' ')
              << "CONGRATULATIONS" << "\n"
              << horizontalSeparator << "\n";
}

void Game::printLoseScreen() const {
    system("clear");
    std::string horizontalSeparator(59, '=');
    std::cout << horizontalSeparator << "\n";
    printTheEnd();
    std::cout << horizontalSeparator << "\n"
              << std::string(4, ' ') 
              << "YOU LOSE THE GAME AFTER "
              << time_->getElapsedTime()
              << " DAYS WITH SCORE " 
              << player_->getMoney() 
              << "\n"
              << std::string(25, ' ')
              << "TRY AGAIN" << "\n"
              << horizontalSeparator << "\n";
}

void Game::printEndGameScreen() const {
    system("clear");
    std::string horizontalSeparator(59, '=');
    std::cout << horizontalSeparator << "\n";
    printTheEnd();
    std::cout << horizontalSeparator << "\n"
              << std::string(4, ' ') 
              << "YOU END THE GAME AFTER " 
              << time_->getElapsedTime() 
              << " DAYS WITH SCORE " 
              << player_->getMoney() 
              << "\n"
              << std::string(20, ' ')
              << "THANKS CAPITAN!" << "\n"
              << horizontalSeparator << "\n";
}

void Game::travel() {
    system("clear");
    printCurrentPositionOnMap();        
    auto destination = map_->getIsland(getTravelLocation()); 
    while (!destination || destination->getPosition() == currentPosition_->getPosition()) {
        if (!destination) {
            printPromptInvalidDestination();
        }
        else if (destination->getPosition() == currentPosition_->getPosition()) {
            printPromptCurrentPositionEqualsDestination();
        }
        printCurrentPositionOnMap();
        destination = map_->getIsland(getTravelLocation());
    }

    auto distance = map_->getDistanceToIsland(destination);
    currentPosition_ = std::make_unique<Island>(*destination);
    map_->setCurrentPosition(currentPosition_.get());
    advanceTimeTraveling(distance);

    std::cout << "Capitan! Let's go for " << distance << " units long trip!\n";
    getKeyPress();
}

void Game::printCurrentPositionOnMap() const {
    std::cout << "Your current position is " << *currentPosition_ << "\n";
    std::cout << *map_;
}

Coordinates Game::getTravelLocation() {
    std::cout << "Type position X of an Island to travel to: ";
    size_t X{};
    std::cin >> X;
    std::cout << "Type position Y of an Island to travel to: ";
    size_t Y{};
    std::cin >> Y;

    return Coordinates(X, Y);
}

void Game::advanceTimeTraveling(size_t distance) {
    while (distance > 0) {
        distance = distance < distancePerDay ? 0 : distance - distancePerDay;
        time_->operator++();
    }
}

void Game::printHomeScreen() const {
    system("clear");

    std::cout << "Ahoy Captain! It's day " << time_->getElapsedTime() << " of our game.\n"
              << "You still have " << timeLimit_ - time_->getElapsedTime() << " days to the end.\n\n";
    std::cout << "Your resources are:\n" 
              << *player_ << "\n";
    std::cout << "Welcome on the Island " << *currentPosition_ << "\n";
    std::cout << "On this Island we have a shop with goods listed below\n" 
              << *(currentPosition_->getStore()) << "\n";
}

void Game::printOptions() const {
    std::cout << "We're waiting for your commands!\n";
    std::cout << "1. Travel \n";
    std::cout << "2. Buy \n";
    std::cout << "3. Sell \n";
    std::cout << "0. Exit \n";
}

void Game::exit() const {
    printEndGameScreen();
    std::exit(0);
}

void Game::buy() {
    size_t productIndex{};
    size_t amount{};
    auto currentIslandStore = currentPosition_->getStore();

    std::cout << "Let's buy something\n";
    std::cout << "Select what do you want buy, by product number: ";
    std::cin >> productIndex;
    auto cargo = currentIslandStore->getCargo(--productIndex);
    while (!cargo) {
        printPromptInvalidProductIndex();
        std::cin >> productIndex;
        cargo = currentIslandStore->getCargo(--productIndex);
    }
    std::cout << "What about amount you need: ";
    std::cin >> amount;
    std::cout << "\n";   
    
    auto response = (amount == 0 ) ? Response::done : currentIslandStore->buy(cargo, amount, player_);
    switch (response) {
    case Response::done:
        std::cout << "Thanks for the transaction!\n";
        break;
    case Response::lack_of_cargo:
        std::cout << "Sorry, we have not enough of selected product\n";
        break;
    case Response::lack_of_money:
        std::cout << "You don't have enough money!\n";
        break;
    case Response::lack_of_space:
        std::cout << "You don't have enough space!\n";
        break;
    default:
        std::cout << "Unknown response\n";
        break;
    }
    getKeyPress();
}

void Game::sell() {
    size_t productIndex{};
    size_t amount{};
    auto currentIslandStore = currentPosition_->getStore();

    if (player_->getShip()->isEmpty()) {
        std::cout << "You have nothing to sell\n";
        getKeyPress();
        return;
    }

    std::cout << "Let's sell something\n";
    std::cout << "If product which you want to sell is in our Store, then we use our SELL PRICE.\n";
    std::cout << "But if we don't have it, then we use your product PRICE.\n\n";
    std::cout << "Select what do you want sell, by product number: ";
    std::cin >> productIndex;
    auto cargo = player_->getShip()->getCargo(--productIndex);
    while (!cargo) {
        printPromptInvalidProductIndex();
        std::cin >> productIndex;
        cargo = player_->getShip()->getCargo(--productIndex);
    }
    std::cout << "What about amount: ";
    std::cin >> amount;
    std::cout << "\n";
        
    auto response = (amount == 0 ) ? Response::done : currentIslandStore->sell(cargo, amount, player_);
    switch (response) {
    case Response::done:
        std::cout << "Thanks for the transaction!\n";
        break;
    case Response::lack_of_cargo:
        std::cout << "Sorry, you don't have enough of selected product\n";
        break;
    default:
        std::cout << "Unknown response\n";
        break;
    }

    getKeyPress();
}

void Game::makeAction(Action choice) {
    switch (choice) {
    case Action::Exit:
        exit();
        break;
    case Action::Travel:
        travel();
        break;
    case Action::Buy:
        buy();
        break;
    case Action::Sell:
        sell();
        break;
    default:
        std::cout << "Invalid choice. Try again.\n";
        getKeyPress();
        break;
    }
}

void Game::startGame() {
    currentPosition_ = std::make_unique<Island>(*(map_->getCurrentPosition()));
    while (true) {
        if (checkLoseCondition()) {
            printLoseScreen();
            return;
        }
        else if (checkWinCondition()) {
            printWinScreen();
            return;
        }

        printHomeScreen();
        printOptions();
        makeAction(chooseAction());
    }
}

Action Game::chooseAction() {
    int action{};
    std::cout << "Your choice: ";
    std::cin >> action;
    std::cout << "\n";

    return Action(action);
}

void Game::printPromptInvalidDestination() const {
    system("clear");
    std::cout << "Hey Pirate! There is no Island there. Enter valid Island location.\n";
}

void Game::printPromptCurrentPositionEqualsDestination() const {
    system("clear");
    std::cout << "Capitan, we are already here!\n";
}

void Game::printPromptInvalidProductIndex() const {
    std::cout << "Hey Pirate! Invalid product number. Try again: ";
}
