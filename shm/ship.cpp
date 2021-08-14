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

Ship::Ship(int capacity, int Crew, int speed, const std::string &name, size_t id, Time *time)
    : capacity_(capacity), crew_(Crew), speed_(speed), name_(name), id_(id), time_(time)
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
    auto cargoPtr = findMatchCargo(item);
    if(findMatchCargo(item))
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
        auto it = std::find_if(begin(shipCargo), end(shipCargo), [item](const auto* el){ return *el == *item; });
        if(it != end(shipCargo)) {
            shipCargo.erase(it);
        }
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
    // Checking if we have enough cargo to unload
    if(auto* shipCargo = findMatchCargo(unloadCargo)) {
        if(shipCargo->getAmount() >= amount) {
            removeCargo(unloadCargo, amount);
        }
        else {
            std::cout << "Ship: " << this->getName() << " doesn't have enough cargo: " << unloadCargo->getName() << '\n';
        }
        
    }
    else {
        std::cout << "Ship: " << this->getName() << "doesn't have cargo: " << unloadCargo->getName() << '\n';
    }
    // TO jest bez sensu 
    // if (calculateAvailableSpace() - amount >= 0)
    // {
    //     removeCargo(unloadCargo, amount);
    // }
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

void Ship::nextDay(size_t elapsedTime) //Not working
{
    size_t moneyForCrew = crew_;
    if (owner_)
    {
        owner_->SpendMoney(moneyForCrew);
    }
}
void Ship::printShipCargo()
{
    auto i = 0;
    std::cout << "Ship Cargo:" << '\n';
    for (auto &el : shipCargo)
    {
        std::cout << '\n';
        el->printCargo(i);
        i++;
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
