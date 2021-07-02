#include <iostream>
#include <numeric>
#include <algorithm>

#include "store.hpp"
#include "fruit.hpp"
#include "item.hpp"

std::shared_ptr<Cargo> Store::getStoreCargo(const size_t index) const {
    if(index > storeCargos_.size()) {
        return nullptr;
    }
    return  storeCargos_[index].get();
}

Response buy(std::shared_ptr<Cargo> cargo, size_t amount, Player* player) 
{
    if(cargo) {
        
    }
}

