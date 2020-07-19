#include <iostream>

#include "game.hpp"
#include "locators.hpp"

Game::Game(size_t money, size_t days, size_t final_goal)
    : money_(money),
      days_(days),
      final_goal_(final_goal),
      time_(std::make_unique<Time>()) {
    TimeServiceLocator::provide(time_.get());
    map_ = std::make_unique<Map>();
    player_ = std::make_unique<Player>(money);
    buy_command_ = std::make_unique<Buy>(map_.get());
    sell_command_ = std::make_unique<Sell>(map_.get());
    travel_command_ = std::make_unique<Travel>(map_.get(), TimeServiceLocator::getTime());
    print_cargo_command_ = std::make_unique<PrintCargo>();
}

void Game::startGame() {
    while (days_ > time_->getElapsedTime()) {
        printMenu();
        printOptions();
        size_t action;
        std::cin >> action;
        if (action == 0) {
            std::cout << "You are exiting the game. Goodbye!\n";
            return;
        }
        makeAction(static_cast<Action>(action));
        if (checkWinCondition()) {
            printWinScreen();
            return;
        } else if (checkLoseCondition()) {
            printLooseScreen();
            return;
        }
    }
}

void Game::makeAction(Action action) {
    switch (action) {
    case Action::Buy:
        buy_command_->execute(player_.get());
        break;
    case Action::Sell:
        sell_command_->execute(player_.get());
        break;
    case Action::Travel:
        travel_command_->execute(player_.get());
        break;
    case Action::PrintCargo:
        print_cargo_command_->execute(player_.get());
        break;
    default:
        std::cout << "Bad command"
                  << "\n";
    }
}

bool Game::checkWinCondition() const {
    return money_ >= final_goal_;
}

bool Game::checkLoseCondition() const {
    return money_ == 0 || (current_day_ >= days_ && money_ < final_goal_);
}

void Game::printMenu() {
    auto elapsedTime = time_->getElapsedTime();
    std::cout << "Day: " << elapsedTime << " Days left: " << days_ - elapsedTime
              << " Money: " << player_->getMoney();
}

void Game::printOptions() {
    std::cout << '\n'
              << " 1) Buy \n"
              << " 2) Sell \n"
              << " 3) Travel \n"
              << " 4) Print Cargo \n"
              << " 0) Exit \n";
}

void Game::printWinScreen() {
    std::cout << "Congratulations! You have earned " << player_->getMoney()
              << " before the deadline. (days left) " << days_ - time_->getElapsedTime()
              << ".";
}

void Game::printLooseScreen() {
    std::cout << "You have lost. You have earned " << player_->getMoney()
              << " and the goal was " << final_goal_ << " try harder next time! ";
}
