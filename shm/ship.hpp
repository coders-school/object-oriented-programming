#pragma once

#include <memory>
#include <string>
#include <vector>

#include "cargo.hpp"

class Ship {
public: 
    Ship();
    Ship(size_t capacity, size_t maxCrew, size_t speed, const std::string& name, int id);
    Ship(size_t maxCrew, size_t speed, int id);

    void setName(const std::string& name); 
   // void load(std::unique_ptr<Cargo> cargo);
   // void unload(Cargo* cargo);
    
    Ship& operator-=(size_t crewman);
    Ship& operator+=(size_t crewman);

    size_t getCapacity() const;  
    size_t getMaxCrew() const; 
    size_t getSpeed() const;
    std::string getName() const;
    int getId() const;
    Cargo* getCargo(size_t index) const;
    size_t countAvailableSpace() const;
    
private:
    //Cargo* findCargo(Cargo* cargo);
    void removeCargo (Cargo* cargo);

    size_t capacity_;
    size_t maxCrew_;
    size_t crew_;
    size_t speed_;
    std::string name_;
    int id_;
    std::vector<std::unique_ptr<Cargo>> cargo_;
};
