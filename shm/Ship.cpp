#include "Ship.hpp"

    Ship::Ship() 
        : id_(-1)
    {}
    Ship::Ship(size_t capacity, size_t maxCrew, size_t speed, const std::string& name, size_t id)
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
        crew_ -= num;
        return *this;
    }
    Ship& Ship::operator+=(size_t num) {
        crew_ += num;
        return *this;
    }

    size_t Ship::getCapacity() const  { return capacity_; }
    size_t Ship::getId() const        { return id_; }
    size_t Ship::getMaxCrew() const   { return maxCrew_; }
    std::string Ship::getName() const { return name_; }
    int Ship::getSpeed() const        { return speed_; }
    