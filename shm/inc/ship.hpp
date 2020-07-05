#pragma once

#include <string>
#include <memory>
#include <vector>
#include <algorithm>
#include <iostream>

#include "cargo.hpp"
#include "common.hpp"

class Ship {
public:
    Ship();
    Ship(int maxCrew, int speed, size_t id);
    Ship(int capacity, int maxCrew, int speed,
         const std::string& name, size_t id);

    Ship& operator-=(const size_t crew);
    Ship& operator+=(const size_t crew);

    void setName(const std::string& name);
    
    size_t getCapacity() const;
    size_t getMaxCrew() const;
    size_t getSpeed() const;
    std::string getName() const;
    size_t getId() const;
    
    Cargo* getCargo(const std::string& name);
    size_t getAvailableSpace() const;

    void printCargo() {Common::printCargo(cargo_);}
    bool addCargo(Cargo* cargo);
    bool removeCargo(Cargo* cargo);

    void cloneCargo(Cargo* cargo);

private:
    size_t capacity_;
    size_t maxCrew_;
    size_t crew_;
    size_t speed_;
    std::string name_;
    const size_t id_;
    // std::vecto/r<std::shared_ptr<Cargo>> cargo_;
    std::vector<Cargo*> cargo_;
};
