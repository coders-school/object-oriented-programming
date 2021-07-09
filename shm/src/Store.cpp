#include "shm/inc/Store.hpp"

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

Item::Rarity Store::rarityCoversion(size_t numberForConversion) {
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
    std::vector<std::string>dataToCreateItems(8, "");
    size_t iterator{};
    for (size_t i = 0; i < lineFromFile.size(); i++) {
        if (lineFromFile[i] != ' ') {
            dataToCreateItems[iterator] += lineFromFile[i];
        } else {
            iterator++;
        }
    }
    generateSingleCargo(dataToCreateItems);
}

void Store::generateSingleCargo(std::vector<std::string>const & cargo) {
    if (cargo[0] == "Fruit"){
        generateFruit(cargo);
    } else if (cargo[0] == "Alcohol"){
        generateAlcohol(cargo);
    } else if (cargo[0] == "Item"){
        generateItem(cargo);
    } else {
        generateDryFruits(cargo);
    }
}

void Store::generateFruit(std::vector<std::string>const & cargo) {
    cargo_.push_back(std::make_unique<Fruit>(Fruit(cargo[1], 
                        randomGenerate(std::stol(cargo[2]), std::stol(cargo[3])), 
                        randomGenerate(std::stol(cargo[4]), std::stol(cargo[5])))));
}

void Store::generateAlcohol(std::vector<std::string>const & cargo) {
    cargo_.push_back(std::make_unique<Alcohol>(Alcohol(cargo[1], 
                        randomGenerate(std::stol(cargo[2]), std::stol(cargo[3])), 
                        randomGenerate(std::stol(cargo[4]), std::stol(cargo[5])), std::stol(cargo[6]))));
}

void Store::generateItem(std::vector<std::string>const & cargo) {
    cargo_.push_back(std::make_unique<Item>(Item(cargo[1], 
                        randomGenerate(std::stol(cargo[2]), std::stol(cargo[3])), 
                        randomGenerate(std::stol(cargo[4]), std::stol(cargo[5])), 
                        rarityCoversion(randomGenerate(std::stol(cargo[6]), std::stol(cargo[7]))))));
}

void Store::generateDryFruits(std::vector<std::string>const & cargo) {
    cargo_.push_back(std::make_unique<DryFruit>(DryFruit(cargo[1], 
                        randomGenerate(std::stol(cargo[2]), std::stol(cargo[3])), 
                        randomGenerate(std::stol(cargo[4]), std::stol(cargo[5])))));
}
