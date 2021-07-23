
#include "DefaultCargo.hpp"

#include <cassert>

size_t CargoDefault::getPrice() const {
    return basePrice_;
}

bool CargoDefault::operator==(const Cargo& other) const {
    return name_ == other.getName();
}

std::unique_ptr<Cargo> CargoDefault::createAmountOfEqual(size_t amount) {
    auto result = std::make_unique<CargoDefault>(name_, amount, basePrice_);
    assert(*result == *this);
    return result;
}
