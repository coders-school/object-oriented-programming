#include "game.hpp"

#include <cmath>
#include <iostream>

#include "island.hpp"
#include "map.hpp"
#include "store.hpp"

Game::Game(uint32_t money, uint32_t days, uint32_t target, Time* time)
    : money_(money), days_(days), target_(target), time_(time) {}

void Game::startGame() {
    std::cout << "SHM game is welcome ! \n"
              << "To final game you have to reach: " << money_ << " Have a good fun :) \n";

    store_ = map_->getCurrentPosition()->getStore();

    while (days_) {
        printMenu();
        printOption();
        uint32_t action;
        std::cin.clear();
        std::cin >> action;
        if (!action) {
            break;
        }
        makeAction(static_cast<Action>(action));
    }
}

void Game::printMenu() {
    if (!map_->getCurrentPosition()) {
        std::cout << "Money:" << player_->getMoney() << " | Position:  Water | "
                  << "Day: " << timeElapsed << " | "
                  << "Left days: " << days_ - timeElapsed << " | "
                  << "\n";
    } else {
        std::cout << "Money: " << player_->getMoney()
                  << " | Position: X = " << map_->getCurrentPosition()->getPosition().getPositionX()
                  << " Y = " << map_->getCurrentPosition()->getPosition().getPositionY() << " | Day: " << timeElapsed
                  << " | "
                  << "Left days: " << days_ - timeElapsed << " | "
                  << " \n";
    }
}

void Game::printOption() {
    std::cout << "0. Exit \n"
              << "1. Buy \n"
              << "2. Sell \n"
              << "3. Travel \n"
              << "Next is your choice:  \n";
}

void Game::makeAction(Action choice) {
    switch (choice) {
    case Action::Buy:
        buy();
        break;
    case Action::Sell:
        sell();
        break;
    case Action::Travel:
        travel();
        break;
    default:
        break;
    }
}

void Game::buy() {
    while (true) {
        uint32_t choiceProduct;
        uint32_t choiceAmount;

        std::cout << "Money of player: " << player_->getMoney() << '\n';
        std::cout << "Available place on ship: " << player_->getAvailableSpace() << '\n';
        player_->printCargo();
        if (store_->getCargo(0)) {
            std::cout << *store_;
        } else {
            std::cout << "You are not at the Island ! You are on water ! Press 0 to return back \n";
        }
        std::cin >> choiceProduct;
        if (choiceProduct == 0) {
            break;
        }
        std::cin >> choiceAmount;
        Store::Response response = store_->buy(store_->getCargo(choiceProduct - 1), choiceAmount, player_.get());
        switch (response) {
        case Store::Response::done:
            std::cout << "You buy: " << store_->getCargo(choiceProduct - 1)->getName() << " in amount: " << choiceAmount
                      << " by price: " << store_->getCargo(choiceProduct - 1).get()->getBasePrice() << " \n";
            break;
        case Store::Response::lack_of_cargo:
            std::cout << "Store is not have enough cargo ! \n";
            break;
        case Store::Response::lack_of_money:
            std::cout << "You do not have enough money ! \n";
            break;
        case Store::Response::lack_of_space:
            std::cout << "You do not have enough space on your ship ! \n";
            break;
        }
    }
}

void Game::sell() {
    while (true) {
        uint32_t choiceProduct;
        uint32_t choiceAmount;

        std::cout << "Money of player: " << player_->getMoney() << '\n';
        std::cout << "Available place on ship: " << player_->getAvailableSpace() << '\n';
        player_->printCargo();
        if (store_->getCargo(0)) {
            std::cout << *store_;
        } else {
            std::cout << "You are not at the Island ! You are on water ! Press 0 to return back \n";
        }
        std::cin >> choiceProduct;
        if (choiceProduct == 0) {
            break;
        }
        std::cin >> choiceAmount;
        std::string productName = player_->getCargo(choiceProduct - 1)->getName();
        uint32_t productPrice = player_->getCargo(choiceProduct - 1).get()->getBasePrice();
        Store::Response response = store_->sell(player_->getCargo(choiceProduct - 1), choiceAmount, player_.get());
        switch (response) {
        case Store::Response::done:
            std::cout << "You sell: " << productName << " in amount: " << choiceAmount << " by price: " << productPrice
                      << " \n";
            break;
        case Store::Response::lack_of_cargo:
            std::cout << "You do not have that much cargo ! \n";
            break;
        case Store::Response::lack_of_money:
            std::cout << "You do not have enough money ! \n";
            break;
        case Store::Response::lack_of_space:
            std::cout << "You do not have enough space on your ship ! \n";
            break;
        }
        store_->printCargo();
    }
}

void Game::travel() {
    while (true) {
        map_->showIslands();
        std::cout << "Next destination ?: \n";
        int32_t currentX;
        int32_t currentY;
        int32_t x;
        int32_t y;
        uint32_t distance;
        uint32_t ship_speed;
        uint32_t time_travel;
        currentX = map_->getCurrentPosition()->getPosition().getPositionX();
        currentY = map_->getCurrentPosition()->getPosition().getPositionY();
        std::cin >> x >> y;

        if (x == 0 || y == 0) {
            break;
        }

        distance = abs(currentX - x) + abs(currentY - y);
        ship_speed = ship_->getSpeed();
        time_travel = distance / ship_speed;

        if (time_travel == 1) {
            std::cout << "You will be travelling " << time_travel << " day\n";
        } else {
            std::cout << "You will be travelling " << time_travel << " days\n";
        }

        island_ = map_->getIsland(Coordinates(x, y));
        if (island_ != nullptr) {
            for (uint32_t i = 0; i < (time_travel); i++) {
                time_->operator++();
                timeElapsed++;
            }
            map_->travel(island_);
            store_ = map_->getIsland(Coordinates(x, y))->getStore();
            std::cout << "Island is here \n";
            break;
        }
        std::cout << "No island for that destination ! \n   ";
    }
}
