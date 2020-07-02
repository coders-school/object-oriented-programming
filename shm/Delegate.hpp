#pragma once

#include <cstddef>
#include <iostream>

class Delegate {
public:
    virtual ~Delegate() = default;
    virtual void payCrew(size_t money) = 0;
};
