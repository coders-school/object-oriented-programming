#pragma once

#include "Command.hpp"
#include "NextDayCommand.hpp"
class Travel : public Command {
public:
    Travel() = default;
    void operator()([[maybe_unused]] Player& player, [[maybe_unused]] Store& store) override;
    std::string getName() const override;

private:
    NextDay nextDay;
    size_t distance = 5;//for show concept
};
