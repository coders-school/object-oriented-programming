#pragma once

#include "Command.hpp"
#include "../GeneralPrint.hpp"

class NextDay : public Command {
public:
    NextDay() = default;
    void operator()([[maybe_unused]] Player& player, [[maybe_unused]] Store& store) override {
        Time::getInstance()->nextDay();
    }

    std::string getName() const override { return "Next day"; }
};
