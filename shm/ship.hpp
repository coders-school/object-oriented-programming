#pragma once

#include <string>

class Ship {
   public:
    Ship();
    Ship(uint8_t capacity, uint8_t maxCrew, uint8_t speed, const std::string& name, uint8_t id);
    Ship(uint8_t maxCrew, uint8_t speed, uint8_t id);

    void setName(const std::string& name);

    Ship& operator-=(uint8_t crew);
    Ship& operator+=(uint8_t crew);

    uint8_t getId() const;
    std::string getName() const;
    uint8_t getSpeed() const;
    uint8_t getMaxCrew() const;
    uint8_t getCapacity() const;

   private:
    uint8_t id_;
    std::string name_;
    uint8_t speed_;
    uint8_t maxCrew_;
    uint8_t capacity_;
    uint8_t crew_;
};
