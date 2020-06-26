#include "game.hpp"

#include <iostream>

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
        if (!action)
            break;
        makeAction(static_cast<Action>(action));
    }
}

void Game::printMenu() {
    //    std::cout << "Money: " << player_->
}

void Game::printOption() {
    std::cout << "0. Exit \n"
              << "1. Buy \n"
              << "2. Sell \n"
              << "Next is your choice:  \n";
}

void Game::makeAction(Action choice) {
    switch (choice) {
    case Action::Buy:
        /* code */
        buy();
        break;
    case Action::Sell:
        break;
    default:
        break;
    }
}

void Game::buy() {
    Store store;
    store.generateCargo();
    while (true) {
        uint32_t choiceProduct;
        uint32_t choiceAmount;

        std::cout << "Money of player: " << player_->getMoney() << '\n';
        std::cout << "Available place on ship: " << player_->getAvailableSpace() << '\n';
        player_->printCargo();
        std::cout << store;
        std::cin >> choiceProduct >> choiceAmount;
        if (choiceProduct == 0)
            break;

        Store::Response response = store.buy(store.getCargo(choiceProduct - 1), choiceAmount, player_.get());
        switch (response) {
        case Store::Response::done:
            std::cout << "You buy: " << store.getCargo(choiceProduct - 1)->getName() << " in amount: " << choiceAmount
                      << " by price: " << store.getCargo(choiceProduct - 1).get()->getBasePrice() << " \n";
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
