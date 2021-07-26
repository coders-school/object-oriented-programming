#pragma once

#include <iostream>
#include <memory>

#include "Map.hpp"
#include "Player.hpp"

class Game {
	size_t money_;
	size_t days_;
	size_t final_goal_;

	size_t current_day_;
	std::unique_ptr<Map> map_;
	std::unique_ptr<Player> player_;

	enum class Action {
		Buy,
		Sell,
		Travel
	};

public:
	Game(const size_t startMoney, 
		const size_t gameDays, 
		const size_t finalGoal);

	void startGame();

private: 
	bool winCondition() const;

	bool looseCodition() const;

	bool printMenu();

	void printOptions();

	void printWinScreen();

	void printLooseScreen();

	void printCargo();

	void makeAction(Action choice);
	
	void buy();
	
	void sell();
	
	void travel();
};