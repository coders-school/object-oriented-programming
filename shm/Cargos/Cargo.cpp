#include <stdexcept>

#include "Cargo.hpp"

#include <cassert>
#include <iostream>

Cargo::Cargo(const std::string& name, size_t amount, size_t basePrice)
    : name_{name}, amount_{amount}, basePrice_{basePrice} {}

Cargo& Cargo::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Cargo::operator-=(size_t amount) {
    if (amount_ < amount) {
        throw std::invalid_argument("Not allowed! You will be below zero!");
    }
    amount_ -= amount;
    return *this;
}

const std::string_view Cargo::getName() const {
    return name_;
}

size_t Cargo::getAmount() const {
    return amount_;
}

size_t Cargo::getBasePrice() const {
    return basePrice_;
}

//Return position where suffix begin in name_ if exist.
std::optional<size_t> Cargo::haveSuffix(const std::string_view suffix) const {
    if (name_.empty() and name_.size() < suffix.size()) {
        return {};
    }
    std::string_view sv(name_);
    auto trim_pos = sv.find(suffix, sv.size() - suffix.size());
    if (trim_pos != sv.npos) {
        return trim_pos;
    }
    return {};
}
//Remove suffix from name_
void Cargo::removeSuffix(const std::string_view suffix) {
    if (auto trim_pos = haveSuffix(suffix)) {
        auto trim_suffix = trim_pos.value();
        name_.shrink_to_fit();
        auto size = name_.size();
        size_t suffix_lenght = suffix.size();
        auto restOfSuffixLenght = size - trim_suffix - suffix_lenght;
        name_ = name_.substr(0, trim_pos.value()) + name_.substr(trim_suffix + suffix_lenght, restOfSuffixLenght);  //save rest of suffixes
    }
}
//Add suffix to the name_
void Cargo::addSuffix(const std::string_view suffix) {
    if (haveSuffix(suffix)) {
        return;
    }
    name_ += suffix;
}

std::unique_ptr<Cargo> Cargo::split(size_t amountPart) {
    if (!amountPart or amountPart > amount_) {
        return {};
    }
    *this -= amountPart;
    return createAmountOfEqual(amountPart);
}

void Cargo::nextDay() {}
