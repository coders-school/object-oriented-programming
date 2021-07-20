#include "ship.hpp"
#include "player.hpp"

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
void Ship::load(std::shared_ptr<Cargo> cargo_ptr) {
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
    std::cout << "PAYDAY" << '\n';
    size_t moneyForCrew = crew_;
    if (owner_) {
        owner_->SpendMoney(moneyForCrew);
    }
}