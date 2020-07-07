#include "Ship.hpp"
#include "ShmExceptions.hpp"

Ship::Ship() : id_(-1)
{
}
Ship::Ship(int capacity, int maxCrew, int speed, const std::string& name, size_t id)
    : capacity_(capacity), maxCrew_(maxCrew), crew_(0), speed_(speed), name_(name), id_(id)
{
}

Ship::Ship(int maxCrew, int speed, size_t id) : Ship(0, maxCrew, speed, "", id)
{
}

void Ship::setName(const std::string& name)
{
    name_ = name;
}

Ship& Ship::operator-=(size_t num)
{
    if (crew_ >= num)
        crew_ -= num;
    else
        throw AmountException("Not enough Crew!");
    return *this;
}

Ship& Ship::operator+=(size_t num)
{
    if ((crew_ + num) <= maxCrew_)
        crew_ += num;
    else
        throw AmountException("Too much Crew!");
    return *this;
}
