#pragma once

#include <string>

class Rottingable {
public:
    Rottingable(size_t freshTime, size_t maxFreshTime = 0)
        : freshTime_(freshTime), maxFreshTime_(maxFreshTime) {
        if (!maxFreshTime) {
            maxFreshTime_ = freshTime_;
        }
    }
    virtual ~Rottingable() = default;

    bool operator==(const Rottingable& other) const {
        return this->maxFreshTime_ == other.maxFreshTime_
            and this->freshTime_ == other.freshTime_;
    }

    virtual Cargo& operator--() = 0;

protected:
    size_t freshTime_;
    size_t maxFreshTime_;
};
