#include "Alcohol.hpp"

Alcohol::Alcohol(const std::string &name, size_t amount, size_t basePrice, size_t alcoholContent)
    : Cargo(name, amount, basePrice), alcoholContent_(alcoholContent) {

}
