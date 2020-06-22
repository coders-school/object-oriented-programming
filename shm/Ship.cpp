#include "Ship.hpp"

#include <algorithm>

Ship& Ship::operator-=(const size_t crew) {
    if (crew > crew_) {
        crew_ = 0;
        return *this;
    }
    crew_ -= crew;
    return *this;
}

Ship& Ship::operator+=(const size_t crew) {
    if (crew_ + crew > maxCrew_) {
        crew_ = maxCrew_;
        return *this;
    }
    crew_ += crew;
    return *this;
}

void Ship::load(const std::shared_ptr<Cargo>& cargo) {
    cargo_.push_back(cargo); 
}

void Ship::unload(Cargo* cargo) {
    if (!cargo->getAmount()) {
        std::remove_if(cargo_.begin(), cargo_.end(), [cargo](const auto& ptr) {
            return ptr.get() == cargo;
        });
    }
}
