#include "map.hpp"
#include "player.hpp"
#include "ship.hpp"
#include "timeSHM.hpp"


class Game {
public:
    enum class Action {
        exit = 0,
        travel = 1,
        buy = 2,
        sell = 3,
        printCargo = 4
    };

    Game(size_t money, size_t days, size_t finalGoal);

    void startGame();

private:
    size_t money_ {0};
    size_t days_ {0};
    const size_t finalGoal_ {0};
    size_t currentDay_ {0};
    std::shared_ptr<Map> map_;
    std::shared_ptr<Ship> ship_ = std::make_shared<Ship>(150, 50, 13, "Player_ship", 1);
    std::shared_ptr<Player> player_ = std::make_shared<Player>(ship_, 500, 200);
    std::shared_ptr<Time> time_;

    void printTrail();
    void printStars();
    bool checkWinConditions() const;
    void printWinScreen();
    bool checkLoseConditions() const;
    void printLoseScreen();
    void printMenu();
    void printOptions();
    void makeAction(Action pickAction);
    void travel();
    void buy();
    void sell();
    void printCargo();
};
