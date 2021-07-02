#include <memory>
#include <iostream>
#include "cargo.hpp"
#include "ship.hpp"
#include "alcohol.hpp"
#include "fruit.hpp"
#include "item.hpp"
#include <algorithm>
#include <numeric>

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
std::shared_ptr<Cargo>Ship::getCargo(size_t index) const {
    if(index < 0) {
        std::cerr << "\nInvalid Cargo\n";
    }
    return cargos_[index];
}

std::vector<std::shared_ptr<Cargo>> Ship::getCargos() const {
    return cargos_;
}

void Ship::setName(const std::string& name) {
    name_ = name;
}

std::shared_ptr<Cargo> Ship::theSame(std::shared_ptr<Cargo> cargo)
{
    /// how the fuck to do that;

    for(auto el : cargos_){
        if(el->getName() == "Fruit"){
            if(el->getName() == cargo->getName() && el->getBasePrice() == cargo->getBasePrice() &&  el->

        } else if(el->getName() == "Alcohol"){

        }else {

        }

    }
}


void Ship::load(std::shared_ptr<Cargo> cargo)
{
    
}

void Ship::unload(std::shared_ptr<Cargo> cargo) 
{
    cargos_.erase(find_if(begin(cargos_), end(cargos_),[cargo](const auto& el) {return el == cargo;}));
}