#pragma once

#include "observerTime.hpp"
#include "subjectTime.hpp"

#include <cstdint>
#include <vector>

class Time : public SubjectTime {
public:
    Time() = default;

    void registerObserver(ObserverTime* o) override;
    void unregisterObserver(ObserverTime* o) override;

    uint32_t getElapsedTime() const;
    Time& operator++();

private:
    uint32_t elapsedTime_;
    std::vector<ObserverTime*> observersList_;
};
