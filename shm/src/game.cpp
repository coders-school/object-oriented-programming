#include "game.hpp"
#include "locators.hpp"
#include "time.hpp"

#include <iostream>

Game::Game(size_t money, size_t days, size_t final_goal)
    : money_(money),
      days_(days),
      final_goal_(final_goal),
      time_(std::make_unique<Time>()) {
    TimeServiceLocator::provide(time_.get());
    map_ = std::make_unique<Map>();
    player_ = std::make_unique<Player>(std::make_unique<Ship>(10, 10, 10, player_.get()),
                                       money);
    buy_command_ = std::make_unique<Buy>(map_.get());
    sell_command_ = std::make_unique<Sell>(map_.get());
    travel_command_ = std::make_unique<Travel>(map_.get(), TimeServiceLocator::getTime());
    print_cargo_command_ = std::make_unique<PrintCargo>();
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
