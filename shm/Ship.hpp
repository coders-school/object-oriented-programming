#pragma once

#include <string>

#include "Cargo.hpp"

class Ship
{
public:
    Ship();
    Ship(int capacity, int maxCrew, int speed, const std::string& name, size_t id);
    Ship(int maxCrew, int speed, size_t id);

    void setName(const std::string& name);

    Ship& operator-=(size_t num);
    Ship& operator+=(size_t num);

    [[nodiscard]] size_t getCapacity() const { return capacity_; }
    [[nodiscard]] size_t getMaxCrew() const { return maxCrew_; }
    [[nodiscard]] size_t getSpeed() const { return speed_; }
    [[nodiscard]] std::string getName() const { return name_; }
    [[nodiscard]] size_t getId() const { return id_; }

    [[nodiscard]] Cargo* getCargo(size_t index) const { return storage_.at(index); }
    [[nodiscard]] std::vector<Cargo*> getCargos() const { return storage_; }

private:
    size_t capacity_;
    size_t maxCrew_;
    size_t crew_;
    size_t speed_;
    std::string name_;
    const size_t id_;
    std::vector<Cargo*> storage_;
};
