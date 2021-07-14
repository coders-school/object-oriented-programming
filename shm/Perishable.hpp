#pragma once

#include <string>

class Perishable {
public:
    Perishable(size_t freshTime, size_t maxFreshTime = 0)
        : freshTime_(freshTime), maxFreshTime_(maxFreshTime) {
        if (!maxFreshTime) {
            maxFreshTime_ = freshTime_;
        }
    }
    virtual ~Perishable() = default;

    bool operator==(const Perishable& other) const {
        return this->maxFreshTime_ == other.maxFreshTime_
            and this->freshTime_ == other.freshTime_;
    }

    virtual Cargo& operator--() = 0;

protected:
    size_t maxFreshTime_;
    size_t freshTime_;
};
