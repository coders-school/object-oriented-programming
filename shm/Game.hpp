#pragma once

#include <cstddef>
#include <memory>

#include "Map.hpp"
#include "Player.hpp"
#include "Time.hpp"

class Game {
public:
    enum class Command {
        ShowCargo = 1,
        Buy = 2,
        Sell = 3,
        Travel = 4
    };

    Game(size_t money, size_t days, size_t finalGoal);
    ~Game() = default;
    void StartGame();

    void displaySummary();
    size_t selectCommands();
    void doCommand(Command cmd);

    void showCargo();
    void Buy();
    void Sell();
    void Travel();

private:
    size_t _money;
    size_t _days;
    size_t _finalGoal;
    std::unique_ptr<Map> _map;
    std::unique_ptr<Player> _player;

    Time _time = {};
};
