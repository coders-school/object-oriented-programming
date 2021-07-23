#pragma once

#include <string>//for size_t

class Perishable {
public:
    Perishable(size_t freshTime, size_t maxFreshTime = 0);
    virtual ~Perishable() = default;

    bool operator==(const Perishable& other) const;
    Perishable& operator--();

    const Perishable& getPerishable() const;
    Perishable& getPerishable();
    size_t getFreshTime() const;
    size_t getMaxFreshTime() const;

private:
    size_t freshTime_;
    size_t maxFreshTime_;
};
