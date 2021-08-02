#ifndef GAME_HPP
#define GAME_HPP
#include "Player.hpp"
#include "Time.hpp"
#include "Map.hpp"
#include "Action.hpp"
#include <memory>

class Game {

private:

size_t money_;
size_t days_;
size_t final_goal_;
size_t current_day_;
std::unique_ptr<Map> map_;
//std::unique_ptr<Map> time_;
//std::unique_ptr<Map> player_;

void CheckWinCondition() const;
bool CheckLooseCodition() const;
void PrintMenu();
void PrintOptions();
void PrintWinScreen();
void PrintLooseScreen();
void MakeAction(Action choice);
void Travel();
void Buy();
void Sell();
void PrintCargo();

public:

Game(size_t money, size_t days, size_t final_goal);
void startGame();

};

#endif