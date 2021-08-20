#include "GeneralPrint.hpp"

void printResponse(Response response) {
    std::array text{
        std::string("done"),
        std::string("lack_of_money"),
        std::string("lack_of_cargo"),
        std::string("lack_of_space")};
    std::cout << "Response: " << text[static_cast<size_t>(response)] << "\n";
}

void printPlayerStatus(const Player &player) {
    std::cout << "Player money: " << player.getMoney() << '\n';
}

void printPlayerGoal(size_t goal){
    std::cout << "Goal money: " << goal << '\n';
}

void printMenu(std::map<std::string, std::unique_ptr<Command>> &commands) {
    std::cout << "\n\nMENU -------\n";
    for (const auto &[key, command] : commands) {
        std::cout << key << " - " << command->getName() << '\n';
    }
}

void printStoreCargoList(const Store &store) {
    printf("\033[31m");
    std::cout << "STORE LIST -------\n";
    for (size_t i = 0; i < store.getCargoVec().size(); ++i) {
        std::cout << i << "\t"                                                 //
                  << "Name: " << store.getCargoVec()[i]->getName() << "\t\t"   //
                  << "Amount: " << store.getCargoVec()[i]->getAmount() << "\t" //
                  << "Price: " << store.getCargoVec()[i]->getPrice() << "\n";  //
    }
    printf("\033[0m\n");
}

void printShipCargoList(const Player &player) {
    printf("\033[33;44m");
    std::cout << "SHIP LIST -------\n";
    for (size_t i = 0; i < player.getShip()->getCargoVec().size(); ++i) {
        std::cout << i << "\t"                                                             //
                  << "Name: " << player.getShip()->getCargoVec()[i]->getName() << "\t\t"   //
                  << "Amount: " << player.getShip()->getCargoVec()[i]->getAmount() << "\t" //
                  << "Price: " << player.getShip()->getCargoVec()[i]->getPrice() << "\n";  //
    }
    printf("\033[0m\n");
}

//universal function to get value in range from user
size_t ChoseOption(size_t limit) {
    size_t result = 0;
    std::string input;
    std::cout << "Chose between [0," << (limit - 1) << "], or " << limit << " to abort:\n";

    do {
        std::cin >> input;
        result = atoi(input.c_str());
    } while (result > limit);

    return static_cast<size_t>(result);
}

const Cargo *ChoseCargoFromStore(size_t chose, Store &store) {
    auto limit = store.getCargoVec().size();
    if (chose == limit) {
        return nullptr;
    }
    return store.getCargoVec()[chose].get();
}

const Cargo *ChoseCargoFromShip(size_t chose, Player &player) {
    auto limit = player.getShip()->getCargoVec().size();
    if (chose == limit) {
        return nullptr;
    }
    return player.getShip()->getCargoVec()[chose].get();
}
