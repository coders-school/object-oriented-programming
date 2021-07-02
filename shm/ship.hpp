#pragma once
#include <memory>
#include <string>
#include <vector>
#include "cargo.hpp"

class Ship 
{
public:
    Ship()
        : id_(-1) {}
    Ship(int capacity, int maxCrew, int speed, const std::string& name, size_t id)
        :  capacity_(capacity)
        , maxCrew_(maxCrew)
        , crew_(0)
        , speed_(speed)
        , name_(name)
        , id_(id)
     {}
    Ship(int maxCrew, int speed, size_t id)
        : Ship(0, maxCrew, speed, "", id) {}

    Ship& operator-=(size_t num);
    Ship& operator+=(size_t num);

    size_t getCapacity() const;
    size_t getMaxCrew() const;
    size_t getSpeed() const;
    std::string getName() const;
    size_t getId() const;
    std::shared_ptr<Cargo> getCargo(size_t index) const;

    
    std::vector<std::shared_ptr<Cargo>> getCargos() const;
    
    
    std::shared_ptr<Cargo> theSame(std::shared_ptr<Cargo> cargo);


    void setName(const std::string& name);
   
private:
    size_t capacity_;
    size_t maxCrew_;
    size_t crew_;
    size_t speed_;
    std::string name_;
    const size_t id_;
    std::vector<std::shared_ptr<Cargo>> cargos_;
};