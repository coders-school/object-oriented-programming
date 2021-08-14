#pragma once

#include <vector>
#include <string>
#include <memory>    
#include "cargo.hpp"
#include "Time.hpp"
#include "TimeEffectable.hpp"
#include "fruit.hpp"
class Player;

//Class responsible for representing ship in game
class Ship : public TimeEffectable {
public:
    Ship(Time* time);
    Ship(int capacity, int Crew, int speed, const std::string& name, size_t id, Time* time);
    Ship(int maxCrew, int speed, size_t id, Time* time);
    ~Ship();
    void setName(const std::string& name) { name_ = name; }

    Ship& operator-=(size_t);
    Ship& operator+=(size_t);
    
    void addCargo(Cargo *);
    void removeCargo(Cargo *, size_t);

    size_t getCapacity() const  { return capacity_; }
    size_t getMaxCrew() const   { return maxCrew_; }
    size_t getSpeed() const     { return speed_; }
    size_t getCrew() const     { return crew_; }
    std::string getName() const { return name_; }
    size_t getId() const        { return id_; }
    std::vector<Cargo *> getCargo() { return shipCargo;} //instead of getcargo we use load atm.
    std::vector<Cargo *> shipCargo; 

    Cargo * findMatchCargo(Cargo *);
    void load(Cargo *, size_t);
    void unload(Cargo *, size_t);
    void printShipCargo();

    void nextDay(size_t) override;
    void setOwner(Player* );
    void setCrew(size_t );

    size_t calculateAvailableSpace();

protected:
    size_t capacity_;
    size_t maxCrew_;
    size_t crew_;
    size_t speed_;
    std::string name_;
    const size_t id_;
    
    Player* owner_ = nullptr;
    Time* time_;
};
