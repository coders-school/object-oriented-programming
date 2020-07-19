#include <iostream>

#include "sell.hpp"
#include "map.hpp"

Sell::Sell(Map* map) : map_(map) {}

void Sell::execute(Player* player) {
    // Will be good to print player's cargo somehow.
    while (true) {
        auto store = map_->getCurrentPosition()->getStore();
        std::cout << "\n" << *store.get() << "\n";

        size_t position{};
        size_t quantity{};

        std::cout << "Please enter the position and amount of cargo you are interested "
                     "in Put zero amount if you want to quit";
        std::cin >> position >> quantity;
        if (quantity == 0) {
            return;
        }
        auto cargo = store->getCargo(position);
        if (!cargo) {
            std::cout << "Wrong position or cargo does not exist";
            continue;
        }

        char answer = 'y';
        while (true) {
            std::cout << "The price is " << cargo->getPrice() * quantity
                      << " Are you sure want to sell it? [y/ other key] ";
            std::cin >> answer;
            if (std::tolower(answer) == 'y') {
                break;
            } else {
                return;
            }
        }

        switch (store->sell(cargo, quantity, player)) {
        case Store::Response::done:
	  std::cout << "Good one! You have sell " << cargo->getName() << " in quantity "
                      << quantity << "\n";
            return;

        case Store::Response::lack_of_money:
            std::cout << "You do not have enough money!";
            break;
        case Store::Response::lack_of_space:
            std::cout << "You do not have enough space!";
            break;
        case Store::Response::lack_of_cargo:
            std::cout << "You do  not have this cargo in given amount!!";
            break;
        }
    }
}
