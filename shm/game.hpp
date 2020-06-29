#include "map.hpp"
#include "player.hpp"
#include "timeSHM.hpp"

class Game {
public:
    Game(size_t money, size_t days, size_t finalGoal);

    void startGame();

private:
    size_t money_;
    size_t days_;
    const size_t finalGoal_;
    size_t currentDay_;
    Map* map_;
    Player* player_;
    Time* time_;

    void printTrail();
    void printStars();
    bool checkWinConditions() const;
    void printWinScreen();
    bool checkLoseConditions() const;
    void printLoseScreen();
    void printMenu();
    // void printOptions();
    // void makeAction(Action choice);
    // void travel();
    // void buy();
    // void sell();
    // void printCargo();
};
