#include "game.hpp"

#include <iostream>

Game::Game(size_t money, size_t days, size_t final_goal, size_t available_space)
    : money_(money),
      days_(days),
      final_goal_(final_goal),
      time_(std::make_unique<Time>()) {
    map_ = std::make_unique<Map>();

    // TODO: This is temporary (we must resolve ship/player dependency)
    player_ = std::make_unique<Player>(
        std::make_unique<Ship>(10, 10, 10, player_.get(), time_.get()), money,
        available_space);
    buy_command_ = std::make_unique<Buy>(map_.get());
    sell_command_ = std::make_unique<Sell>(map_.get());
    travel_command_ = std::make_unique<Travel>(map_.get(), time_.get());
    print_cargo_command_ = std::make_unique<PrintCargo>();
}

void Game::makeAction(Action action) {
    switch (action) {
    case Action::Buy:
        buy_command_->execute(player_.get());
        break;
    case Action::Sell:
        sell_command_->execute(player_.get());
    case Action::Travel:
        travel_command_->execute(player_.get());
    case Action::PrintCargo:
        print_cargo_command_->execute(player_.get());
    default:
        std::cout << "Bad command"
                  << "\n";
    }
}
