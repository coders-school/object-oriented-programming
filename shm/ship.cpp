#include "ship.hpp"

Ship::Ship()
    : id_(-1) {}

Ship::Ship(size_t capacity, size_t maxCrew, size_t speed, const std::string& name, int id)
    : capacity_(capacity), maxCrew_(maxCrew), crew_(0), speed_(speed), name_(name), id_(id) {}

Ship::Ship(size_t maxCrew, size_t speed, int id)
    : Ship(0, maxCrew, speed, "", id) {}

void Ship::setName(const std::string& name) {
    name_ = name;
}
 // ​void Ship::load(std::unique_ptr<Cargo> cargo) { 
    //     cargo_.push_back(std::move(cargo));
    // }
    //wziąć pod uwagę available space - countFreeSpace w klasie player!
    //porównanie dwóch towarów - akumulacja tych samych typów towarów
    //czy zmiesci sie caly towar (maxcapacity?)

    // void Ship::unload(Cargo* cargo) {
    //     auto it = find_if(cargo_.begin(), cargo_.end(), [cargo](const auto& ptr) {
    //         return ptr.get() == cargo;
    //     });

    //     if (it != cargo_.end())
    //         cargo_.erase(it);
    // }
  //sprawdzić ilość czy jest 0 - usuwamy
  //ile zostanie towaru

Ship& Ship::operator-=(size_t crewman) {
    if (crew_ > crewman) {
        crew_ -= crewman;
    }
    return *this;
}
Ship& Ship::operator+=(size_t crewman) {
    if (crew_ + crewman < maxCrew_) {
        crew_ += crewman;
    }
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
int Ship::getId() const {
    return id_;
}
Cargo* Ship::getCargo(size_t cargo) {
    if (cargo) {
        return &cargo_[cargo];
    }
}
std::vector<Cargo> Ship::getAllCargo() const {
    return cargo_;
}