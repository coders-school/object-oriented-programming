#include "cargo.hpp"

Cargo::Cargo(const std::string& name, size_t amount, size_t basePrice)
    : name_(name)
    , amount_(amount)
    , basePrice_(basePrice)
{}

Cargo::Cargo(const Cargo& cargo){
    name_ = cargo.name_;
    amount_ = cargo.amount_;
    basePrice_ = cargo.basePrice_;
}
