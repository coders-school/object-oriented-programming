#pragma once 

#include <string>

class Ship {
public:
    Ship();
    Ship(size_t capacity, size_t maxCrew, size_t speed, const std::string& name, size_t id);
    Ship(int maxCrew, int speed, size_t id);
    
    void setName(const std::string& name);

    Ship& operator-=(size_t num);
    Ship& operator+=(size_t num);

    size_t getCapacity() const;
    size_t getId() const;
    size_t getMaxCrew() const;
    std::string getName() const;
    size_t getSpeed() const;

private:
    size_t capacity_;
    size_t crew_;
    const size_t id_;
    size_t maxCrew_;
    std::string name_;
    size_t speed_;
};
