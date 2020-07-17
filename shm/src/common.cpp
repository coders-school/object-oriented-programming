#include "common.hpp"

#include <algorithm>
#include <numeric>
#include <iomanip>
#include <iostream>

/*static*/ /*public*/
//-----------------------------------------------------------------------------------
// <summary> This method prints out vector of cargo content
//-----------------------------------------------------------------------------------
bool Common::printCargo(const std::vector<std::unique_ptr<Cargo>>& vecOfCargo) {
    if (!vecOfCargo.empty()) {
        for (auto& el : vecOfCargo) {
            std::cout << "|Name| " << std::setw(15) << std::left << el->getName()
                    << "|Amount| " << std::setw(15) << std::left << el->getAmount()
                    << "|BasePrice| " << std::setw(15) << std::left
                    << el->getBasePrice() << "\n";
        }
        return true;
    }
    std::cout << "* there is no cargo *" << '\n';
    return false;
}

/*static*/ /*public*/
//--------------------------------------------------------------------------------------
// <summary> Finds particular type cargo in cargo vector using std::name for comparsion
//--------------------------------------------------------------------------------------
Cargo* Common::getCargo(const std::string& name,
                        const std::vector<std::unique_ptr<Cargo>>& vecOfCargo) {

    auto it = std::find_if(vecOfCargo.begin(), vecOfCargo.end(),
                           [&](const auto& el) { return el->getName() == name; });

    if (it != vecOfCargo.end()) {
        return (*it).get();
    }
    return nullptr;
}

/*static*/ /*public*/
//-----------------------------------------------------------------------------------
// <summary> Returns object avaiable space
//-----------------------------------------------------------------------------------
size_t Common::getAvailableSpace(size_t capacity,
                                 const std::vector<std::unique_ptr<Cargo>>& vecOfCargo) {
    size_t occupied = std::accumulate(vecOfCargo.begin(), vecOfCargo.end(), 0,
                                      [](size_t sum, const auto& cargo) {
                                          return sum += cargo->getAmount();
                                      });
    return capacity - occupied;
}
