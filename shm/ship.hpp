#pragma once

#include <memory>
#include <string>
#include <vector>

#include "cargo.hpp"

class Ship {
public:
    Ship();
    Ship(int maxCrew, int speed, size_t id, const std::string& name, int capacity);
    Ship(int maxCrew, int speed, size_t id);

    void setName(const std::string& name);
    Ship& operator+=(const size_t crew);
    Ship& operator-=(const size_t crew);

    size_t getCapacity() const { return capacity_; }
    size_t getMaxCrew() const { return maxCrew_; }
    size_t getSpeed() const { return speed_; }
    std::string getName() const { return name_; }
    size_t getId() const { return id_; }
    size_t getCrew() const { return crew_; }
    Cargo* getCargo(size_t index) { return cargo_[index].get(); }
    std::vector<std::shared_ptr<Cargo>> getCargos() const { return cargo_; }

private:
    size_t maxCrew_{};
    size_t speed_{};
    const size_t id_{};
    std::string name_{};
    size_t capacity_{};
    size_t crew_{};
    std::vector<std::shared_ptr<Cargo>> cargo_{};
};
