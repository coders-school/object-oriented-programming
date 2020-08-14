#include "Game.hpp"
#include "Ship.hpp"

#include <iostream>

constexpr size_t distancePerDay{2};

Game::Game(size_t money, size_t timeLimit, size_t finalGoal)
    : money_(money), timeLimit_(timeLimit), finalGoal_(finalGoal) {
    auto timePtr = std::make_shared<Time>();
    time_ = timePtr.get();

    map_ = new Map(timePtr);

    auto shipPtr = std::make_shared<Ship>(100, 100, 10, "tratwa", 42, timePtr);

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
        "######## ##     ## ########    ######## ##    ## ######## " << "\n" << 
        "   ##    ##     ## ##          ##       ###   ## ##     ##" << "\n" <<  
        "   ##    ##     ## ##          ##       ####  ## ##     ##" << "\n" <<  
        "   ##    ######### ######      ######   ## ## ## ##     ##" << "\n" << 
        "   ##    ##     ## ##          ##       ##  #### ##     ##" << "\n" << 
        "   ##    ##     ## ##          ##       ##   ### ##     ##" << "\n" << 
        "   ##    ##     ## ########    ######## ##    ## ######## " << "\n";
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
    auto currentIsland = map_->getCurrentPosition();
    std::cout << "Your current position is [ X = " 
              << currentIsland->getPosition().getX() 
              << " ; Y = "
              << currentIsland->getPosition().getY() 
              << " ]\n";
    std::cout << *map_;
        
    auto destination = map_->getIsland(getTravelLocation()); 
    while(!destination){
        printPromptInvalidDestination(); //"Hey Pirate! Are you sure these coordinates are correct?\n";
        destination = map_->getIsland(getTravelLocation());
    }

    auto distance = map_->getDistanceToIsland(destination);
    map_->setCurrentPosition(destination);
    advanceTimeTraveling(distance);

    std::cout<< "Capitan! Let's go for " << distance <<" units long trip!\n";
    getKeyPress();
}

Coordinates Game::getTravelLocation() {
    std::cout << *map_;

    std::cout << "\nType position X of an Island to travel to: ";
    size_t X{};
    std::cin >> X;
    std::cout << "Type position Y of an Island to travel to: ";
    size_t Y{};
    std::cin >> Y;

    return Coordinates(X, Y);
}

void Game::advanceTimeTraveling(int distance) {
    while (distance > 0) {
        if (distance < distancePerDay) {
            distance = 0;
        }
        else {
            distance -= distancePerDay;
        }
        time_->operator++();
    }
}

void Game::printHomeScreen() const {
    system("clear");
    auto currentIsland = map_->getCurrentPosition();

    std::cout << "Ahoy Captain! It's day " << time_->getElapsedTime() << " of our game.\n"
              << "You still have " << timeLimit_ - time_->getElapsedTime() << " days to the end.\n\n";
    std::cout << "Your resources are:\n" 
              << *player_ << "\n";
    std::cout << "Welcome on the island [ X = " 
              << currentIsland->getPosition().getX() 
              << " ; Y = "
              << currentIsland->getPosition().getY() 
              << " ]\n";
    std::cout << "On this island we have a shop with goods listed below\n" 
              << *(currentIsland->getStore()) << "\n";
              
    printOptions();
}

void Game::printOptions() const {
    std::cout << "We're waiting for your commands!\n";
    std::cout << "1. Travel \n";
    std::cout << "2. Buy \n";
    std::cout << "3. Sell \n";
    // std::cout << "4. Show my storage \n";
    std::cout << "0. Exit \n";
}

void Game::exit() const {
    printEndGameScreen();
    std::exit(0);
}

void Game::buy() {
    size_t productIndex{};
    size_t amount{};
    auto currentIslandStore = map_->getCurrentPosition()->getStore();

    std::cout << "Let's buy something\n";
    //std::cout << *currentIslandStore;
    std::cout << "Select what do you want buy, by product number: ";
    std::cin >> productIndex;
    std::cout << "What about amount you need: ";
    std::cin >> amount;
    std::cout << "\n";
   
    auto cargo = StockManagement::getCargo(currentIslandStore->getAllCargos(), productIndex);
    // TODO it would be better to call 
    // currentIslandStore.getCargo(productIndex); 
    // to achive it Store and Ship have to inherit from StockMgmt and StockMgmt should have it's Stock inside itself as protected member
    auto resp = currentIslandStore->buy(cargo, amount, player_);
    switch (resp) {
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
    std::cout << "Gimme Gimme Gimme!\n";
    //TBD
    getKeyPress();
}

void Game::showPlayerStorage() const {
    std::cout << *player_;
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
        break;
    }
}

void Game::startGame() {
    while(true) {
        if(checkLoseCondition()) {
            printLoseScreen();
            return;
        }
        else if(checkWinCondition()) {
            printWinScreen();
            return;
        }

        printHomeScreen();
        printOptions();
        makeAction(chooseAction());
    }
}

Action Game::chooseAction() {
    int action {};
    std::cout << "Your choice: ";
    std::cin >> action;
    std::cout << "\n";

    return Action(action);
}

void Game::printPromptInvalidDestination() const {
    system("clear");
    std::cout << *map_;
    std::cout << "\nThere is no Island there. Enter valid Island location\n";
}
