#include "ship.hpp"
#include "player.hpp"

Ship::Ship(int capacity, int maxCrew, int speed, const std::string& name, size_t id)
        : capacity_(capacity)
        , maxCrew_(maxCrew)
        , crew_(0)
        , speed_(speed)
        , name_(name)
        , id_(id)
    { 
        shipCargo.reserve(3);
        shipCargo.push_back(std::make_shared<Fruit>(10, "Apple", 10, 100, 0));
        shipCargo.push_back(std::make_shared<Fruit>(10, "ejple", 10, 100, 0));
        shipCargo.push_back(std::make_shared<Fruit>(10, "wejple", 10, 100, 0));
    }

Ship::~Ship(){}

Ship& Ship::operator-=(size_t num) {
    if (crew_ < num) {
        crew_ = 0;
    } else {
        crew_ -= num;
    }
    return *this;
}

Ship& Ship::operator+=(size_t num) {
    crew_ += num;
    return *this;
}

void Ship::addCargo(Cargo* item) {
    printShipCargo();
    shipCargo.emplace_back(item);
}
Cargo* Ship::findMatchCargo(Cargo* cargo) {
    for (auto& el : shipCargo) {
        if (*el == *cargo) {
            return el.get();
        }
    }
    return nullptr;
}
void Ship::load(std::shared_ptr<Cargo> cargo_ptr) { // Not working
    if (Cargo* ptr = findMatchCargo(cargo_ptr.get())) {
        *ptr += cargo_ptr->getAmount();
        return;
    }
    shipCargo.push_back(cargo_ptr);
}

void Ship::setOwner(Player* newOwner) {
    owner_ = newOwner;
}

void Ship::setCrew(size_t newCrew) {
    crew_ = newCrew;
}

void Ship::nextDay() {
    size_t moneyForCrew = crew_;
    if (owner_) {
        owner_->SpendMoney(moneyForCrew);
    }
}
void Ship::printShipCargo()
{
    for(auto & el : shipCargo)
    {
        std::cout << '\n';
        el -> printCargo();
    }
}