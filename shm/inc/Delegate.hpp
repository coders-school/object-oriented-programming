#pragma once

#include <cstddef>

class Delegate {
public: 
    virtual void payCrew(const size_t payCrew) = 0;
    virtual ~Delegate() {}; 
};
