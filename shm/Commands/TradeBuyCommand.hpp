#pragma once

#include "Command.hpp"

class TradeBuy : public Command {
public:
    TradeBuy() = default;
    void operator()(Player& player, Store& store) override;
    std::string getName() const override;
};
