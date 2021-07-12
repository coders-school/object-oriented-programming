#pragma once

#include "DefaultCargo.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "Store.hpp"

#include <array>
#include <cmath>
#include <iostream>

constexpr size_t start_money = 10'000;
constexpr size_t game_days = 100;
constexpr size_t final_goal = 20'000;

// Return by value to give up ownership
std::unique_ptr<Cargo> generateCargo();

class Game {
public:
    Game(size_t startMoney, size_t daysLimit, size_t goal)
        : startMoney_(startMoney), daysLimit_(daysLimit), goal_(goal) {}

    void startGame();

    void init();

    void ShowOption();
    void BuyOption();
    void SellOption();

    void printResponse(Response response) const;
    void printPlayerStatus() const;
    void printMenu() const;
    void printStoreCargoList() const;
    void printShipCargoList() const;

    size_t ChoseOption(size_t limit) const;
    Cargo* ChoseCargoFromStore(size_t chose);
    Cargo* ChoseCargoFromShip(size_t chose);

private:
    size_t startMoney_;
    size_t daysLimit_;
    size_t goal_;
    bool endGame = false;
    bool playerWin = false;

    Map map{};
    Player player = Player{std::make_unique<Ship>(), startMoney_};
    Store store{};
};