#pragma once

#include <iostream>

class Delegate {
public:
    virtual void payCrew(size_t money) = 0;
    virtual ~Delegate() {}
};
