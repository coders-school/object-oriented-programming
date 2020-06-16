#pragma once

#include<string>

class Ship {
public:
    Ship();
    Ship(int, std::string, size_t, size_t, size_t);
    Ship(int, std::string, size_t);

    int getId();
    std::string getName();
    size_t getSpeed();
    size_t getMaxCrew();
    size_t getCapacity();
    void setName(const std::string& name);
    Ship& operator +=(const size_t crew) {
        if (crew_ + crew <= maxCrew_) {
            crew_ += crew;
        }
        return *this;
    }
    Ship& operator -=(const size_t crew) {
        if (crew_ - crew >= 0) {
            crew_ -= crew;
        }
        return *this;
    }
private:
    const int id_;
    std::string name_;
    size_t speed_;
    size_t maxCrew_;
    size_t capacity_;
    size_t crew_;
};