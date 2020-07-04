#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "cargo.hpp"
#include "timeSHM.hpp"

class Ship : public Observer {

public: 
    Ship();
    Ship(size_t capacity, size_t maxCrew, size_t speed, const std::string& name, int id, Time* Publisher);
    //Ship(size_t maxCrew, size_t speed, int id);
    ~Ship(){
        this->Publisher_->removeObserver(this);
        std::cout << "Goodbye! I was your Ship\n";
    };
    void setName(const std::string& name); 
    void load(Cargo* cargo);
   // void unload(Cargo* cargo);
   void nextDay() override; 
    Ship& operator-=(size_t crewman);
    Ship& operator+=(size_t crewman);

    size_t getCapacity() const;  
    size_t getCrew() const;
    size_t getMaxCrew() const; 
    size_t getSpeed() const;
    std::string getName() const;
    int getId() const;
    Cargo* getCargo(size_t index) const;
    size_t countAvailableSpace() const;
    size_t fillInCrew();
private:
    Cargo* findCargo(Cargo* cargo);
    void removeCargo (Cargo* cargo);
    size_t capacity_;
    size_t maxCrew_;
    size_t crew_;
    size_t speed_;
    std::string name_;
    int id_;
    std::vector<Cargo*> cargo_;
    Time* Publisher_;
    bool ownerExistenceFlag_;
};
