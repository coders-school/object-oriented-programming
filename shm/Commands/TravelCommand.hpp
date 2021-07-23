#pragma once

#include "Command.hpp"
#include "../GeneralPrint.hpp"
#include "NextDayCommand.hpp"

class Travel : public Command {
public:
    Travel() = default;
    void operator()([[maybe_unused]] Player& player, [[maybe_unused]] Store& store) override {
        for (size_t day = 1; day <= distance; ++day) {
            nextDay(player, store);
            std::cout << "Day " << day << " on travel\n";
        }
    }

    std::string getName() const override { return "Travel"; }

private:
    NextDay nextDay;
    size_t distance = 5;//for show concept
};
