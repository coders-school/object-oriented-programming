#pragma once
#include <memory>
#include <string>
#include <vector>
#include "cargo.hpp"


// Class responsible for managing Ship in the game.
class Ship 
{
public:
    Ship()
        : id_(-1) {}
    Ship(size_t capacity, size_t maxCrew, size_t crew, size_t speed, const std::string& name, size_t id, std::vector<std::shared_ptr<Cargo>> cargos)
        :  capacity_(capacity)
        , maxCrew_(maxCrew)
        , crew_(crew)
        , speed_(speed)
        , name_(name)
        , id_(id)
        , cargos_(cargos)
     {}
    Ship(size_t maxCrew, size_t speed, size_t id)
        : Ship(0, maxCrew, 0, speed, "", id, {}) {}

    Ship& operator-=(size_t num);
    Ship& operator+=(size_t num);

    size_t getCapacity() const;
    size_t getMaxCrew() const;
    size_t getSpeed() const;
    size_t getCrew() const;
    std::string getName() const;
    size_t getId() const;
    std::shared_ptr<Cargo> getCargo(size_t index) const;    
    std::vector<std::shared_ptr<Cargo>> getCargosVector() const;
    
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