#pragma once

#include "Command.hpp"
#include "../GeneralPrint.hpp"

class TradeSell : public Command {
public:
    TradeSell() = default;
    void operator()(Player& player, Store& store) override {
        while (true) {
            size_t limit = 0;
            printShipCargoList(player);
            printPlayerStatus(player);

            std::cout << "Which Cargo want to sell to store?\n";
            limit = player.getShip()->getCargoVec().size();
            auto chose = ChoseOption(limit);
            if (chose >= limit) {
                break;
            }
            const Cargo* const cargo = ChoseCargoFromShip(chose, player);

            std::cout << "Amount:\n";
            limit = cargo->getAmount() + 1;
            size_t amount = ChoseOption(limit);
            if (amount >= limit) {
                break;
            }

            Response response = store.buy(cargo, amount, &player);
            printResponse(response);
        }
    }

    std::string getName() const override { return "Sell"; }
};
