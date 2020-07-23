#include "Store.hpp"
#include <memory>

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

    auto cargo = store.getCargo(index);
    store.buy(cargo, amount, playerPtr);

    system("clear");
    std::cout << store;
    std::cout << "Money: " << playerPtr->getMoney() << " Space: " << playerPtr->getAvailableSpace() << "\n";

    shipPtr->print();

    std::cout << "Index, amount\n";
    std::cin >> index >> amount;

    cargo = store.getCargo(index);
    store.buy(cargo, amount, playerPtr);

    system("clear");
    std::cout << store;
    std::cout << "Money: " << playerPtr->getMoney() << " Space: " << playerPtr->getAvailableSpace() << "\n";

    shipPtr->print();

    std::cout << "Index, amount\n";
    std::cin >> index >> amount;

    cargo = shipPtr->getCargo(index);
    store.sell(cargo, amount, playerPtr);

    std::cout << "Money: " << playerPtr->getMoney() << " Space: " << playerPtr->getAvailableSpace() << "\n";
    shipPtr->print();




    return 0;
}
