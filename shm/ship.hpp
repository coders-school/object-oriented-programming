#pragma once

#include <string>

class Ship {
   public:
    Ship() : id_(-1) {}
    Ship(int capacity, int maxCrew, int speed, const std::string& name, size_t id)
        : capacity_(capacity),
          maxCrew_(maxCrew),
          crew_(0),
          speed_(speed),
          name_(name),
          id_(id) {}
    Ship(int maxCrew, int speed, size_t id) : Ship(0, maxCrew, speed, "", id) {}

    void setName(const std::string& name);

    Ship& operator-=(size_t crew);
    Ship& operator+=(size_t crew);

    size_t getId() const;
    std::string getName() const;
    size_t getSpeed() const;
    size_t getMaxCrew() const;
    size_t getCapacity() const;

   private:
    size_t id_;
    std::string name_;
    size_t speed_;
    size_t maxCrew_;
    size_t capacity_;
    size_t crew_;
};
