// #include "item.hpp"

// Cargo& Cargo::operator+=(size_t amount) {
//     amount_ += amount;
//     return *this;
// }

// Cargo& Cargo::operator-=(size_t amount) {
//     if (amount <= amount_) {
//         amount_ -= amount;
//         return *this;
//     }
// }

// Item& Item::operator--() {
//     if (amount_ > 0) {
//         --amount_;
//     }
//     return *this;
// }

// Item& Item::operator--(int) {
//     Item temp(*this);
//     if (amount_ > 0) {
//         operator--();
//     }
//     return temp;
// }

// // bool item::operator == (const Cargo& cargo) const
// // {

// // }

// size_t Item::getPrice() const {
//     return basePrice_ * static_cast<size_t>(rarity_);
// }
