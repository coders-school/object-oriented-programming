#pragma once

#include "Command.hpp"

class TradeSell : public Command {
public:
    TradeSell() = default;
    void operator()(Player& player, Store& store) override;
    std::string getName() const override;
};
