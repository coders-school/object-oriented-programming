#pragma once
#include <string>

#include "Cargo.hpp"

class Ship {
public:
    Ship()
        : capacity_()
        , maxCrew_()
        , crew_()
        , speed_()
        , name_()
        , cargo_()
        , id_(-1)
    {}

    Ship(int capacity, int maxCrew, int speed, const std::string& name, size_t id)
        : capacity_(capacity)
        , maxCrew_(maxCrew)
        , crew_(0)
        , speed_(speed)
        , name_(name)
        , cargo_()
        , id_(id)
    {}
    
    Ship(int maxCrew, int speed, size_t id)
        : Ship(0, maxCrew, speed, "", id)
    {}

    void setName(const std::string& name) { name_ = name; }

    Ship& operator-=(size_t num) {
        crew_ -= num;
        return *this;
    }
    Ship& operator+=(size_t num) {
        crew_ += num;
        return *this;
    }

    size_t getCapacity() const  { return capacity_; }
    size_t getMaxCrew() const   { return maxCrew_; }
    size_t getSpeed() const     { return speed_; }
    std::string getName() const { return name_; }
    Cargo& getCargo(const size_t index) { return cargo_.at(index); }
    size_t getId() const        { return id_; }

private:
    size_t capacity_;
    size_t maxCrew_;
    size_t crew_;
    size_t speed_;
    std::string name_;
    std::vector<Cargo> cargo_;
    const size_t id_;
};
