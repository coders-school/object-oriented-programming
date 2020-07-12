#include "island.hpp"

Island::Island(int positionX, int positionY) : position_(positionX, positionY) {
    store_ = std::make_shared<Store>();
}
