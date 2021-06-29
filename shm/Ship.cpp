#include "Ship.hpp"
    
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
{}

Ship::Ship(int maxCrew, int speed, size_t id)
    : Ship(0, maxCrew, speed, "", id, {})
{}


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

void Ship::load(std::unique_ptr<Cargo> cargo){
    bool check = true;
    for (auto el : cargoVec_) {
        if ((*cargo) == (*el)) {
            (*el) += cargo->getAmount();
            check = false;
            break;
        }
    }
    if(!check){
        cargoVec_.push_back(move(cargo));
    }
}

void Ship::unload(Cargo* cargo){
    cargoVec_.erase(std::remove_if(cargoVec_.begin(), cargoVec_.end(), 
                [ &cargo ]( unique_ptr<Cargo> cargoOnBoard ) {
                    return cargo == cargoOnBoard.get();
                }), cargoVec_.end());
}

