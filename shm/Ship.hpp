#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Cargo.hpp"
#include "Delegate.hpp"

constexpr size_t salaryPerWorker = 1;

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
    void setDelegate(Delegate* const delegate) { delegate_ = delegate; }    //it might be good to integrate it with Ship constructor
                                                                            //but it then requires Player class to construct Ship for itself
    size_t getCapacity() const  { return capacity_; }
    size_t getMaxCrew() const   { return maxCrew_; }
    size_t getSpeed() const     { return speed_; }
    std::string getName() const { return name_; }
    size_t getId() const        { return id_; }
    Cargo* getCargo(size_t index) const;
    const std::vector<std::shared_ptr<Cargo>>& getAllCargos() const {return cargo_;}

    Ship& operator-=(const size_t crew);
    Ship& operator+=(const size_t crew);

    void load(const std::shared_ptr<Cargo>& cargo);
    void unload(Cargo* cargo);

    void nextDay();

private:
    size_t capacity_;
    size_t maxCrew_;
    size_t crew_;
    size_t speed_;
    std::string name_;
    const size_t id_;
    std::vector<std::shared_ptr<Cargo>> cargo_;
    Delegate* delegate_ = nullptr;
};
