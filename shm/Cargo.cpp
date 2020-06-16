#include <Cargo.hpp>

Cargo& Cargo::operator+=(const size_t amount) {
    m_amount += amount;
    return *this;
}

Cargo& Cargo::operator-=(const size_t amount) {
    m_amount -= amount;
    return *this;
}
