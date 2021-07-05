#include "Ship.hpp"
#include "Time.hpp"
#include <iostream>
#include <functional>
    
Ship::Ship() 
    : id_(-1)
{}

Ship::Ship(int capacity, int maxCrew, int speed, const std::string& name, size_t id, std::vector<std::unique_ptr<Cargo>> cargoVec)
    : capacity_(capacity)
    , maxCrew_(maxCrew)
    , crew_(0)
    , speed_(speed)
    , name_(name)
    , id_(id)
    , cargoVec_(std::move(cargoVec))
    {
        Time* time = Time::getInstance();
        std::function<void(void)> function = std::bind(&Ship::nextDay, this);
        timeId_ = time->attach(function);
    }

Ship::Ship(int maxCrew, int speed, size_t id)
    : Ship(0, maxCrew, speed, "", id, {})
{}

Ship::~Ship() {
    Time* time = Time::getInstance();
    time->detach(timeId_);
}


void Ship::setName(const std::string& name) { 
    name_ = name; 
}

Ship& Ship::operator-=(size_t num) {
    crew_ -= num;
    return *this;
}

Ship& Ship::operator+=(size_t num) {
    crew_ += num;
    return *this;
}

size_t Ship::getCapacity() const { 
    return capacity_; 
}

size_t Ship::getMaxCrew() const { 
    return maxCrew_; 
}

size_t Ship::getSpeed() const { 
    return speed_; 
}

std::string Ship::getName() const { 
    return name_; 
}

size_t Ship::getId() const { 
    return id_; 
}

const std::vector<std::unique_ptr<Cargo>>& Ship::getCargoVec() const { 
    return cargoVec_; 
}

void Ship::load(std::unique_ptr<Cargo> cargo) {
    if (!cargo) {
        return;
    }

    Cargo* storedCargo = nullptr;
    for(const auto& el : cargoVec_){
        if(*cargo == *el){
            storedCargo = el.get();
            break;
        }
    }

    if (!storedCargo) {
        for (auto& el : cargoVec_) {
            if (!el) {
                el = std::move(cargo);  //move cargo into empty cargo space
                return;
            }
        }
        cargoVec_.push_back(std::move(cargo));  //move cargo into vector
        return;
    }
    *storedCargo += cargo->getAmount();  //transfer amount into comperable cargo
    //here cargo will be destroyed
}

void Ship::unload(const Cargo* const cargo) {  //ver A
    if (!cargo) {
        return;
    }
    for (auto& el : cargoVec_) {
        if (el.get() == cargo) {  //equal pointers -> equal amount
            el.reset();
            //we leave empty cargo space in store here
            cargoVec_.erase(std::remove(begin(cargoVec_), end(cargoVec_), nullptr), end(cargoVec_));
            return;
        }
    }
    throw std::logic_error("Store: Not my Cargo!");
}

void Ship::nextDay() {
    std::cout << "Next Day in Ship " << name_ << '\n';
}