#include "common.hpp"

/*static*/ /*public*/
//-----------------------------------------------------------------------------------
// <summary> This method prints out vector of cargo content
//-----------------------------------------------------------------------------------
void Common::printCargo(const std::vector<Cargo*>& vecOfCargo) {
    for (auto* el : vecOfCargo) {
        std::cout << "|Name| " << std::setw(15) << std::left << el->getName()
                  << "|Amount| " << std::setw(15) << std::left << el->getAmount()
                  << "|BbasePrice| " << std::setw(15) << std::left
                  << el->getBasePrice() << "\n";
    }
}

/*static*/ /*public*/
//-----------------------------------------------------------------------------------
// <summary> Finds particular cargo in cargo vec using std::name for comparsion
//-----------------------------------------------------------------------------------
Cargo* Common::getCargo(const std::string& name,
                        const std::vector<Cargo*>& vecOfCargo) {
    auto it = std::find_if(vecOfCargo.begin(), vecOfCargo.end(),
                           [&](Cargo* el) { return el->getName() == name; });

    if (it != vecOfCargo.end()) {
        return (*it);
    }
    return nullptr;
}

/*static*/ /*public*/
//-----------------------------------------------------------------------------------
// <summary> Returns object avaiable space
//-----------------------------------------------------------------------------------
size_t Common::getAvailableSpace(size_t capacity,
                                 const std::vector<Cargo*>& vecOfCargo) {
    size_t occupied = std::accumulate(vecOfCargo.begin(), vecOfCargo.end(), 0,
                                      [](size_t sum, const auto& cargo) {
                                          return sum += cargo->getAmount();
                                      });
    return capacity - occupied;
}
