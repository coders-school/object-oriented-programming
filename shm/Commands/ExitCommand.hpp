#pragma once

#include "Command.hpp"
#include "../GeneralPrint.hpp"

class Exit : public Command {
public:
    Exit(bool& endGame): endGame_(endGame){}
    ~Exit() override = default;

    void operator()([[maybe_unused]] Player& player, [[maybe_unused]] Store& store) override {
        endGame_ = true;
    }

    std::string getName() const override { return "End game"; }

private:
    bool& endGame_;
};