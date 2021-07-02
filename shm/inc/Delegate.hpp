#pragma once

class Delegate {
public: 
    virtual void payCrew(size_t payCrew) = 0;
    virtual ~Delegate() = 0; 
};