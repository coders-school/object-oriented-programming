#pragma once
#include <memory>
#include <string>
#include <vector>
#include "cargo.hpp"
#include "iObserver.hpp"
#include "time.hpp"

// Class responsible for managing Ship in the game.
class Ship : public IObserver
{
public:
    Ship(Time * time)
        : id_(-1) {
            time ->attachObeserver(this);
        }
    Ship(size_t capacity, size_t maxCrew, size_t crew, size_t speed, const std::string& name, size_t id, std::vector<std::shared_ptr<Cargo>> cargos, Time * time)
        :  capacity_(capacity)
        , maxCrew_(maxCrew)
        , crew_(crew)
        , speed_(speed)
        , name_(name)
        , id_(id)
        , cargos_(cargos)
        , time_(time)
     {
         time->attachObeserver(this);
     }
    Ship(size_t maxCrew, size_t speed, size_t id, Time * time)
        : Ship(0, maxCrew, 0, speed, "", id, {}, time) {
            time->attachObeserver(this);
        }

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

     std::vector<std::shared_ptr<Cargo>>::iterator findMatchCargo(std::shared_ptr<Cargo> cargo);
    
    void setName(const std::string& name);

    void addCargo(std::shared_ptr<Cargo>& cargo, size_t amount);
    
    void unload(std::shared_ptr<Cargo>& cargo, size_t amount);
    void load(std::shared_ptr<Cargo>& cargo, size_t amount);

    friend std::ostream& operator<<(std::ostream& os, const Ship& ship);
   
private:
    size_t capacity_;
    size_t maxCrew_;
    size_t crew_;
    size_t speed_;
    Time * time_;
    std::string name_;
    const size_t id_;
    std::vector<std::shared_ptr<Cargo>> cargos_;
};