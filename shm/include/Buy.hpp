#pragma once

#include "Command.hpp"

class Map;

class Buy : public Command {
public:
    Buy(Map* map);

    // Overrides from ICommand
    ~Buy() override = default;
    void execute(Player* player) override;

private:
    Map* map_;
};
