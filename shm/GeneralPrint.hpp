#pragma once

#include "Player.hpp"
#include "Store.hpp"
#include "Command.hpp"
#include <map>

void printResponse(Response response);
void printPlayerStatus(const Player &player);
void printPlayerGoal(size_t goal);
void printMenu(std::map<std::string, std::unique_ptr<Command>> &commands);
void printStoreCargoList(const Store &store);
void printShipCargoList(const Player &player);

//universal function to get value in range from user
size_t ChoseOption(size_t limit);
const Cargo *ChoseCargoFromStore(size_t chose, Store &store);
const Cargo *ChoseCargoFromShip(size_t chose, Player &player);
