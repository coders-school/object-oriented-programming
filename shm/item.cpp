#include "item.hpp"

//size_t Item::getPrice() const;
std::string Item::getName() const { return name_; }
size_t Item::getAmount() const  { return amount_; }
size_t Item::getBasePrice() const  { return base_price_; }
Cargo& operator+=(size_t amount);
Cargo& operator-=(size_t amount);
bool operator==(Cargo& cargo) const;