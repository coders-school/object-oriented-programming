#pragma once
#include <memory>
#include <string>
#include <vector>

class Cargo;

class Ship {
public:
    using CargoVec = std::vector<std::unique_ptr<Cargo>>;
    Ship() = default;
    Ship(size_t capacity, size_t maxCrew, size_t speed, const std::string& name, size_t id, CargoVec cargoVec);
    Ship(size_t maxCrew, size_t speed, size_t id);
 
    void setName(const std::string& name);

    //both operators throw std::invalid_argument. if you will use operators remember about try-catch.  
    Ship& operator-=(size_t numCrew);
    Ship& operator+=(size_t numCrew);
 
    size_t getCapacity() const;  
    size_t getMaxCrew() const;   
    size_t getSpeed() const;   
    const std::string& getName() const;  
    size_t getId() const;

    void load(std::unique_ptr<Cargo> cargo);
    void unload(const Cargo* const cargo);

    const CargoVec& getCargoVec() const;
     
private:
    size_t capacity_ = 0;
    size_t maxCrew_ = 0;
    size_t crew_ = 0;
    size_t speed_ = 0;
    std::string name_;
    size_t id_ = -1;
    CargoVec cargoVec_ = {};
};
