#include "TravelCommand.hpp"
#include "GeneralPrint.hpp"

void Travel::operator()([[maybe_unused]] Player& player, [[maybe_unused]] Store& store) {
    for (size_t day = 1; day <= distance; ++day) {
        nextDay(player, store);
        std::cout << "Day " << day << " on travel\n";
    }
}

std::string Travel::getName() const { 
    return "Travel"; 
}
