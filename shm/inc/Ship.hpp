#pragma once

#include <string>
class Ship {

public:
    Ship() = default;
    Ship(size_t, std::string, size_t, size_t, size_t);
    Ship(size_t, size_t, size_t);

    Ship& operator+=(const size_t);
    Ship& operator-=(const size_t);

    size_t getId() const { return id_; };
    std::string getName() const& { return name_; };
    size_t getSpeed() const { return speed_; };
    size_t getMaxCrew() const { return maxCrew_; };
    size_t getCapacity() const { return capacity_; };

    void setName(const std::string&);
private:


    const int id_ { -1 };
    std::string name_ { };
    size_t speed_ { 50 };
    const size_t maxCrew_ { 100 };
    size_t crew_ { 0 };
    const size_t capacity_ { 80 };

};


