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

void Ship::addCargo(std::shared_ptr<Cargo> item)
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

void Ship::removeCargo(std::shared_ptr<Cargo> item, size_t amount)
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

std::shared_ptr<Cargo> Ship::findMatchCargo(std::shared_ptr<Cargo> cargo)
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
void Ship::load(std::shared_ptr<Cargo> loadCargo, size_t amount)
{
    if (amount <= calculateAvailableSpace())
    {
        loadCargo->reduceAmount(amount);
        std::cout << "Line 0 - Value of is :" << loadCargo.get()->getPrice() << " " << loadCargo.get()->getName() << std::endl ;
      /*  if(Fruit* f = dynamic_cast<Fruit*>(loadCargo.get())){
            std::shared_ptr<Cargo> toAdd = std::shared_ptr<Fruit>(f);
            std::cout << "Line 1 - Value of (Fruit)toAdd is :" << toAdd.get()->getPrice() << std::endl ;
            toAdd->setAmount(amount);
            addCargo(toAdd);
        }
       if(Item* i = dynamic_cast<Item*>(loadCargo.get())){
            std::shared_ptr<Cargo> toAdd = std::shared_ptr<Item>(i);
            std::cout << "Line 1 - Value of (Item)toAdd is :" << toAdd.get()->getPrice() << std::endl ;
            toAdd->setAmount(amount);
            addCargo(toAdd);
        }
        if(Alcohol* a = dynamic_cast<Alcohol*>(loadCargo.get())){
            std::shared_ptr<Cargo> toAdd = std::shared_ptr<Alcohol>(a);
            std::cout << "Line 1 - Value of (Alcohol)toAdd is :" << toAdd.get()->getPrice() << std::endl ;
            toAdd->setAmount(amount);
            addCargo(toAdd);
        }*/
            auto toAdd = loadCargo;
            toAdd->setAmount(amount);
            addCargo(toAdd);
    }
}

void Ship::unload(std::shared_ptr<Cargo> unloadCargo, size_t amount)
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
    cargoAmount = std::accumulate(shipCargo.begin(), shipCargo.end(), 0, [](int i, std::shared_ptr<Cargo> c) { return i += c->getAmount(); });

    if (capacity_ - cargoAmount < 0)
    {
        return 0;
    }
    return capacity_ - cargoAmount;
}