#pragma once

#include <memory>
#include <string>
#include <vector>

#include "shm/inc/Cargo.hpp"

//class responsible for manage ship(s) in game
class Ship {
public:
    Ship() = default;
    Ship(int id, const std::string& name, size_t speed, size_t maxCrew, size_t capacity);
    Ship(int id, size_t speed, size_t maxCrew);

    Ship& operator+=(const size_t amount);
    Ship& operator-=(const size_t amount);

    int getId() const { return id_; };
    std::string getName() const { return name_; };
    size_t getSpeed() const { return speed_; };
    size_t getMaxCrew() const { return maxCrew_; };
    size_t getCapacity() const { return capacity_; };
    std::shared_ptr<Cargo> getCargo(size_t index) const;
    std::vector<std::shared_ptr<Cargo>> getVectorCargo() const { return cargo_; };

    void setName(const std::string& name);

private:
    const int id_ { -1 };
    std::string name_;
    size_t speed_ { 50 };
    const size_t maxCrew_ { 100 };
    size_t crew_ { };
    const size_t capacity_ { 80 };
    std::vector<std::shared_ptr<Cargo>> cargo_;
};



