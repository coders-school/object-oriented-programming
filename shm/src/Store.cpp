#include "shm/inc/Store.hpp"

#include <algorithm>
#include <cstddef>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>

#include "shm/inc/Alcohol.hpp"
#include "shm/inc/Cargo.hpp"
#include "shm/inc/DryFruit.hpp"
#include "shm/inc/Fruit.hpp"
#include "shm/inc/Player.hpp"

Store::Store(const size_t & storeSize)
{
    cargo_.reserve(storeSize);
    generateAllCargo();
}

std::ostream& operator<<(std::ostream& out, const Store& store){
    for (size_t i = 0; i < store.cargo_.size(); i++) {
        out << "|" << std::setfill('-') << std::setw (100) << "|\n";
        out << std::setfill(' ')<< std::setw (10) << "| ID: " << i + 1;
        out << std::setw (30) << " | CARGO NAME: " << store.cargo_[i]->getName();
        out << std::setw (10) << " | AMOUNT: " << store.cargo_[i]->getAmount();
        out << std::setw (10) << " | PRICE: " << store.cargo_[i]->getPrice() << " |\n";
    }
    out << "|" << std::setfill('-') << std::setw (100) << "|\n";
    return out;
}

Store::Response Store::buy(Cargo* cargo, size_t amount, Player* player) {
    if (!cargo) {
        return Response::lack_of_cargo;
    }
    if (amount * cargo->getPrice() > player->getMoney()){
        return Response::lack_of_money;
    }
    if (cargo->getAmount() < amount) {
        return Response::lack_of_cargo;
    }
    if (player->getAvailableSpace() < amount) {
        return Response::lack_of_space;
    }
    return Response::done;   
}

Store::Response Store::sell(Cargo* cargo, size_t amount, Player* player) {
    if (!cargo) {
        return Response::lack_of_cargo;
    }
    if (cargo->getAmount() + amount > STORE_CAPACITY) {
        return Response::lack_of_space;
    }
    return Response::done;
}

Cargo* Store::getCargo(const std::string& name) const {
    auto result{ std::find_if(cargo_.begin(), cargo_.end(),
                             [&name](const auto& cargo) {
                                return cargo->getName() == name ;
                             })
    };
    
    return result != cargo_.end() ? result->get() : nullptr;
}

void Store::nextDay() {
    for (const auto& cargo : cargo_) {
        cargo->setAmount(randomGenerate(MIN_CARGO_IN_STORE, MAX_CARGO_IN_STORE));
    }
}

size_t Store::randomGenerate(size_t min, size_t max) {
    std::mt19937 gen(std::random_device{}()); 
    std::uniform_int_distribution<size_t> distribution(min, max);
    return distribution(gen);
}

Item::Rarity Store::rarityConversion(size_t numberForConversion) {
    size_t multiplyRarity = 4;
    size_t addRarity = 1;
    return static_cast<Item::Rarity>((numberForConversion * multiplyRarity) + addRarity);
}

void Store::generateAllCargo() {
    std::string line;
    std::fstream file;
    file.open("settings/items.txt", std::ios::in);
    if (file.good() == false) {
        std::cout << "File not exist\n";
    }
    while (getline(file, line)) {
        convertDataFromFile(line);
    }
    file.close();
}

void Store::convertDataFromFile(std::string lineFromFile) {
    std::string singleWordFromFile;
    size_t wordNumber{};
    for (size_t i = 0; i < lineFromFile.size(); i++) {
        if (lineFromFile[i] != ' ') {
            singleWordFromFile += lineFromFile[i];
        } else {
            wordNumber++;
            valueOneLineAssignment(wordNumber, singleWordFromFile);
            singleWordFromFile = "";
        }
    }
    generateSingleCargo();
}

void Store::valueOneLineAssignment(const size_t & wordNumber, const std::string & singleWordFromFile) {
    switch (wordNumber) {
        case 1 : {
            oneLine_.className_ = singleWordFromFile;
        } break;
        case 2 : {
            oneLine_.itemName_ = singleWordFromFile;
        } break;
        case 3 : {
            oneLine_.minAmount_ = std::stol(singleWordFromFile); 
        } break;
        case 4 : {
            oneLine_.maxAmount_ = std::stol(singleWordFromFile);
        } break;
        case 5 : {
            oneLine_.minPrice_ = std::stol(singleWordFromFile);
        } break;
        case 6 : {
            oneLine_.maxPrice_ = std::stol(singleWordFromFile);
        } break;
        case 7 : {
            oneLine_.minUniqueStat_ = std::stol(singleWordFromFile);
        } break;
        case 8 : {
            oneLine_.maxUniqueStat_= std::stol(singleWordFromFile);
        } break;
        default : {
        } break;
    }
}

void Store::generateSingleCargo() {
    
    if (oneLine_.className_ == "Fruit"){
        generateFruit();
    } else if (oneLine_.className_ == "Alcohol"){
        generateAlcohol();
    } else if (oneLine_.className_ == "Item"){
        generateItem();
    } else {
        generateDryFruits();
    }
}

void Store::generateFruit() {
    cargo_.push_back(std::make_unique<Fruit>(Fruit(oneLine_.itemName_, 
                        randomGenerate(oneLine_.minAmount_, oneLine_.maxAmount_), 
                        randomGenerate(oneLine_.minPrice_, oneLine_.maxPrice_))));
}

void Store::generateAlcohol() {
    cargo_.push_back(std::make_unique<Alcohol>(Alcohol(oneLine_.itemName_, 
                        randomGenerate(oneLine_.minAmount_, oneLine_.maxAmount_), 
                        randomGenerate(oneLine_.minPrice_, oneLine_.maxPrice_), oneLine_.minUniqueStat_)));
}

void Store::generateItem() {
    cargo_.push_back(std::make_unique<Item>(Item(oneLine_.itemName_, 
                        randomGenerate(oneLine_.minAmount_, oneLine_.maxAmount_), 
                        randomGenerate(oneLine_.minPrice_, oneLine_.maxPrice_), 
                        rarityConversion(randomGenerate(oneLine_.minUniqueStat_, oneLine_.maxUniqueStat_)))));
}

void Store::generateDryFruits() {
    cargo_.push_back(std::make_unique<DryFruit>(DryFruit(oneLine_.itemName_, 
                        randomGenerate(oneLine_.minAmount_, oneLine_.maxAmount_), 
                        randomGenerate(oneLine_.minPrice_, oneLine_.maxPrice_))));
}
