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
    constexpr size_t LAST_OPTION_ELEMENT{ 6 };
}

Game::Game(size_t money, size_t gameDays, size_t finalGoal)
    : money_(money)
    , gameDays_(gameDays)
    , finalGoal_(finalGoal)  
{
    time_ = std::make_unique<Time>();
    map_ = std::make_shared<Map>();
    player_ = std::make_unique<Player>(std::make_unique<Ship>(1, 25, 100, nullptr),
                                       map_, 100, 10000);
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
    size_t frameSize { 100 };
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
    std::cout << "#" << std::setfill('-')  << std::setw (30) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (22) << " CHOOSE ACTION: " << std::setw (8) << "#\n";
    std::cout << "#" << std::setfill('-')  << std::setw (30) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (30) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (21) << " 1. SHOW MAP " << std::setw (9) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (20) << " 2. TRAVEL " << std::setw (10) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (22) << " 3. PRINT CARGO " << std::setw (8) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (19) << " 4. BUY " << std::setw (11) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (19) << " 5. SELL" << std::setw (11) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (21) << " 6. HIRE CREW" << std::setw (9) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (19) << " 7. EXIT" << std::setw (11) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (30) << "#\n";
    std::cout << "#" << std::setfill('-')  << std::setw (31) << "#\n\n";
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
    size_t islandNo{};
    for (const auto& island : map_->getIslands()) {
        std::cout << "Island no " << ++islandNo 
                  << " ---- Coordinates [" << island.getCoordinates().getPositionX() 
                  << "][" << island.getCoordinates().getPositionY() << "]\n";
    }
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
        hireCrew(); break;
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
    printMap();
    auto islandMax = map_->getIslands().size();
    std::cout << "You are at island ("
              << player_->getCurrentPosition()->getCoordinates().getPositionX() << ", "
              << player_->getCurrentPosition()->getCoordinates().getPositionY() << ")\n";
    size_t islandNo;
    setUserDestination(islandNo, islandMax);
    size_t coordX{map_->getIslands()[islandNo - 1].getCoordinates().getPositionX()};
    size_t coordY{map_->getIslands()[islandNo - 1].getCoordinates().getPositionY()};
    Island* destinationIsland{ map_->getIsland(Island::Coordinates(coordX, coordY)) };
    if (destinationIsland) {
        const size_t distance{
            Island::Coordinates::distance(player_->getCurrentPosition()->getCoordinates(),
                                          destinationIsland->getCoordinates())
        };
        const size_t playerSpeed = player_->getSpeed();
        const size_t travelTime = (distance * DISTANCE_MULTIPLIER) / playerSpeed;
        std::cout << "You covered the distance of " << distance 
                  << " at speed " << playerSpeed << ".\n";
        player_->setCurrentPosition(destinationIsland);
        std::cout << "Island no " << islandNo 
                  << " at coordinates (" << coordX << ", " << coordY 
                  << ") reached in " << travelTime << " days.\n";
        for (size_t i = 0; i < travelTime; i++) {
            ++(*time_);
        }
        currentDay_ = time_->getElapsedTime();
    }
}

void Game::setUserDestination(size_t& islandNo, size_t islandMax) {
    do {   
        std::cin.clear();
        std::cout << "Which island are you travelling to?" << std::endl;
        std::cin >> islandNo;
        if (islandNo > islandMax || islandNo < 1) {
            std::cout << "No such island!" << std::endl;
            continue;
        }
    } while (std::cin.fail());
}

void Game::printCargo() {

}

void Game::buy() {
    std::cout << "Cargo to buy in store:\n";
    // TODO: print store cargo
    std::string cargoName;
    size_t cargoAmount;
    Store::Response response;
    auto currentStore{ player_->getCurrentPosition()->getStore() };
    do {
        setUserCargo(cargoName, cargoAmount);
        Cargo* cargo{ currentStore->getCargo(cargoName) };
        if (cargo) {
            response = currentStore->buy(cargo, cargoAmount, player_.get());
            break;
        }
        std::cout << "No such cargo!" << std::endl;
    } while (true);
    printResponse(response,
                  "Bought " + std::to_string(cargoAmount) + " of " + cargoName);
}

void Game::sell() {
    std::cout << "Cargo to sell:\n";
    // TODO: print ship cargo
    std::string cargoName;
    size_t cargoAmount;
    Store::Response response;
    auto currentStore{ player_->getCurrentPosition()->getStore() };
    do {
        setUserCargo(cargoName, cargoAmount);
        Cargo* cargo{ player_->getCargo(cargoName) };
        if (cargo) {
            response = currentStore->sell(cargo, cargoAmount, player_.get());
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

void Game::hireCrew() {
    size_t crewAmount{};
    std::cout << "Cost of crew is 1 coin\n";
    do {
        std::cout << "How many crew you wanna hire? ";
        std::cin >> crewAmount;
    } while (isCrewNumber(crewAmount));

    if (hasPlayerEnoughMoney(crewAmount)) {
        *(player_->getShip()) += crewAmount;
        std::cout << "You have employed " << crewAmount << " sailors\n";
    } else {
        std::cout << "You don't have enough money\n";
    }
}

bool Game::isCrewNumber(const size_t& crew) { 
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wrong value please insert number.\n";
        return false;
    }
    return true;
}

bool Game::hasPlayerEnoughMoney(const size_t& crew) {
    if (crew > player_->getMoney()) {
        return false;
    }
    return true;
}
