#include <algorithm>
#include <iostream>
#include <numeric>
#include "ship.hpp"
#include "player.hpp"
#include "fruit.hpp"
#include "alcohol.hpp"
#include "item.hpp"

Ship::Ship(Time *time)
    : id_(-1), time_(time)
{
    time_->attach(this);
}

Ship::Ship(int capacity, int maxCrew, int speed, const std::string &name, size_t id, Time *time)
    : capacity_(capacity), maxCrew_(maxCrew), crew_(0), speed_(speed), name_(name), id_(id), time_(time)
{
    time_->attach(this);
    shipCargo.reserve(10);
}

Ship::Ship(int maxCrew, int speed, size_t id, Time *time)
    : Ship(0, maxCrew, speed, "", id, time)
{
    time_->attach(this);
}

Ship::~Ship()
{
    time_->detach(this);
}

Ship &Ship::operator-=(size_t num)
{
    if (crew_ < num)
    {
        crew_ = 0;
    }
    else
    {
        crew_ -= num;
    }
    return *this;
}

Ship &Ship::operator+=(size_t num)
{
    crew_ += num;
    return *this;
}

void Ship::addCargo(Cargo * item)
{
    if(findMatchCargo(item) == item)
    {
        findMatchCargo(item)->increaseAmount(item->getAmount());
    }
    else
    {
        shipCargo.emplace_back(item);
    }
}

void Ship::removeCargo(Cargo * item, size_t amount)
{
    auto shipCargoAmount = findMatchCargo(item)->getAmount();
    if(shipCargoAmount == amount)
    {
        auto i = std::find(begin(shipCargo), end(shipCargo), item);
        shipCargo.erase(i);
    }
    else
    {
        findMatchCargo(item)->reduceAmount(amount);
    }
}

Cargo * Ship::findMatchCargo(Cargo * cargo)
{
    for (auto &el : shipCargo)
    {
        if (*el == *cargo)
        {
            return el;
        }
    }
    return nullptr;
}
void Ship::load(Cargo * loadCargo, size_t amount)
{
    if (amount <= calculateAvailableSpace())
    {        
        loadCargo->reduceAmount(amount);
        Cargo* toAdd;
        //lol no
        //dont look, bleh
        //Something is not yes
        if(Fruit* f = dynamic_cast<Fruit*>(loadCargo)){
            toAdd = new Fruit(*f);
        }
        if(Item* i = dynamic_cast<Item*>(loadCargo)){
          toAdd = new Item(*i);
        }
        if(Alcohol* a = dynamic_cast<Alcohol*>(loadCargo)){
            toAdd = new Alcohol(*a);
        }        

        toAdd->setAmount(amount);
        addCargo(toAdd);
    }
}

void Ship::unload(Cargo * unloadCargo, size_t amount)
{
    if (calculateAvailableSpace() - amount >= 0)
    {
        removeCargo(unloadCargo, amount);
    }
}

void Ship::setOwner(Player *newOwner)
{
    owner_ = newOwner;
}

void Ship::setCrew(size_t newCrew)
{
    if (newCrew <= maxCrew_)
    {
        crew_ = newCrew;
    }
}

void Ship::nextDay()
{
    size_t moneyForCrew = crew_;
    if (owner_)
    {
        owner_->SpendMoney(moneyForCrew);
    }
}
void Ship::printShipCargo()
{
    std::cout << "Ship Cargo:" << '\n';
    for (auto &el : shipCargo)
    {
        std::cout << '\n';
        el->printCargo();
    }
}

size_t Ship::calculateAvailableSpace()
{
    int cargoAmount = 0;
    cargoAmount = std::accumulate(shipCargo.begin(), shipCargo.end(), 0, [](int i, Cargo * c) { return i += c->getAmount(); });

    if (capacity_ - cargoAmount < 0)
    {
        return 0;
    }
    return capacity_ - cargoAmount;
}