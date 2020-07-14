#include "game.hpp"

#include <algorithm>
#include <iostream>

#include "cargo.hpp"
#include "globaltime.hpp"
#include "island.hpp"
#include "store.hpp"

const std::string line(80, '=');

Game::Game(size_t money, size_t days, size_t finalGoal)
    : money_(money), days_(days), finalGoal_(finalGoal) {
    std::shared_ptr<Ship::Delegate> delegate;
    time_ = std::make_shared<Time>();
    GlobalTime::provideGlobalTime(time_.get());
    map_ = std::make_unique<Map>(Map());
    Ship ship(200, 50, 3, "Black Pearl", 1, delegate.get(), time_.get());
    player_ = std::make_shared<Player>(Player(ship, money, 200ul));
    delegate = player_;
    ship.setDelegate(delegate.get());
}

void Game::startGame() {
    system("clear");
    std::cout << "Welcome in SHM, you have: " << days_
              << " days, to gain: " << money_ << " HAVE FUN!\n\n";

    while (days_ > time_->getElapsedTime()) {
        if (checkWinCondition()) {
            printWinScreen();
            return;
        } else if (checkLooseCondition()) {
            break;
        }
        std::cout << line << "\n";
        printMenu();
        printOptions();
        size_t option;
        std::cin.clear();
        std::cin >> option;
        if (option == 5) {
            break;
        }
        system("clear");
        makeAction(static_cast<Action>(option));
    }
    printLooseScreen();
}

bool Game::checkWinCondition() const {
    return player_->getMoney() >= finalGoal_;
}

bool Game::checkLooseCondition() const {
    return player_->getMoney() == SIZE_MAX;
}

void Game::printMenu() {
    std::cout << "Your money: " << player_->getMoney()
              << " Day: " << time_->getElapsedTime()
              << " Days to end: " << days_ - time_->getElapsedTime()
              << " Position: "
              << map_->getCurrentPosition()->getPosition() << "\n";
}

void Game::printOptions() {
    std::cout << "\n"
              << "1) Travel\n"
              << "2) Sell\n"
              << "3) Buy\n"
              << "4) Check cargo\n"
              << "5) Exit\n\n"
              << "Choose option: ";
}

void Game::printWinScreen() {
    system("clear");
    std::cout << "CONGRATULATION!!! YOU WIN, You earn: " << player_->getMoney()
              << " money in: " << time_->getElapsedTime() << " days";
}

void Game::printLooseScreen() {
    system("clear");
    std::cout << "GAME OVER! You earn: " << player_->getMoney()
              << " money in: " << time_->getElapsedTime() << " days";
}

void Game::makeAction(Action action) {
    switch (action) {
    case Action::Travel:
        travel();
        break;
    case Action::Sell:
        sell();
        break;
    case Action::Buy:
        buy();
        break;
    case Action::checkCargo:
        printCargo();
        break;
    default:
        std::cout << "Wrong action!\n";
        break;
    }
}

void Game::travel() {
    std::cout << *map_;
    size_t option;
    std::cout << "Choose Island: ";
    std::cin.clear();
    std::cin >> option;

    if (option < 1 || option > Map::kIslandAmt - 1) {
        return;
    }
    size_t daysToArrive = map_->getDaysToArrive(option);
    for (size_t i = 0; i < daysToArrive; i++) {
        ++(*time_);
    }
    map_->travel(option);
}

Game::BuySellAction Game::buySellChoice(const CargoHolder* const sourceCargoHolder) const {
    Game::BuySellAction action;
    auto& availableCargos = sourceCargoHolder->getAllCargo();
    sourceCargoHolder->printAllCargoOwned();

    std::cout << "Choose cargo:\n";
    std::cin.clear();
    size_t option;
    std::cin >> option;
    if (option < 1 || option > availableCargos.size()) {
        std::cout << "Invalid choice\n";
        action.valid = false;
        return action;
    }
    action.option = option;

    std::cout << "Choose amount:\n";
    std::cin.clear();
    size_t amount;
    std::cin >> amount;
    if (amount < 1 || amount > availableCargos[option]->getAmount()) {
        std::cout << "Invalid amount\n";
        action.valid = false;
        return action;
    }
    action.amount = amount;
    action.valid = true;
    return action;
}

void Game::buy() {
    auto store = map_->getCurrentPosition()->getStore();
    Game::BuySellAction action = buySellChoice(store);

    if (!action.valid)
        return;
    auto& availableCargos = store->getAllCargo();

    store->sell(availableCargos[action.option - 1].get(), action.amount, player_.get());
}

void Game::sell() {
    auto store = map_->getCurrentPosition()->getStore();
    auto player = player_;
    Game::BuySellAction action = buySellChoice(player.get());

    if (!action.valid)
        return;
    auto& availableCargos = player->getAllCargo();

    store->buy(availableCargos[action.option - 1].get(), action.amount, player_.get());
}

void Game::printCargo() {
    player_->printAllCargoOwned();
}
