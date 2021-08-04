#include "NextDayCommand.hpp"
#include "../GeneralPrint.hpp"

void NextDay::operator()([[maybe_unused]] Player &player, [[maybe_unused]] Store &store) {
    Time::getInstance()->nextDay();
}

std::string NextDay::getName() const { 
    return "Next day"; 
}
