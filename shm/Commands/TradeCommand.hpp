#pragma once

#include "Command.hpp"
#include "../GeneralPrint.hpp"

class Trade : public Command {
public:
    Trade() = default;
    void operator()([[maybe_unused]]Player& player, [[maybe_unused]]Store& store) override {
    }

    std::string getName() const override { return "Go to store"; }
};
