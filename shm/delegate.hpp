#pragma once

#include <cstdint>

class Delegate {
public:
    virtual ~Delegate() = default;
    virtual void payCrew(uint32_t salary) = 0;
};
