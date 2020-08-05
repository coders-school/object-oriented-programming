#include "Store.hpp"
#include "Game.hpp"

constexpr size_t startMoney = 1000;
constexpr size_t gameDays = 100;
constexpr size_t finalGoal = 2000;

int main() {
    system("clear");

    Time time;
    auto timePtr = std::make_shared<Time>(time);

    Ship ship(100, 100, 10, "tratwa", 42, timePtr);
    auto shipPtr = std::make_shared<Ship>(ship);

    Player player(shipPtr, 1000);
    auto playerPtr = std::make_shared<Player>(player);

    Store store(timePtr);
    std::cout << store;

    std::cout << "Money: " << playerPtr->getMoney() << " Space: " << playerPtr->getAvailableSpace() << "\n";

    size_t index, amount;
    std::cout << "Index, amount\n";
    std::cin >> index >> amount;

    auto cargo = StockManagement::getCargo(store.getAllCargos(), index);
    store.buy(cargo, amount, playerPtr);

    system("clear");
    std::cout << store;
    std::cout << "Money: " << playerPtr->getMoney() << " Space: " << playerPtr->getAvailableSpace() << "\n";
    std::cout << *shipPtr;

    std::cout << "Index, amount\n";
    std::cin >> index >> amount;

    cargo = StockManagement::getCargo(store.getAllCargos(), index);
    store.buy(cargo, amount, playerPtr);

    system("clear");
    std::cout << store;
    std::cout << "Money: " << playerPtr->getMoney() << " Space: " << playerPtr->getAvailableSpace() << "\n";
    std::cout << *shipPtr;

    std::cout << "Index, amount\n";
    std::cin >> index >> amount;

    cargo = StockManagement::getCargo(shipPtr->getAllCargos(), index);
    store.sell(cargo, amount, playerPtr);
    
    system("clear");
    std::cout << store;
    std::cout << "Money: " << playerPtr->getMoney() << " Space: " << playerPtr->getAvailableSpace() << "\n";
    std::cout << *shipPtr;

    return 0;
}
