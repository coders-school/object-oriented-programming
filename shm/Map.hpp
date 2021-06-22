#pragma once
#include <string>
#include <vector>
#include <memory>
#include <functional>

class Map {
public:
    Map(Island island, Island* currentPosition)
        : currentPostion_(currentPosition)
        {}
    virtual void initialize(island);
private:
    std::vector<Island&> islands_; //I dont know if this vector is going to be the only place where we are collecting islands. If its the only way to somehow "remember" islands, then pointer is pointless (hehe) 
    Island* currentPostion_;                        
};