#pragma once

#include <string>
#include <vector>
#include "Cargo.hpp"

class Ship {
public:
    Ship()
        : id_(0)
    {}
    Ship(int capacity, int maxCrew, int speed, const std::string& name, size_t id)
        : capacity_(capacity)
        , maxCrew_(maxCrew)
        , crew_(0)
        , speed_(speed)
        , name_(name)
        , id_(id)
    {}
    Ship(int maxCrew, int speed, size_t id)
        : Ship(0, maxCrew, speed, "", id)
    {}

    void setName(const std::string& name) { name_ = name; }

    size_t getCapacity() const  { return capacity_; }
    size_t getMaxCrew() const   { return maxCrew_; }
    size_t getSpeed() const     { return speed_; }
    std::string getName() const { return name_; }
    size_t getId() const        { return id_; }
    void load(const std::shared_ptr<Cargo>& cargo) { allCargos_.push_back(cargo); }
    //void unload(Cargo* cargo) {  }

    Ship& operator-=(size_t num);
    Ship& operator+=(size_t num);

private:
    size_t capacity_;
    size_t maxCrew_;
    size_t crew_;
    size_t speed_;
    std::string name_;
    const size_t id_;
    std::vector<std::shared_ptr<Cargo>> allCargos_;
};
