#ifndef SHIP_HPP
#define SHIP_HPP
#include <string>

class Ship {
private:
    const size_t id_;
    std::string name_;
    size_t speed_;
    size_t maxCrew_;
    size_t capacity_;
    size_t crew_;

public:
    Ship();
    Ship(int capacity, int maxCrew, int speed, const std::string& name, size_t id);
    Ship(int maxCrew, int speed, size_t id);

    size_t getCapacity() const { return capacity_; }
    size_t getMaxCrew() const { return maxCrew_; }
    size_t getSpeed() const { return speed_; }
    std::string getName() const { return name_; }
    size_t getId() const { return id_; }

    void setName(const std::string& name);

    Ship& operator-=(size_t num);
    Ship& operator+=(size_t num);
};

#endif