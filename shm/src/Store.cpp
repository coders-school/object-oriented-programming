#include "shm/inc/Store.hpp"

std::ostream& operator<<(std::ostream& oper, const Store& store){
    for (size_t i = 0; i < cargo_.size(); i++) {
        oper << "|" << std::setfill('-') << std::setw (100) << "|\n";
        oper << std::setw (10) << "| ID: " << i + 1;
        oper << std::setw (30) << " | CARGO NAME: " << cargo_[i]->getName();
        oper << std::setw (10) << " | AMOUNT: " << cargo_->getAmount();
        oper << std::setw (10) << " | PRICE: " << cargo_->getPrice() << " |\n";
    }
    oper << "|" << std::setfill('-') << std::setw (100) << "|\n";
    return oper;
}
