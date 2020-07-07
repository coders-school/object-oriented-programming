#include "Game.hpp"

#include <iostream>

#include "Map.hpp"

Game::Game(size_t money, size_t days, size_t finalGoal) :
    _money(money),
    _days(days),
    _finalGoal(finalGoal),
    _map(std::make_unique<Map>()),
    _player(std::make_unique<Player>(money, &_time)) {
}

void Game::StartGame() {
    std::cout << "Welcome in game SHM (made by The Diggers)\n"
        << "-= This is demo version =-\n\n";

    while (true) // (_days > ...)
    {
        if (_player->getMoney() >= _finalGoal) {
            std::cout << "You are winner\n";
        }

        displaySummary();
        size_t cmdId = selectCommands();
        if (cmdId == 0)
			break;
        doCommand(static_cast<Command>(cmdId));
    }
    std::cout << "\nThank you for your cooperation.\n\n";
}

void Game::displaySummary() {
    size_t day = 1; // get from time
    std::cout << "Day: " << day
              << ", days left: " << _days - day
              << "\nMoney: " << _player->getMoney()
              << ", money left: " << _money
              << "\nCurrent position: " << _map->getCurrentIsland()->getPosition() << "\n";
}

size_t Game::selectCommands() {
    std::cout << "\n"
              << "1) Show Cargo\n"
              << "2) Buy\n"
              << "3) Sell\n"
              << "4) Travel\n"
              << "0) I will be back\n\n"
              << "Your choice: ";
    size_t cmdId = 0;
    std::cin >> cmdId;

    return cmdId;
}

void Game::doCommand(Command cmd) {
    switch (cmd) {
    case Command::ShowCargo:
        showCargo();
        break;
    case Command::Buy:
        Buy();
        break;
    case Command::Sell:
        Sell();
        break;
    case Command::Travel:
        Travel();
        break;
    default:
        std::cout << "Try again\n";
        break;
    }
}

void Game::showCargo() {
    _player->showCargo();
}

void Game::Buy() {
    // ...
}

void Game::Sell() {
    // ...
}

void Game::Travel() {
    size_t x = 0, y = 0;
    std::cout << "Where would you want to travel: ";
    std::cin >> x >> y;
    Island* island = _map->getIsland(Coordinates(x, y));
    if (island != nullptr) {
        // ...
    }
}
