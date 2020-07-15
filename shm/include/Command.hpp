#pragma once

class Player;

class Command {
public:
    virtual ~Command() {}
    virtual void execute(Player* player) = 0;
};
