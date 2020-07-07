#include "cargo.hpp"

Cargo::Cargo(const std::string& name, size_t amount, size_t basePrice, Time* time)
    : name_(name)
    , amount_(amount)
    , basePrice_(basePrice)
    , time_(time)
{
    time_->addObserver(this);    
}
Cargo::~Cargo() {
    time_->removeObserver(this);
}
