#pragma once

#include "Command.hpp"

class Player;

class PrintCargo : public Command {
public:
    // Overrides from ICommand
    ~PrintCargo() override = default;
    void execute(Player* player) override;
};
