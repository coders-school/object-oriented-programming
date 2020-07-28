#pragma once

#include <memory>

#include "map.hpp"
#include "player.hpp"
#include "store.hpp"
#include "time.hpp"

class Game {
public:
    Game(size_t money, size_t days, size_t final_goal);
    ~Game() = default;

    void startGame();

private:    
    enum class Action { Travel = 1,
                        Sell = 2,
                        Buy = 3,
                        ShipCargo = 4,
                        StoreCargo = 5,
                        Exit = 0 };

    bool checkWinCondition() const;  
    bool checkLooseCodition() const;
    void printInfo();
    void printOptions();
    void printWonScreen();
    void printLostScreen();
    void makeAction(Action choice);
    void travel();
    void buy();
    void sell();
    bool printShipCargo();
    void printStore(const Store& store);

    size_t money_;
    size_t days_;
    size_t final_goal_;
    size_t current_day_;
    std::unique_ptr<Map> map_;
    std::unique_ptr<Time> time_;
    std::shared_ptr<Player> player_;
    std::unique_ptr<Store> store_;

    std::unique_ptr<Ship> ship_;
};