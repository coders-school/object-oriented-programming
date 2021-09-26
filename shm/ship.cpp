#include "ship.hpp"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <memory>

#include "alcohol.hpp"
#include "cargo.hpp"
#include "fruit.hpp"
#include "item.hpp"

// Class responsible for managing Ships in the game.

Ship::Ship() : id_(-1){};

Ship::Ship(size_t capacity, size_t maxCrew, size_t crew, size_t speed, const std::string& name, size_t id, std::shared_ptr<Time> time)
        : capacity_(capacity)
        , maxCrew_(maxCrew)
        , crew_(crew)
        , speed_(speed)
        , name_(name)
        , id_(id)
        , time_(time)
     {
         time_->attachObserver(this);
     }

Ship::~Ship() { time_->detachObserver(this); }

Ship &Ship::operator-=(size_t num)
{
    if (crew_ - num <= crew_)
    {
        crew_ -= num;
    }
    else
    {
        std::cerr << "You need at least one member of the crew !!!\n";
    }
    return *this;
}

Ship &Ship::operator+=(size_t num)
{
    if (crew_ + num <= maxCrew_)
    {
        crew_ += num;
    }
    else
    {
        std::cerr << " The maximum amount of members of the crew is " << maxCrew_ << " !!!! \n";
    }
    return *this;
}

size_t Ship::getCapacity() const
{
    return capacity_;
}
size_t Ship::getMaxCrew() const
{
    return maxCrew_;
}
size_t Ship::getCrew() const
{
    return crew_;
}
size_t Ship::getSpeed() const
{
    return speed_;
}
std::string Ship::getName() const
{
    return name_;
}
size_t Ship::getId() const
{
    return id_;
}
// Function returns specific cargo
std::shared_ptr<Cargo> Ship::getCargo(size_t index) const
{
    if (cargos_.size() <= index)
    {
        return nullptr;
    }
    return cargos_[index];
}

std::vector<std::shared_ptr<Cargo>> Ship::getCargosVector() const
{
    return cargos_;
}

void Ship::setName(const std::string &name)
{
    name_ = name;
}

std::vector<std::shared_ptr<Cargo>>::iterator Ship::findMatchCargo(std::shared_ptr<Cargo> cargo)
{
    return std::find_if(cargos_.begin(),
                        cargos_.end(),
                        [&cargo](const auto &searchCargo)
                        { return searchCargo->getName() == cargo->getName(); });
}

void Ship::unload(std::shared_ptr<Cargo> &cargo, size_t amount)
{
    auto findCargo = findMatchCargo(cargo);
    if (findCargo == cargos_.end())
    {
        return;
    }

    if (findCargo != cargos_.end())
    {
        (**findCargo) -= amount;
        if (!(*findCargo)->getAmount())
        {
            (*findCargo)->detachingObserver();
            cargos_.erase(findCargo);
        }
    }
}

void Ship::load(std::shared_ptr<Cargo> &cargo, size_t amount)
{
    auto findCargo = findMatchCargo(cargo);

    if (findCargo != cargos_.end()) {
        if (capacity_ > cargo->getAmount()) {
            (**findCargo) += amount;
        } else {
            std::cerr << "Not enuogh space on ship!!!!\n";
        }
    } else {
        addCargo(cargo, amount);
    }
}

void Ship::addCargo(std::shared_ptr<Cargo> &cargo, size_t amount)
{
    cargo->setTime(time_);
    cargos_.push_back(cargo->clone(amount));
}
void Ship::nextDay()
{
    owner_->setMoney(owner_->getMoney() - crew_);
}

void Ship::setOwner(std::shared_ptr<Player> owner)
{
    owner_ = owner;
}

std::shared_ptr<Time> Ship::getTime() const
{
    return time_;
}
