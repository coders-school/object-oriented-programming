#pragma once
#include <string>


class Ship {
public: 
    Ship();
    Ship(int capacity, int maxCrew, int speed, const std::string& name, int id);
Ship::Ship(int maxCrew, int speed, size_t id);
    void setName(const std::string& name); 
    Ship& operator-=(size_t num);
    Ship& operator+=(size_t num);
    size_t getCapacity();  
    size_t getMaxCrew(); 
    size_t getSpeed();
    std::string getName();
    int getId();
private:
    size_t capacity_;
    size_t maxCrew_;
    size_t crew_;
    size_t speed_;
    std::string name_;
    const int id_;
};

