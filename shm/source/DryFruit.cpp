#include "DryFruit.hpp"

DryFruit::DryFruit(const std::string& name, const size_t amount, const size_t basePrice):
    Fruit(name, amount, basePrice),
    freshnessModifier_(10)
{}

DryFruit& DryFruit::operator--() {
    if (--freshnessModifier_ <= 0) {
        freshnessModifier_ = 10;
        Fruit::operator--();
    }
    return *this;
}

size_t DryFruit::getPrice() const {
    return Fruit::getPrice() * 3;
}

std::string DryFruit::getName() const { 
    return "DryFruit: " + name_; 
}
