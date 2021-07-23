#pragma once

#include "Command.hpp"
#include "../GeneralPrint.hpp"

class Menu : public Command {
public:
    Menu() = default;
    void operator()(Player& player, Store& store) override {
        printStoreCargoList(store);
        printShipCargoList(player);
    }

    std::string getName() const override { return "Show menu"; }
};