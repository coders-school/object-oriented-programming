#pragma once

#include <iostream>
#include <string>

class Ship {
    size_t id_;
    std::string name_;
    size_t speed_;
    size_t maxCrew_;
    size_t capacity_;
    size_t crew_;

public:
    Ship();
    Ship(size_t, const std::string&, size_t, size_t, size_t);
    Ship(size_t, size_t, size_t);

    void setName(const std::string&);

    Ship& operator+=(size_t);
    Ship& operator-=(size_t);

    size_t getId() const;
    std::string getName();
    size_t getSpeed() const;
    size_t getMaxCrew() const;
    size_t getCapacity() const;
};