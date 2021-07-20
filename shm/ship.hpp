#pragma once

#include <vector>
#include <string>
#include <memory>    
#include "cargo.hpp"
#include "time.hpp"
#include "TimeEffectable.hpp"


class Player;

//Class responsible for representing ship in game
class Ship : public TimeEffectable {
public:
    Ship(Time &time)
        : id_(-1)
        , time_(time)
    {
        time_.attach(this);
    }

    Ship(int capacity, int maxCrew, int speed, const std::string& name, size_t id, Time &time)
        : capacity_(capacity)
        , maxCrew_(maxCrew)
        , crew_(0)
        , speed_(speed)
        , name_(name)
        , id_(id)
        , time_(time)
    {
        time_.attach(this);
    }

    Ship(int maxCrew, int speed, size_t id, Time &time)
        : Ship(0, maxCrew, speed, "", id, time)
    {}
    
    ~Ship(){ time_.detach(this); }
    
    void setName(const std::string& name) { name_ = name; }

    Ship& operator-=(size_t num);
    Ship& operator+=(size_t num);
    
    void addCargo(Cargo* item);

    size_t getCapacity() const  { return capacity_; }
    size_t getMaxCrew() const   { return maxCrew_; }
    size_t getSpeed() const     { return speed_; }
    size_t getCrew() const     { return crew_; }
    std::string getName() const { return name_; }
    size_t getId() const        { return id_; }
    std::vector<std::shared_ptr<Cargo>> getCargo() { return shipCargo;}
    Cargo* findMatchCargo(Cargo* cargo);
    void load(std::shared_ptr<Cargo> cargo);
    void unload(Cargo* cargo_ptr);

    void nextDay() override;
    void setOwner(Player* newOwner);
    void setCrew(size_t newCrew);
    Time &time_;

private:
    size_t capacity_;
    size_t maxCrew_;
    size_t crew_;
    size_t speed_;
    std::string name_;
    const size_t id_;
    std::vector<std::shared_ptr<Cargo>> shipCargo;
    Player* owner_ = nullptr;
    
};
