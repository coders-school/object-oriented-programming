#include <iomanip>
#include <iostream>

#include "player.hpp"
#include "print_cargo.hpp"

void PrintCargo::displayCargoValues(const Cargo* cargo) {
    std::cout << std::setw(12) << cargo->getName() << " |" << std::setw(12)
              << cargo->getAmount() << " |" << std::setw(12) << cargo->getBasePrice()
              << " |\n";
}

void PrintCargo::displayTableHeader() {
    std::string dash(42, '-');
    std::cout << std::setw(14) << "Name |" << std::setw(14) << " Amount |"
              << std::setw(15) << " Baseprice |\n"
              << dash << '\n';
}

void PrintCargo::execute(Player* player) {
    size_t cargoIndex = 0;
    auto cargo = player->getCargo(cargoIndex);

    displayTableHeader();

    while (cargo) {
        displayCargoValues(cargo);
        cargoIndex++;
        cargo = player->getCargo(cargoIndex);
    }
}
