#pragma once

#include <cstddef>

namespace constValues {

    //coordinates
    constexpr int defaultPositionX = 0;
    constexpr int defaultPositionY = 0;
    //crew
    constexpr size_t dailySalary = 1;
    constexpr size_t hiringCost = 5;
    //map
    constexpr int initialAmountOfIsland = 10;
    constexpr int maxX = 100;
    constexpr int maxY = 100;
    //minigame
    constexpr size_t pointsToGetMoneyInDiceGame = 150;
    constexpr size_t moneyForWinInDiceGame = 100;
    //store generator
    constexpr size_t numerOfItems = 4;
    constexpr size_t minExpiryDate = 2;
    constexpr size_t maxExpiryDate = 20;
    constexpr size_t minAmount = 0;
    constexpr size_t maxAmount = 1000;
    constexpr double sellPriceFactor = 0.95;
} 

