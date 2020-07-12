#include "game.hpp"

#include <iostream>

Game::Game(size_t money, size_t days, size_t final_goal)
    : money_(money), days_(days), final_goal_(final_goal), time_(std::make_unique<Time>()) {
    map_ = std::make_unique<Map>();
    current_day_ = time_->getElapsedTime();
    ship_ = std::make_unique<Ship>(1000, 99, 7, "Titanic", 1, time_.get());
    player_ = std::make_shared<Player>(*ship_, 250, 30);
    store_ = std::make_unique<Store>(time_.get());
}

void Game::startGame() {
    std::cout << "Welcome in SHM, you have: " << days_
              << " days, to gain: " << final_goal_ << "\n";

    while (days_ > current_day_) {
        if (checkWinCondition()) {
            printWonScreen();
            return;
        } else if (checkLooseCodition()) {
            break;
        }

        printInfo();
        printOptions();
        
        size_t action;
        std::cin.clear();
        std::cin >> action;
        if (action == 0) {
            break;
        }
        makeAction(static_cast<Action>(action));
    }
    printLostScreen();
}

bool Game::checkWinCondition() const {
    return player_->getMoney() >= final_goal_;
}

void Game::printWonScreen() {
    std::cout << "You won! You earned " << player_->getMoney()
              << " money in " << current_day_ << " days.\n";
}

bool Game::checkLooseCodition() const {
    return player_->getMoney() == SIZE_MAX;
}

void Game::printLostScreen() {
    std::cout << "You lost! You earned " << player_->getMoney()
              << " money in " << current_day_ << " days.\n";
}

void Game::printInfo() {
    std::cout << "\n---------------------------------------\n"
              << "Money: " << player_->getMoney()
              << " # Day: " << current_day_
              << " # Days left: " << days_ - current_day_ << "\n";
}

void Game::printOptions() {
    std::cout << "Choose your option:\n"
              << "1. Travel\n"
              << "2. Sell\n"
              << "3. Buy\n"
              << "4. Ship cargo\n"
              << "5. Store cargo\n"
              << "0. Exit\n"
              << "Your choice: ";
}

void Game::makeAction(Action choice) {
    switch (choice) {
    case Action::Travel:
        travel();
        break;
    case Action::Sell:
        sell();
        break;
    case Action::Buy:
        buy();
        break;
    case Action::ShipCargo:
        printShipCargo();
        break;
    case Action::StoreCargo:
        printStoreCargo();
        break;
    default:
        std::cout << "Wrong option!\n";
        break;
    }
}

void Game::travel() {
    while (true) {
        std::cout << "\n";
        map_->printMap();
        std::cout << "\nYou are at island: ("
                  << map_->getCurrentPosition()->getPosition().getPositionX() << ", "
                  << map_->getCurrentPosition()->getPosition().getPositionY() << ")\n";

        std::cout << "Choosing island to travel to...\n";
        size_t posX, posY;
        std::cout << "Coordinate X: ";
        std::cin >> posX;
        std::cout << "Coordinate Y: ";
        std::cin >> posY;
        Island* island = map_->getIsland(Coordinates(posX, posY));
        if (island != nullptr) {
            const size_t distance = map_->getDistanceToIsland(island);
            const size_t playerSpeed = player_->getSpeed();
            const size_t travelTime = (distance * 10) / playerSpeed;
     
            std::cout << "# distance: " << distance << "\n";
            std::cout << "# at speed: " << playerSpeed << "\n";
            
            map_->travel(island);
            std::cout << "You have reached the island at ("
                      << map_->getCurrentPosition()->getPosition().getPositionX() << ", "
                      << map_->getCurrentPosition()->getPosition().getPositionY() << ")\n";
            std::cout << "# travel time: " << travelTime << "\n";

            for (size_t i = 0; i < travelTime; i++) {
                ++*time_;
            }
            current_day_ = time_->getElapsedTime();
            break;
        } else {
            std::cout << "\nWrong coordinates!\n";
        }
    }
}

void Game::sell() {
    while (true) {
        std::cout << "Available cargo to sell:\n";
        player_->printShipCargo();

        std::string cargoName;
        size_t cargoAmount;

        std::cout << "\nChoosing cargo to sell...\n";
        std::cout << "Cargo name: ";
        std::cin >> cargoName;
        std::cout << "Cargo quantity: ";
        std::cin >> cargoAmount;

        Cargo* cargo = player_->getCargo(cargoName);
        Store::Response response = store_->sell(cargo, cargoAmount, player_.get());

        switch (response) {
        case Store::Response::done:
            std::cout << "Sold " << cargoAmount << " of " << cargoName << "\n";
            return;
        case Store::Response::lack_of_cargo:
            std::cout << "There is no enough cargo to sell\n";
            break;
        case Store::Response::lack_of_space:
            std::cout << "There is no enough space in store\n";
            break;
        case Store::Response::invalid_cargo:
            std::cout << "There is no such cargo\n";
            break;
        case Store::Response::lack_of_money:
            std::cout << "You do not have enough money\n";
            break;
        }
    }
}

void Game::buy() {
    while (true) {
        std::cout << "Available cargo to buy:\n";
        store_->printCargo();

        std::string cargoName;
        size_t cargoAmount;

        std::cout << "\nChoosing cargo to buy...\n";
        std::cout << "Cargo name: ";
        std::cin >> cargoName;
        std::cout << "Cargo quantity: ";
        std::cin >> cargoAmount;

        Cargo* cargo = player_->getCargo(cargoName);
        Store::Response response = store_->buy(cargo, cargoAmount, player_.get());
        
        switch (response) {
        case Store::Response::done:
            std::cout << "Bought " << cargoAmount << " of " << cargoName << "\n";
            return;
        case Store::Response::lack_of_cargo:
            std::cout << "There is no enough cargo to buy\n";
            break;
        case Store::Response::lack_of_space:
            std::cout << "You do not have enough space on your ship\n";
            break;
        case Store::Response::invalid_cargo:
            std::cout << "There is no such cargo\n";
            break;
        case Store::Response::lack_of_money:
            std::cout << "You do not have enough money\n";
            break;
        }
    }
}

void Game::printShipCargo() {
    std::cout << "Cargo on your ship:\n";
    player_->printShipCargo();
}

void Game::printStoreCargo() {
    std::cout << "Cargo in store:\n";
    store_->printCargo();
}
