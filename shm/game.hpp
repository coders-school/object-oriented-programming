#include "map.hpp"
#include "player.hpp"
#include "ship.hpp"
#include "timeSHM.hpp"

class Game {
public:
    Game(size_t money, size_t days, size_t finalGoal);

    void startGame();

private:
    size_t money_ {0};
    size_t days_ {0};
    const size_t finalGoal_ {0};
    size_t currentDay_ {0};
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
    void printOptions();
    void makeAction(size_t choice);
    void travel();
    void buy();
    void sell();
    void printCargo();
};
