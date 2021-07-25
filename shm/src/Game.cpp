#include "shm/inc/Game.hpp"

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <memory>

#include "shm/inc/Island.hpp"

namespace {
    constexpr size_t DISTANCE_MULTIPLIER{ 10 };
    constexpr size_t FIRST_OPTION_ELEMENT{ 1 };
    constexpr size_t LAST_OPTION_ELEMENT{ 7 };
}

Game::Game(size_t money, size_t gameDays, size_t finalGoal)
    : money_(money)
    , gameDays_(gameDays)
    , finalGoal_(finalGoal)  
    , time_(std::make_shared<Time>())
    , map_(std::make_shared<Map>(time_.get()))
    , player_(std::make_unique<Player>(std::make_unique<Ship>(1, 25, 100, time_.get(), nullptr),
                                       map_, 100, 10000, time_.get()))
{                                       
    islandMax_  = map_->getIslands().size();
}

void Game::startGame() {
    printWelcomeScreen();
    while (isGameWon() == false && isGameLost() == false) {
        if (selectOption() == MenuOption::Exit) {
            break;
        }
    }
}

bool Game::isGameWon() {
    if (player_->getMoney() >= finalGoal_) {
        printWinScreen();
        return true;
    }
    return false;
}

void Game::printWinScreen() {
    announcementGenerate("CONGRATULATION YOU WIN");
}

void Game::printLoseScreen() {
    announcementGenerate("UNFORTUNATELY YOU LOST");
}

void Game::printWelcomeScreen() {
    announcementGenerate("WELCOME TO TRADE SHIP SIMULATOR 1.0.0.0 ");
}

void Game::announcementGenerate(const std::string & announcenent) {
    size_t frameSize { 99 };
    size_t frameLine { 1 };
    size_t announcementEndPosition = frameSize / 2 - announcenent.size() / 2 + announcenent.size();
    std::cout << std::setfill('#') << std::setw (frameSize ) << "\n"
          << '#' << std::setfill(' ') << std::setw (frameSize - frameLine) << "#\n"
          << '#' << std::setw (announcementEndPosition) << announcenent 
          << std::setw (frameSize - announcementEndPosition - frameLine) << "#\n"
          << '#' << std::setw (frameSize - frameLine) << "#\n"
          << std::setfill('#') << std::setw (frameSize) << "\n";
    std::cin.get();
}

bool Game::isGameLost() {
    if (player_->getMoney() == 0 || (gameDays_ - time_->getElapsedTime()) == 0) {
        printLoseScreen();
        return true;
    }
    return false;
}

void Game::printMenu() {
    std::cout << "#" << std::setfill('-')  << std::setw (98) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (56) << " CHOOSE ACTION: " << std::setw (42) << "#\n";
    std::cout << "#" << std::setfill('-')  << std::setw (98) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (98) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (53) << " 1. SHOW MAP " << std::setw (45) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (51) << " 2. TRAVEL " << std::setw (47) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (56) << " 3. PRINT CARGO " << std::setw (42) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (48) << " 4. BUY " << std::setw (50) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (48) << " 5. SELL" << std::setw (50) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (53) << " 6. HIRE CREW" << std::setw (45) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (48) << " 7. EXIT" << std::setw (50) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (98) << "#\n";
    std::cout << "#" << std::setfill('-')  << std::setw (99) << "#\n\n";
}

void Game::printHeader() {
    std::cout << std::setw (99) << std::setfill('#') << "\n";
    std::cout << "#" << std::setfill(' ') << std::setw (97) << "#" << "\n";
    std::cout << "#" << std::setfill(' ') << std::setw (15) << "YOUR MONEY: " << std::setw (8) << std::setfill('0') << money_;
    std::cout << std::setfill(' ') << std::setw (30) << "YOUR GOAL: " << std::setw (8) << std::setfill('0') << finalGoal_;
    std::cout << std::setfill(' ') << std::setw (30) << "DAYS LEFT: " << std::setw (3) << std::setfill('0') 
              << gameDays_ - currentDay_ << std::setfill(' ') << std::setw (4) << "#" "\n";
    std::cout << "#" << std::setfill(' ') << std::setw (97) << "#" << "\n";
    std::cout << std::setw (99) << std::setfill('#') << "\n";
}

void Game::printMap() {
    size_t islandNo_ {};
    for (const auto& island : map_->getIslands()) {
        std::cout << "Island no " << ++islandNo_  
                  << " ---- Coordinates [" << island.getCoordinates().getPositionX() 
                  << "][" << island.getCoordinates().getPositionY() << "]\n";
    }
    std::cout << "\nPress the button to continue\n";
    std::cin.clear();
    std::cin.ignore(100, '\n');
    std::getchar();
}

Game::MenuOption Game::selectOption() {
    printHeader();
    printMenu();
    size_t option {};
    do {
        std::cout << "Please insert you choice: ";
        std::cin >> option;
    } while (!isChoiceValid(option));
    menuOption_ = static_cast<MenuOption>(option);
    return actionMenu(menuOption_);
}

Game::MenuOption Game::actionMenu(Game::MenuOption userAnswer) {
    switch(menuOption_) {
    case MenuOption::PrintMap :
        printMap(); break;
    case MenuOption::Travel :
        travel(); break;
    case MenuOption::PrintCargo :
        printCargo(); break;
    case MenuOption::Buy :
        buy(); break;
    case MenuOption::Sell :
        sell(); break;
    case MenuOption::HireCrew :
        manageCrew(); break;
    case MenuOption::Exit :
        menuOption_ = exitGame(); break;
    default:
        std::cout << "Option doesn't exists\n";
    }
    return menuOption_;
}

bool Game::isChoiceValid(const size_t& option) { 
    if (std::cin.fail() || option < FIRST_OPTION_ELEMENT || option > LAST_OPTION_ELEMENT) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wrong value please insert number between " 
                  << FIRST_OPTION_ELEMENT << " and " << LAST_OPTION_ELEMENT << ".\n";
        return false;
    }
    return true;
}

Game::CheckAnswer Game::checkAnswer(const std::string& announcement) {
    std::cout << announcement << '\n';
    std::cin.clear();
    std::cin.ignore(100,'\n');
    char answer = getchar();
    if (answer == 'Y' || answer == 'y') {
        return CheckAnswer::Yes;
    }
    if (answer == 'N' || answer == 'n') {
        return CheckAnswer::No;
    }
    std::cout << "Wrong answer, you must choose Y or N\n";
    return CheckAnswer::Error;   
}

Game::MenuOption Game::exitGame() {
    while (true) {
        CheckAnswer exitAnswer = checkAnswer("Are you sure you wanna exit game? Y/N");
        if (exitAnswer == CheckAnswer::Yes) {
            return Game::MenuOption::Exit;
        }
        if (exitAnswer == CheckAnswer::No) {
            return Game::MenuOption::NoChoice;
        }
    }
}

void Game::travel() {
    do {
        printMap();
        std::cout << "You are at island ("
                << player_->getCurrentPosition()->getCoordinates().getPositionX() << ", "
                << player_->getCurrentPosition()->getCoordinates().getPositionY() << ")\n";
        setUserDestination();
        destinationIsland = generateDestinationIsland();
        if (destinationIsland) {
            playerSpeed = player_->getSpeed();
            travelTime = (getTravelDistance(destinationIsland)* DISTANCE_MULTIPLIER) / playerSpeed;
            generatingTravelInfo();
        }
    } while (checkAnswer("Do you accept this journey") != CheckAnswer::Yes);
    player_->setCurrentPosition(destinationIsland);
    countingCurrentDay(travelTime);
}

void Game::generatingTravelInfo() {
    std::cout << "You covered the distance of " << getTravelDistance(destinationIsland)
                << " at speed " << playerSpeed << ".\n";
    std::cout << "Island no " << islandNo_  
                << " at coordinates (" << travelCoordX_ << ", " << travelCoordY_ 
                << ") reached in " << travelTime << " days.\n";
}

size_t Game::getTravelDistance(Island* destinationIsland) {
    return Island::Coordinates::distance(player_->getCurrentPosition()->getCoordinates(),
                                          destinationIsland->getCoordinates());
}

void Game::countingCurrentDay(size_t travelTime) {
        for (size_t i = 0; i < travelTime; i++) {
            ++(*time_);
        }
        currentDay_ = time_->getElapsedTime();
}

Island* Game::generateDestinationIsland() {
    travelCoordX_ = map_->getIslands()[islandNo_  - 1].getCoordinates().getPositionX();
    travelCoordY_ = map_->getIslands()[islandNo_  - 1].getCoordinates().getPositionY();
    return map_->getIsland(Island::Coordinates(travelCoordX_, travelCoordY_));
}

void Game::setUserDestination() {
    do {   
        std::cin.clear();
        std::cout << "Which island are you travelling to?" << std::endl;
        std::cin >> islandNo_ ;
        if (islandNo_  > islandMax_ || islandNo_  < 1) {
            std::cout << "No such island!" << std::endl;
            continue;
        }
    } while (std::cin.fail());
}

void Game::printCargo() {
// TO DO
}

void Game::buy() {
    std::cout << "Cargo to buy in store:\n";
    printCargoFromStore();
    std::string cargoName;
    size_t cargoAmount;
    Store::Response response;
    auto currentStore{ player_->getCurrentPosition()->getStore() };
    do {
        setUserCargo(cargoName, cargoAmount);
        
        Cargo* cargo = currentStore->getCargo(cargoName);
        
        response = currentStore->buy(cargo, cargoAmount, player_.get());
        if (response == Store::Response::done) {
            
            currentStore->cargoToShip(cargo, cargoAmount);
            
            break;
        }
        std::cout << "No such cargo!" << std::endl;
    } while (true);
    printResponse(response,
                  "Bought " + std::to_string(cargoAmount) + " of " + cargoName);
}

void Game::sell() {
    std::cout << "Cargo to sell:\n";
    printCargoFromShip();
    std::string cargoName;
    size_t cargoAmount;
    Store::Response response;
    auto currentStore = player_->getCurrentPosition()->getStore();
    do {
        setUserCargo(cargoName, cargoAmount);
        std::cout << "-----------------------  ERROR -------------------------------" << std::endl;
        Cargo* cargo = player_->getCargo(cargoName);
        response = currentStore->sell(cargo, cargoAmount, player_.get());
        if (response == Store::Response::done) {
            
            currentStore->cargoFromShip(cargo, cargoAmount);
            
            break; 
        }
        std::cout << "No such cargo!" << std::endl;
    } while (true);
    printResponse(response,
                  "Sold " + std::to_string(cargoAmount) + " of " + cargoName);
}

void Game::setUserCargo(std::string& cargoName, size_t& cargoAmount) {
    do {
        std::cin.clear();
        std::cout << "Input cargo name: ";
        std::cin >> cargoName;
        std::cout << "Input cargo amount: ";
        std::cin >> cargoAmount;
        if (std::cin.fail()) {
            std::cout << "Invalid amount!\n";
        }
    } while (std::cin.fail());
}

void Game::printResponse(const Store::Response& response,
                         const std::string& message)
{
    switch (response) {
    case Store::Response::done:
        std::cout << message << '\n'; break;
    case Store::Response::lack_of_cargo:
        std::cout << "There is not enough cargo!\n"; break;
    case Store::Response::lack_of_space:
        std::cout << "There is not enough space!\n"; break;
    case Store::Response::lack_of_money:
        std::cout << "You do not have enough money!\n"; break;
    }
}

void Game::manageCrew() {
    int choice {};
    do {
        do {
        printCrew();
        std::cout << "1. Hire crew.\n2. Dismiss Crew.\n3. Back to main menu\n";
        std::cin >> choice;
    } while (!isCrewNumber(choice));
    switch (choice) {
    case 1 : 
        hireCrew();
        break;
    case 2 : 
        dismissCrew();
        break;
    case 3 : 
        selectOption();
        break;
    default : 
        break;
    }
    } while (choice != 1 || choice != 2 || choice != 3);
}

void Game::hireCrew() {
    int crewAmount {};
    std::cout << "Cost of crew is 1 coin\n";
    do {
        std::cout << "How many crew you wanna hire? ";
        std::cin >> crewAmount;
    } while (!isCrewNumber(crewAmount));

    if (isNumberLowerThanZero(crewAmount)) {
        std::cout << "The number must be greater than 0\n";
    }
    else if (!hasPlayerEnoughMoney(crewAmount)) {
        std::cout << "You don't have enough money\n";
    } 
    else {
        player_->getShip()->operator+=(crewAmount);
    } 
}

void Game::dismissCrew() {
    size_t crewAmount {};
    do {
        std::cout << "How many sailors you want to dismiss? ";
        std::cin >> crewAmount;
    } while (!isCrewNumber(crewAmount));
    player_->getShip()->operator-=(crewAmount);
}
bool Game::isCrewNumber(const int crew) { 
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wrong value please insert number.\n";
        return false;
    }
    return true;
}
void Game::printCrew() {
    std::cout << "Crew: " << player_->getShip()->getCrew() << " / " << player_->getShip()->getMaxCrew()<< '\n';
}
bool Game::hasPlayerEnoughMoney(const int crew) {
    if (crew > player_->getMoney()) {
        return false;
    }
    return true;
}

bool Game::isNumberLowerThanZero(const int crew) {
    return crew < 0;
}

void Game::printCargoFromStore() {
    std::cout << *player_->getCurrentPosition()->getStore();
}

void Game::printCargoFromShip() {
    std::cout << *player_->getShip();
}