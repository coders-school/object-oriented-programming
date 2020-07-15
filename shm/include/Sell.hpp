#pragma once

#include "Command.hpp"

class Player;
class Map;

class Sell : public Command {
public:
    Sell(Map* map);

    // Overrides from Icommand
    ~Sell() override = default;
    void execute(Player* player) override;

private:
    Map* map_;
};
