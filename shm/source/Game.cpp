#include "Game.hpp"
#include "Observer.hpp"

Game::Game(const size_t startMoney, 
	const size_t gameDays, 
	const size_t finalGoal):
		money_(startMoney),
		days_(gameDays),
		final_goal_(finalGoal),
		current_day_(1),
		map_(std::make_unique<Map>()),
		time_(std::make_unique<Time>()),
		player_(std::make_unique<Player>())
{}

void Game::startGame() {
	printMenu();
	while (true) {
		int action;
		std::cin >> action;
		if (action == 10) {
			continue;
		}
		makeAction(static_cast<Action>(action - 1));
		if (!printMenu()) {
			return;
		}
	}
}

bool Game::winCondition() const {
	return money_ >= final_goal_; 
}

bool Game::looseCodition() const {
	return money_ == 0;		
}

bool Game::printMenu() {
	if (looseCodition()) {
		printLooseScreen();
		return false;
	}
	if (winCondition()) {
		printWinScreen();
		return false;
	}
	printOptions();
	return true;
}

void Game::printOptions() {
	std::cout << "\n Choose Action:"
		<< "\n |   [1] Buy"
		<< "\n |   [2] Sell"
		<< "\n |   [3] Travel"
		<< "\n   "; 
}

void Game::printWinScreen() {
	std::cout << "\n CONGRATULATIONS!!!"
		<< "\n |   Gold collected: " << money_
		<< "\n |   Days passed: " << current_day_
		<< "\n"; 
}

void Game::printLooseScreen() {
	std::cout << "\n GAME OVER"
		<< "\n |   Gold collected: " << money_
		<< "\n |   Days passed: " << current_day_
		<< "\n"; 
}

void Game::printCargo() {}

void Game::makeAction(Action choice) {
	switch (choice) {
	case Action::Buy:
		buy();
		return;
	
	case Action::Sell:
		sell();
		return;
	
	case Action::Travel:
		travel();
		return;

	default:
		std::cout << "\n Wrong Action! \n";
		return;
	}
}

void Game::buy() {}

void Game::sell() {}

void Game::travel() {}