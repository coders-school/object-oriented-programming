#include "Island.hpp"


Island::Island(Coordinates coordinates)
    : position_(coordinates) {
         std::unique_ptr<Store> store(new Store());
    store_ = std::move(store);
    }