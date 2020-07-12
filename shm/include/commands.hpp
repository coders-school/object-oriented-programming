#pragma once

#include "map.hpp"
#include "player.hpp"

class ICommand {
public:
    virtual ~ICommand() {}
    virtual void execute(Player* player) = 0;
};

class Buy : public ICommand {
public:
    Buy(Map* map);

    // Overrides from ICommand
    ~Buy() override = default;
    void execute(Player* player) override;
    void displayStore(std::shared_ptr<Store> store);

private:
    Map* map_;
};

class Sell : public ICommand {
public:
    Sell(Map* map);

    // Overrides from Icommand
    ~Sell() override = default;
    void execute(Player* player) override;

private:
    Map* map_;
};

class Travel : public ICommand {
public:
    Travel(Map* map, Time* time);

    // Overrides from ICommand
    ~Travel() override = default;
    void execute(Player* player) override;

private:
    Map* map_;
    Time* time_;
};

class PrintCargo : public ICommand {
public:
    // Overrides from ICommand
    ~PrintCargo() override = default;
    void execute(Player* player) override;
};
