#pragma once

class Delegate {
public: 
    virtual void payCrew(int payCrew) = 0;
    virtual ~Delegate() {} ; 
};