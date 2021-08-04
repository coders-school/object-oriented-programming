#pragma once

#include "Command.hpp"

class Menu : public Command {
public:
    Menu() = default;
    void operator()(Player& player, Store& store) override;
    std::string getName() const override;
};
