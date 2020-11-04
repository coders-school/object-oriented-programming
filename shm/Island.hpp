#pragma once

#include <memory>

#include "Coordinates.hpp"
#include "Store.hpp"

class Island {
    Coordinates position_;
    std::shared_ptr<Store> store_;

public:
    Island() = default;
    Island(uint16_t, uint16_t);
    Coordinates getPosition() const;
    std::shared_ptr<Store> getStore() const;
};