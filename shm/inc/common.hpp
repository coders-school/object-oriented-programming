#pragma once

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

#include "cargo.hpp"

class Common {
public:
    static void printCargo(const std::vector<Cargo*>& vecOfCargo);
    static Cargo* getCargo(const std::string& name,
                           const std::vector<Cargo*>& vecOfCargo);
    static size_t getAvailableSpace(size_t capacity,
                                    const std::vector<Cargo*>& vecOfCargo);
};