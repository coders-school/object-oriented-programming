#pragma once

#include <vector>
#include <memory>
#include <string>

#include "cargo.hpp"

class Common {
public:
    static bool printCargo(const std::vector<std::unique_ptr<Cargo>>& vecOfCargo);
    static Cargo* getCargo(const std::string& name,
                           const std::vector<std::unique_ptr<Cargo>>& vecOfCargo);
    static size_t getAvailableSpace(size_t capacity,
                                    const std::vector<std::unique_ptr<Cargo>>& vecOfCargo);
};
