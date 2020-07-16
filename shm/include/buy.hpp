#pragma once

#include <memory>

#include "command.hpp"
#include "store.hpp"

class Map;

class Buy : public Command {
public:
    Buy(Map* map);

    // Overrides from ICommand
    ~Buy() override = default;
    void execute(Player* player) override;
    void displayStore(std::shared_ptr<Store> store);

private:
    Map* map_;
};
