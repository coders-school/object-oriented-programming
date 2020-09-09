#include <algorithm>
#include "Ship.hpp"
#include "ShmExceptions.hpp"


Ship::~Ship()
{
    time_.removeObserver(this);
}

Ship::Ship(int capacity, int maxCrew, int speed, const std::string& name, size_t id, Time& time)
    : capacity_(capacity), maxCrew_(maxCrew), crew_(maxCrew), speed_(speed), name_(name), id_(id), time_(time)
{
    time_.addObserver(this);
}

Ship::Ship(int maxCrew, int speed, size_t id, Time& time) : Ship(0, maxCrew, speed, "", id, time)
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

[[nodiscard]] std::shared_ptr<Cargo> Ship::getCargo(size_t index) const
{
    try
    {
        return storage_.at(index);
    }
    catch (const std::out_of_range& ex)
    {
        return nullptr;
    }
}
void Ship::NextDay()
{
    if (delegate_)
    {
        delegate_->PayCrew(crew_ * wage);
    }
}

void Ship::addDelegate(IDelegate* delegate)
{
    delegate_ = delegate;
}

void Ship::load(const std::shared_ptr<Cargo>& cargo)
{
    storage_.push_back(cargo);

    //    TODO support case, when product is already loaded previously
}

void Ship::unload(Cargo* cargo)
{
    storage_.erase(
        std::remove_if(storage_.begin(), storage_.end(), [cargo](auto listedCargo) { return *cargo == *listedCargo; }));

    // TODO support situation when only part od product is sold
}
