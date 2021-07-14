#pragma once

#include <cstddef> 
#include <memory>

#include "shm/inc/Store.hpp"

// class responsible for manage landmass in game
class Island {
public:
    // class responsible for manage coordinates of islands in game
    class Coordinates {
    public:
        Coordinates(size_t positionX, size_t positionY);
        bool operator==(const Coordinates& position) const;
        static size_t distance(const Coordinates& lhs, const Coordinates& rhs);
        size_t getPositionX() { return positionX_; }
        size_t getPositionY() { return positionY_; }

    private:
        const size_t positionX_ = 0;
        const size_t positionY_ = 0;
    };

    Island(const Island::Coordinates& position, const size_t &storeSize);
    
    Coordinates getCoordinates() const { return position_; }
    Store* getStore() { return store_.get(); }

private:
    const Coordinates position_;
    std::shared_ptr<Store> store_;
};
