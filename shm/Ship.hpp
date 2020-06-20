#pragma once

#include <string>

class Ship {
public:
    Ship();
    Ship(int id,
         const std::string & name,
         size_t speed,
         size_t maxCrew,
         size_t capacity);
    Ship(int id,
         size_t speed,
         size_t maxCrew);

    int getId() const { return _id; }
    std::string getName() const { return _name; }
    size_t getSpeed() const { return _speed; }
    size_t getMaxCrew() const { return _maxCrew; }
    size_t getCapacity() const { return _capacity; }
    size_t getCrew() const { return _crew; }

    void setName(const std::string& name) { _name = name; }

    Ship& operator+=(const size_t crew);
    Ship& operator-=(const size_t crew);

private:
    const int _id;
    std::string _name;
    size_t _speed;
    size_t _maxCrew;
    size_t _capacity;
    size_t _crew;
};
