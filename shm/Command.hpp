#pragma once

class Command {
public:
    Command() = default;
    virtual ~Command() = default;
    virtual void operator()(Player& player, Store& store) = 0;
    virtual std::string getName() const { return {}; }
    virtual void print() const { return; };
};
