#include "Island.hpp"


Island::Island(Coordinates coordinates, Time* time)
    : position_(coordinates) {
         std::unique_ptr<Store> store(new Store(time));
         store_ = std::move(store);
         time-> AddObserver(store_.get());
    }