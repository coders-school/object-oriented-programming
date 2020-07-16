#pragma once

#include "command.hpp"

class Player;
class Cargo;

class PrintCargo : public Command {
public:
    // Overrides from ICommand
    ~PrintCargo() override = default;
    void execute(Player* player) override;

private:
    void displayTableHeader();
    void displayCargoValues(const Cargo* cargo);
};
