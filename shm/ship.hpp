#pragma once
#include <string>
#include <vector>

#include "cargo.hpp"

class Ship {
public:
    Ship();
    Ship(int capacity, int maxCrew, int speed, const std::string& name, size_t id);
    Ship(int maxCrew, int speed, size_t id);

    void setName(const std::string& name);

    Ship& operator-=(size_t crew);
    Ship& operator+=(size_t crew);

    size_t getId() const;
    std::string getName() const;
    size_t getSpeed() const;
    size_t getCrew() const;
    size_t getMaxCrew() const;
    size_t getCapacity() const;
    Cargo* getCargo(size_t index);
    std::vector<Cargo> getVectorCargo() const;

private:
    size_t id_;
    std::string name_;
    size_t speed_;
    size_t maxCrew_;
    size_t capacity_;
    size_t crew_;
    std::vector<Cargo> cargo_;
};
