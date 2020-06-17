#pragma once

#include <string>

class Ship {
public:
    Ship();
    Ship(int, const std::string &, size_t, size_t, size_t);
    Ship(int, size_t, size_t);

    int getId() const { return _id; }
    std::string getName() const { return _name; }
    size_t getSpeed() const { return _speed; }
    size_t getMaxCrew() const { return _maxCrew; }
    size_t getCapacity() const { return _capacity; }
    size_t getCrew() const { return _crew; }

    void setName(const std::string& name) { _name = name; }

    Ship& operator+=(const size_t);
    Ship& operator-=(const size_t);

private:
    const int _id;
    std::string _name;
    size_t _speed;
    size_t _maxCrew;
    size_t _capacity;
    size_t _crew;
};
