#include <array>
#include <iostream>
#include <map>
#include <vector>

//no bonus points, no second & third general

class diceGame {
public:
    bool startDiceGame(size_t pointsToGetMoney, size_t prize);

private:
    char makeSure();
    void gameLoop();
    size_t singleRoll();
    void reRoll();
    void playRound();
    void fullRoll();
    void showResultOfRoll();
    void calculateScores(size_t category);
    void printStatus();
    void printCategories();
    void pickDiceCategory();
    void endScreen();

    size_t roundNumber_ {0};
    size_t overallScore_ {0};
    size_t throwCounter_ {0};
    std::vector<size_t> actualRoundResult_ {5};
    std::array<size_t, 14> category_ {0};
};