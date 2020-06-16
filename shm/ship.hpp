#pragma once

#include <string>

class Ship {
public:
    Ship();
    Ship(size_t, std::string, size_t, size_t, size_t);
    Ship(size_t, std::string, size_t);

    int getId() const { return id_; };
    std::string getName() const { return name_; };
    size_t getSpeed() const { return speed_; };
    size_t getMaxCrew() const { return maxCrew_; };
    size_t getCapacity() const { return capacity_; };
    void setName(const std::string& name);

    Ship& operator+=(const size_t& crew) {
        if (crew_ + crew <= maxCrew_) {
            crew_ += crew;
        }
        return *this;
    }

    Ship& operator-=(const size_t& crew) {
        if (crew_ - crew >= 0) {
            crew_ -= crew;
        }
        return *this;
    }

private:
    size_t id_;
    std::string name_;
    size_t speed_;
    size_t maxCrew_;
    size_t capacity_;
    size_t crew_;
};