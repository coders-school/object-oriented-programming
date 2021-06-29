#pragma once 
  
#include "Cargo.hpp"

enum class ItemStatus {
    common,
    rare,
    epic,
    legendary
};

class Item : public Cargo {
public:
    size_t getPrice() const override;
    std::string getName() const override;
    size_t getAmount() const override;
    size_t getBasePrice() const override;
  
private:
    ItemStatus itemStatus_;
  
};
