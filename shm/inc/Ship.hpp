#pragma once

#include <string>
class Ship {

public:
    Ship() = default;
    Ship(int8_t, std::string, uint8_t, uint8_t, uint8_t);
    Ship(int8_t, uint8_t, uint8_t);

    Ship& operator+=(const uint16_t);
    Ship& operator-=(const uint16_t);

    int8_t getId() const { return id_; };
    std::string getName() const& { return name_; };
    uint8_t getSpeed() const { return speed_; };
    uint8_t getMaxCrew() const { return maxCrew_; };
    uint8_t getCapacity() const { return capacity_; };

    void setName(const std::string&);
private:


    const int8_t id_ { -1 };
    std::string name_ { };
    uint8_t speed_ { 50 };
    const uint8_t maxCrew_ { 100 };
    uint8_t crew_ { 0 };
    const uint8_t capacity_ { 80 };

};


