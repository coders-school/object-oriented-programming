#pragma once
#include <memory>
#include <string>
#include <vector>

class Cargo;

class Ship {
public:
    using CargoVec = std::vector<std::unique_ptr<Cargo>>;
    Ship();
    Ship(size_t capacity, size_t maxCrew, size_t speed, const std::string& name, const size_t id, CargoVec cargoVec);
    Ship(size_t maxCrew, size_t speed, size_t id);
 
    void setName(const std::string& name);
 
    Ship& operator-=(size_t num);
    Ship& operator+=(size_t num);
 
    size_t getCapacity() const;  
    size_t getMaxCrew() const;   
    size_t getSpeed() const;   
    const std::string& getName() const;  
    size_t getId() const;
    const CargoVec& getCargoVec() const;
     
private:
    size_t capacity_;
    size_t maxCrew_;
    size_t crew_;
    size_t speed_;
    std::string name_;
    const size_t id_;
    CargoVec cargoVec_;
};
