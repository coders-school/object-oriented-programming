#include "game.hpp"

#include <iostream>

#include "island.hpp"
#include "map.hpp"
#include "store.hpp"

Game::Game(uint32_t money, uint32_t days, uint32_t target) : money_(money), days_(days), target_(target) {}

void Game::startGame() {
    std::cout << "SHM game is welcome ! \n"
              << "To final game you have to reach: " << money_ << " Have a good fun :) \n";

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
    std::cout << "Money: " << player_->getMoney() << "\n";
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
    // Store store;
    // store.generateCargo();
    while (true) {
        uint32_t choiceProduct;
        uint32_t choiceAmount;

        std::cout << "Money of player: " << player_->getMoney() << '\n';
        std::cout << "Available place on ship: " << player_->getAvailableSpace() << '\n';
        player_->printCargo();
        if (store_.getCargo(0)) {
            std::cout << store_;
        } else {
            std::cout << "You are not at the Island ! You are on water ! Press 0 to return back \n";
        }
        std::cin >> choiceProduct;
        if (choiceProduct == 0) {
            break;
        }
        std::cin >> choiceAmount;
        Store::Response response = store_.buy(store_.getCargo(choiceProduct - 1), choiceAmount, player_.get());
        switch (response) {
        case Store::Response::done:
            std::cout << "You buy: " << store_.getCargo(choiceProduct - 1)->getName() << " in amount: " << choiceAmount
                      << " by price: " << store_.getCargo(choiceProduct - 1).get()->getBasePrice() << " \n";
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
        if (store_.getCargo(0)) {
            std::cout << store_;
        } else {
            std::cout << "You are not at the Island ! You are on water ! Press 0 to return back \n";
        }
        std::cin >> choiceProduct;
        if (choiceProduct == 0) {
            break;
        }
        std::cin >> choiceAmount;
        Store::Response response = store_.sell(player_->getCargo(choiceProduct - 1), choiceAmount, player_.get());
        switch (response) {
        case Store::Response::done:
            std::cout << "You sell: " << player_->getCargo(choiceProduct - 1)->getName()
                      << " in amount: " << choiceAmount
                      << " by price: " << player_->getCargo(choiceProduct - 1).get()->getBasePrice() << " \n";
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
        store_.printCargo();
    }
}

void Game::travel() {
    while (true) {
        map_.showIslands();
        std::cout << "Next destination ?: \n";
        uint32_t x, y;
        std::cin >> x >> y;
        if (x == 0 || y == 0) {
            break;
        }
        Island* island = map_.getIsland(Coordinates(x, y));
        if (island != nullptr) {
            map_.travel(island);
            store_ = map_.getIsland(Coordinates(x, y))->getStore();
            std::cout << "Island is here \n";
            break;
        }
        std::cout << "No island for that destination ! \n   ";
    }
}
