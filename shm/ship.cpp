#include <iostream>
#include <string>
#include "ship.hpp"

    Ship::Ship()
        : id_(-1)
    {}

    Ship::Ship(int capacity, int maxCrew, int speed, const std::string& name, int id)
        : capacity_(capacity)
        , maxCrew_(maxCrew)
        , crew_(0)
        , speed_(speed)
        , name_(name)
        , id_(id)
    {}
    
    Ship::Ship(int maxCrew, int speed, size_t id)
        : Ship(0, maxCrew, speed, "", id)
    {}

    void Ship::setName(const std::string& name) { name_ = name; }

    Ship& Ship::operator-=(size_t num) {
        if (crew_ < num) {
            std::cerr << "Number of papays is lower than 0 \n";
            return *this;
        }
        crew_ -= num;
        return *this;
    }
    Ship& Ship::operator+=(size_t num) {
        if(num + crew_ > maxCrew_) {
            std::cerr << "To many papays!\n";
            return *this;
        }
        crew_ += num;
        return *this;
    }

    size_t Ship::getCapacity() const  { return capacity_; }
    size_t Ship::getMaxCrew() const   { return maxCrew_; }
    size_t Ship::getSpeed() const     { return speed_; }
    std::string Ship::getName() const { return name_; }
    int Ship::getId() const        { return id_; }

