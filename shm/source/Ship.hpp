#pragma once

#include "Observer.hpp"
#include "Time.hpp"
//#include "Delegate.hpp"

#include <memory>
#include <string>
#include <vector>

class Cargo;

class Ship : Observer {
    std::string name_;
    const size_t capacity_;
    const size_t maxCrew_;
    const size_t id_;
    size_t crew_;
    size_t speed_;
    Time* time_;
    //Delegate* delegate_;
    std::vector<std::unique_ptr<Cargo>> cargo_;

public:
    Ship();

    Ship(int maxCrew, int speed, size_t id);

    Ship(int capacity, int maxCrew, int speed, const std::string& name, size_t id, Time* time);

    // ~Ship() override;
    
    void setName(const std::string& name);

    Ship& operator-=(size_t num);

    Ship& operator+=(size_t num);

    size_t getCapacity() const;

    size_t getMaxCrew() const;

    size_t getSpeed() const;

    std::string getName() const;

    size_t getId() const;
    
    std::vector<std::unique_ptr<Cargo>>& getCargo();

    // void printCargo() const;

    void load(std::unique_ptr<Cargo> cargo);

    void unload(Cargo* cargo);

    Cargo* getCargo(const size_t index) const;

    // Cargo* findMatchCargo(Cargo* cargo);
    
    // void removeFromStorage(Cargo* cargo);
    
    void nextDay() override;
};
