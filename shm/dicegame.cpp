#include "dicegame.hpp"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <numeric>
#include <random>

#include "game.hpp"

constexpr size_t numberOfRounds = 13;

constexpr size_t fulPoints = 25;
constexpr size_t smallStritePoints = 30;
constexpr size_t bigStritePoints = 40;
constexpr size_t generalPoints = 50;


bool diceGame::startDiceGame(size_t pointsToGetMoney, size_t prize) {
    char answer = makeSure();
    std::cout << "If you will get " << pointsToGetMoney << " points I will give you a " << prize << " coins!!!\n\n";
    if (std::toupper(answer) == 'Y') {
        gameLoop();
        endScreen();
        if (overallScore_ > pointsToGetMoney) {
            return true;
        }
    }
    return false;
}

char diceGame::makeSure() {
    std::cout << "I've heard you wanna play dices. You sure? [Y/N]\n";
    char answer;
    std::cin >> answer;
    Game::inputValidator();
    std::cout << '\n';
    return answer;
}

void diceGame::gameLoop() {
    std::cout << "All, right, let's roll... \n" << std::setw(31) << "...\n" << std::setw(37) << "...\n\n";
    while (true) {
        playRound();
        if (roundNumber_ == numberOfRounds) {
            break;
        }
    }
}

void diceGame::playRound() {
    fullRoll();
    showResultOfRoll(); 
    reRoll();
    pickDiceCategory();
    ++roundNumber_;
    printStatus();
    std::cout << ">>>>>>>>>>>>>Next round!<<<<<<<<<<<<<\n\n"
              << std::setw(14) << "...\n" << std::setw(22) << "...\n" << std::setw(30) << "...\n\n";
}

size_t diceGame::singleRoll() {
    std::random_device numbers;
    std::mt19937 dice(numbers());
    std::uniform_int_distribution<> singleRoll(1, 6);
    return singleRoll(dice);
}

void diceGame::reRoll() {
    for (size_t i = 0; i < 2; i++) {
        std::cout << "How many dices ya wanna roll again? \n" << "  [0 - none - go to next round]\n";
        size_t howManyDices;
        std::cin >> howManyDices;
        Game::inputValidator();
        if (howManyDices == 0) {
            showResultOfRoll();
            break;
        }
        if (howManyDices == 5) {
            std::cout << std::setw(22) << "...\n\n";
            fullRoll();
        } else {
            std::cout << "Which result?\n";
            size_t dice;
            for (size_t j = 0; j < howManyDices; j++) {
                std::cin >> dice;
                Game::inputValidator();
                actualRoundResult_.erase(std::find(actualRoundResult_.begin(), actualRoundResult_.end(), dice));
            }
            for (size_t k = 0; k < howManyDices; k++) {
                actualRoundResult_.push_back(singleRoll());
            }
        }
        std::cout << std::setw(22) << "...\n\n";
        showResultOfRoll();
    }
}

void diceGame::fullRoll() {
    actualRoundResult_.clear();
    for (auto i = 0; i < 5; i ++) {
        actualRoundResult_.push_back(singleRoll());
    }
}

void diceGame::showResultOfRoll(){
    std::cout << " Your dices: ";
    for (auto el : actualRoundResult_) {
        std::cout << '[' << el << ']' << ' ';
    }
    std::cout << "\n\n";
}

void diceGame::calculateScores(size_t category) {
    size_t allDiceSum = std::accumulate(actualRoundResult_.begin(), actualRoundResult_.end(), 0);
    size_t theSameDice = std::count(actualRoundResult_.begin(), actualRoundResult_.end(), category);
    size_t counterFirstEl = std::count(actualRoundResult_.begin(), actualRoundResult_.end(), *actualRoundResult_.begin());
    size_t counterSecEl = std::count(actualRoundResult_.begin(), actualRoundResult_.end(), *std::next(actualRoundResult_.begin()));
    size_t counterLastEl = std::count(actualRoundResult_.begin(), actualRoundResult_.end(), *actualRoundResult_.rbegin());

    size_t roundPoints = 0;

    std::sort(actualRoundResult_.begin(), actualRoundResult_.end());
    auto uniqCounter = std::unique(actualRoundResult_.begin(), actualRoundResult_.end());
    actualRoundResult_.erase(uniqCounter, actualRoundResult_.end());

    switch (category) {
        case 1: 
        case 2:
        case 3:
        case 4:
        case 5:
        case 6: {
            roundPoints = theSameDice * category;
            break;
        }
        case 7: {
            if (counterFirstEl > 2 || counterSecEl > 2 || counterLastEl >2) {
                roundPoints = allDiceSum;
            }  
            break;
        }
        case 8: {
            if (counterFirstEl == 4 || counterLastEl == 4) {
                roundPoints = allDiceSum;
            }
            break;
        }
        case 9: {
            if (counterFirstEl > 1 && counterFirstEl < 4 && actualRoundResult_.size() == 2) {
                roundPoints = fulPoints;
            }
            break;
        }
        case 10: {
            if (actualRoundResult_.size() == 4) {
                auto partialSum = std::accumulate(actualRoundResult_.begin(), actualRoundResult_.end(), 0);
                if (partialSum == 10 || partialSum == 14 || partialSum == 18) {
                    roundPoints = smallStritePoints;
                }
            }
            if (actualRoundResult_.size() == 5) {
                roundPoints = smallStritePoints;
            }
            break;
        }
        case 11: {
            if (actualRoundResult_.size() == 5) {
                roundPoints = bigStritePoints;
            }
            break;
        }
        case 12: {
            if (actualRoundResult_.size() == 1) {
                roundPoints = generalPoints;
            }
            break;
        }
        case 13: {
            roundPoints = allDiceSum;
            break;
        }
        default: {
            std::cout << "Sth went wrong.\n";
        }
    }
    overallScore_ += roundPoints;
    std::cout << "You won " << roundPoints << " points.\n";
}

void diceGame::printStatus() {
    std::cout << "\n**After round " << roundNumber_ << " You have " << overallScore_ << " points.**\n\n";
}

void diceGame::pickDiceCategory() {
    while (true) {
        std::cout << "\nPick calculate category. (0 - free, 1 - used)\n" << "[14 - resign, but no money and you lost!]\n";
        printCategories();
        size_t playerChoice;
        std::cin >> playerChoice;
        Game::inputValidator();
        if (playerChoice == 14) {
            roundNumber_ = 14;
            break;
        } else if (playerChoice > 0 && playerChoice < 14) {
            if (category_[playerChoice] == 0) {
                category_[playerChoice] = 1;
                calculateScores(playerChoice);
                break;
            } else {
                std::cout << "You have used this category before. \n" << "Choose another one. \n";
            }
        }
    }
}

void diceGame::printCategories() {
    std::cout << "---------------------------------------------\n"
              << "1. Ones:   " << category_[1] << " || " 
              << "2. Twos:  " << category_[2] << " || "
              << "3. Trees: " << category_[3] << " || " << '\n'
              << "4. Foures: " << category_[4] << " || "
              << "5. Fives: " << category_[5] << " || "
              << "6. Sixes: " << category_[6] << " || " << '\n'
              << "---------------------------------------------\n"
              << "7. Three same:   " << category_[7] << " || "
              << "8. Four same:      " << category_[8] << " || " << '\n'
              << "9. Ful:          " << category_[9] << " || "
              << "10. Small strite:  " << category_[10] << " || " << '\n'
              << "11. Big strite:  " << category_[11] << " || "
              << "12. General:       " << category_[12] << " || " << '\n'
              << "13. Chance:      " << category_[13] << " || " << std::setw(24) << "||\n"
              << "---------------------------------------------\n";
}

void diceGame::endScreen() {
    std::cout << "well... after all that throws you have " << overallScore_ 
              << ",\ndo you think you can do better next time? \n";
}
