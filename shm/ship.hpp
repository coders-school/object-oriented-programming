#pragma once
#include <memory>
#include <string>
#include <vector>

#include "cargo.hpp"

class Ship {
public:
    Ship(uint32_t capacity, uint32_t maxCrew, uint32_t speed, const std::string& name, uint32_t id);
    Ship(uint32_t maxCrew, uint32_t speed, uint32_t id);
    Ship();

    void setName(const std::string& name);
    Ship& operator-=(uint32_t crew);
    Ship& operator+=(uint32_t crew);

    uint32_t getId() const;
    std::string getName() const;
    uint32_t getSpeed() const;
    uint32_t getCrew() const;
    uint32_t getMaxCrew() const;
    uint32_t getCapacity() const;
    std::shared_ptr<Cargo> getCargo(size_t index) const;
    std::vector<std::shared_ptr<Cargo>> getVectorCargo() const;

    void load(std::shared_ptr<Cargo> cargo);
    void unload(std::shared_ptr<Cargo> cargo, uint32_t amount);
    void printCargo() const;

private:
    uint32_t capacity_;
    uint32_t maxCrew_;
    uint32_t crew_;
    uint32_t speed_;
    std::string name_;
    uint32_t id_;
    std::vector<std::shared_ptr<Cargo>> cargo_;
    // std::vector<Cargo> cargo_;
};
