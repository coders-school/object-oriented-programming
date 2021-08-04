#pragma once

#include "Command.hpp"

class NextDay : public Command {
public:
    NextDay() = default;
    void operator()([[maybe_unused]] Player& player, [[maybe_unused]] Store& store) override;
    std::string getName() const override;
};
