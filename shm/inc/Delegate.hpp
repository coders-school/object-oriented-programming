#pragma once

class Delegate {
public: 
    virtual void payCrew(const size_t payCrew) = 0;
    virtual ~Delegate() = 0; 
};
