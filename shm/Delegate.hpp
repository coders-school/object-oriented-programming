#pragma once

#include <cstddef>

class Delegate {
public:
    virtual ~Delegate() = default;
    virtual void payCrew(size_t money) = 0;
};
