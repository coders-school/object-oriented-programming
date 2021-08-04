#pragma once

#include "Command.hpp"

class Exit : public Command {
public:
    Exit(bool& endGame): endGame_(endGame){}
    ~Exit() override = default;

    void operator()([[maybe_unused]] Player& player, [[maybe_unused]] Store& store) override;
    std::string getName() const override;

private:
    bool& endGame_;
};
