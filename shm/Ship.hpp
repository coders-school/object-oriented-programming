#pragma once
#include <memory>
#include <string>
#include <vector>

#include "Time.hpp"
#include "Timeable.hpp"
#include "Warehouse.hpp"

class Cargo;

class Ship : public Warehouse,
             public Timeable {
public:
    using CargoVec = std::vector<std::unique_ptr<Cargo>>;
    Ship() = default;
    Ship(CargoVec cargoVec, size_t capacity, size_t maxCrew, size_t speed, const std::string& name, const size_t id);
    Ship(size_t maxCrew, size_t speed, const size_t id);
    Ship(size_t capacity, size_t maxCrew, size_t speed, const std::string& name, size_t id, CargoVec cargoVec);
    ~Ship() override = default;

    void setName(const std::string& name);

    //both operators throw std::invalid_argument. if you will use operators remember about try-catch.
    Ship& operator-=(size_t numCrew);
    Ship& operator+=(size_t numCrew);

    size_t getCapacity() const;
    size_t getMaxCrew() const;
    size_t getSpeed() const;
    const std::string& getName() const;
    size_t getId() const;
    const CargoVec& getCargoVec() const;

    void nextDay() override;

private:
    size_t capacity_ = 0;

    size_t maxCrew_ = 0;
    size_t crew_ = 0;
    size_t speed_ = 0;
    std::string name_;
    const size_t id_ = -1;
};
