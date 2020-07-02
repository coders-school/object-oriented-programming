#pragma once
#include <memory>
#include <string>

#include "map.hpp"
#include "player.hpp"
#include "store.hpp"

class Game {
private:
    uint32_t money_;
    uint32_t days_;
    uint32_t target_;

    std::shared_ptr<Ship> ship_ = std::make_shared<Ship>(200, 50, 180, "black pearl", 1);
    std::shared_ptr<Player> player_ = std::make_shared<Player>(ship_, 300, 80);
    Store store_;
    Map map_;

public:
    enum class Action { Buy = 1, Sell = 2, Travel = 3, Exit = 0 };

    Game(uint32_t money, uint32_t days, uint32_t target);
    ~Game() = default;
    void startGame();
    void printMenu();
    void printOption();
    void makeAction(Action choice);
    void buy();
    void sell();
    void travel();
};
