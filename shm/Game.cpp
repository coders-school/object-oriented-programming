#include "Game.hpp"

#include <iostream>

constexpr size_t distancePerDay{2};

Game::Game(size_t money, size_t timeLimit, size_t finalGoal)
    : money_(money), timeLimit_(timeLimit), finalGoal_(finalGoal) {
    auto timePtr = std::make_shared<Time>();
    time_ = timePtr.get();

    auto shipPtr = std::make_shared<Ship>(100, 100, 10, "tratwa", 42, timePtr);
    auto playerPtr = std::make_shared<Player>(shipPtr, 1000);
    player_ = playerPtr.get();

    map_ = new Map();

}

bool Game::checkWinCondition() const {
    return (player_->getMoney() >= finalGoal_);
}

bool Game::checkLoseCondition() const {
    return (player_->getMoney() == 0 || time_->getElapsedTime() == timeLimit_);
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
    std::cout << *map_;
    auto destination = map_->getIsland(getTravelLocation());
    while(!destination){
        std::cout << "\nThere is no Island there. Enter valid Island location\n";
        destination = map_->getIsland(getTravelLocation());
    }

    auto distance = map_->getDistanceToIsland(destination);
    map_->setCurrentPosition(destination);
    advanceTimeTraveling(distance);
}

Coordinates Game::getTravelLocation() {
    std::cout << "Type position X of an Island to travel to: ";
    size_t X{};
    std::cin >> X;
    std::cout << "\nType position Y of an Island to travel to: ";
    size_t Y{};
    std::cin >> Y;
    std::cout << "\n";

    return Coordinates(X, Y);
}

void Game::advanceTimeTraveling(int distance) {
    while (distance > 0) {
        distance -= distancePerDay;
        time_++;
    }
}

void Game::printOptions() const {
    std::cout << "Ahoy captain! We're waiting for your commands! \n";
    std::cout << "1. Travel \n";
    std::cout << "2. Buy \n";
    std::cout << "3. Sell \n";
    std::cout << "0. Exit \n";
}

void Game::exit() const {
    printEndGameScreen();
    std::exit(0);
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

void Game::buy() {  //TODO: To be implemented

}

void Game::sell() { //TODO: To be implemented

}
