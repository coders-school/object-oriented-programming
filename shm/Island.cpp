#include "Island.hpp"

Island::Island(size_t positionX, size_t positionY, std::shared_ptr<Time>& time)
    : position_(positionX, positionY) {  
        store_ = std::make_shared<Store>(time);
};
