#include "Perishable.hpp"

Perishable::Perishable(size_t freshTime, size_t maxFreshTime)
    : freshTime_(freshTime), maxFreshTime_((maxFreshTime) ? maxFreshTime : freshTime) {
}

bool Perishable::operator==(const Perishable& other) const {
    return this->maxFreshTime_ == other.maxFreshTime_ and this->freshTime_ == other.freshTime_;
}

Perishable& Perishable::operator--(){
    --freshTime_;
    return *this;
}

const Perishable& Perishable::getPerishable() const {
    return *this;
}

Perishable& Perishable::getPerishable() {
    return *this;
}

size_t Perishable::getFreshTime() const {
    return freshTime_;
}

size_t Perishable::getMaxFreshTime() const {
    return maxFreshTime_;
}
