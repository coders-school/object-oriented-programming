#pragma once

#include <stdint.h>

class Delegate {
public:
    virtual void payCrew(uint16_t);
    virtual ~Delegate();
};