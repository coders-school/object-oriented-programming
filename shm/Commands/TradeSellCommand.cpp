#include "TradeSellCommand.hpp"
#include "../GeneralPrint.hpp"

void TradeSell::operator()(Player& player, Store& store) {
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

    std::string TradeSell::getName() const { 
        return "Sell"; 
    }
