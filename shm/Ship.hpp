#pragma once
#include <memory>
#include <string>
#include <vector>
#include <functional>

#include "Time.hpp"
#include "Timeable.hpp"
#include "Warehouse.hpp"

class Cargo;

struct Crew{
    size_t value;
    operator size_t(){
        return value;
    }
};

struct Capacity{
    size_t value;
    operator size_t(){
        return value;
    }
};

struct Speed{
    size_t value;
    operator size_t(){
        return value;
    }
};

class Ship : public Warehouse,
             public Timeable {
public:
    static constexpr size_t defaultCapacity = 15;
    static constexpr size_t defaultMaxCrew_ = 10;
    static constexpr size_t defaultCrew = 10;
    static constexpr size_t defaultSpeed = 3;
    using Warehouse::CargoVec;

    Ship();
    Ship(Crew maxCrew, Speed speed);
    Ship(Capacity capacity, Crew maxCrew, Speed speed, const std::string& name);
    Ship(CargoVec cargoVec, Capacity capacity, Crew maxCrew, Speed speed, const std::string& name);

    ~Ship() override = default;

    //both operators throw std::invalid_argument. if you will use operators remember about try-catch.
    Ship& operator-=(Crew numCrew);
    Ship& operator+=(Crew numCrew);

    Capacity getCapacity() const;
    Crew getMaxCrew() const;
    Speed getSpeed() const;
    const std::string& getName() const;
    size_t getId() const;
    const CargoVec& getCargoVec() const;

    void setName(const std::string& name);
    void setDebt(std::function<bool(size_t)> payFunction);
    
    void nextDay() override;
  
private:
    static size_t nextId;
    Capacity capacity_ = {defaultCapacity};
    Crew maxCrew_ = {defaultMaxCrew_};
    Crew crew_ = {defaultCrew};
    Speed speed_ = {defaultSpeed};
    std::string name_;
    const size_t id_;

    std::function<bool(size_t)> debt{};
};
