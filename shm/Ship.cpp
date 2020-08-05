#include "Ship.hpp"

#include <algorithm>
#include <iomanip>
#include <iostream>

Ship::Ship()
    : id_(0) {
}

Ship::Ship(int capacity, int maxCrew, int speed, const std::string& name, size_t id, std::shared_ptr<Time>& time)
    : capacity_(capacity), maxCrew_(maxCrew), crew_(0), speed_(speed), name_(name), id_(id), time_(time) {
    time_->addObserver(this);
}

Ship::Ship(int maxCrew, int speed, size_t id, std::shared_ptr<Time>& time)
    : Ship(0, maxCrew, speed, "", id, time) {
}

Ship& Ship::operator-=(const size_t crew) {
    if (crew > crew_) {
        crew_ = 0;
        return *this;
    }
    crew_ -= crew;
    return *this;
}

Ship& Ship::operator+=(const size_t crew) {
    if (crew_ + crew > maxCrew_) {
        crew_ = maxCrew_;
        return *this;
    }
    crew_ += crew;
    return *this;
}

void Ship::load(const CargoPtr& cargo) {
    StockManagement::addCargoToStock(stock_, cargo, cargo->getAmount());
}

void Ship::unload(const CargoPtr& cargo, size_t amount) {
    StockManagement::removeCargoFromStock(stock_, cargo, amount);
}

std::ostream& operator<<(std::ostream& out, const Ship& ship) {
    std::string horizontalSeparator(41, '=');
    int i = 0;
    out << horizontalSeparator
        << "\n"
        << "|| SHIP'S  STOCK" << std::setw(15)
        << "| QTY " << std::setw(5)
        << "| PRICE " << std::setw(3)
        << "||\n"
        << horizontalSeparator << "\n";

    for (const auto& el : ship.stock_) {
        out << "||"
            << std::setw(2) << ++i << ". "
            << std::setw(18) << std::left << el->getName() << " | "
            << std::setw(3) << std::right << el->getAmount() << " | "
            << std::setw(5) << std::right << el->getPrice() << " ||\n";
    }
    out << horizontalSeparator << "\n";

    return out;
}

void Ship::nextDay() {
    if (delegate_) {
        delegate_->payCrew(crew_ * salaryPerWorker);
    }
    std::for_each(stock_.begin(), stock_.end(), [](const auto& el) { el->nextDay(); });
}
