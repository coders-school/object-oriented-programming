#pragma once

#include <string>
#include <memory>
#include <vector>

#include "Cargo.hpp"

class Ship {
public:
    size_t getId() const;
    std::string getName() const;
    size_t getSpeed() const;
    size_t getMaxCrew() const;
    size_t getCapacity() const;
    void setName(const std::string& name);
    Cargo* getCargo(size_t index) const;
    size_t getCargoWeight() const;

    Ship();
    Ship(int id, const std::string& name, size_t speed, size_t maxCrew, size_t capacity);
    Ship(int id, size_t speed, size_t maxCrew);

    Ship& operator+=(const int crew);
    Ship& operator-=(const int crew);

private:
    int id_;
    std::string name_;
    size_t speed_;
    size_t maxCrew_;
    size_t capacity_;
    size_t crew_;
    std::vector<std::shared_ptr<Cargo>> cargo_;
};
