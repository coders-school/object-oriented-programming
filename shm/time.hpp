#pragma once

#include "subjectTime.hpp"
#include "observerTime.hpp"

#include <cstdint>
#include <vector>

class Time : public SubjectTime {

private:
    uint32_t elapsedTime_;
    std::vector<ObserverTime*> observersList_;

public:
    Time () = default;

    void registerObserver(ObserverTime* o) override;
    void unregisterObserver(ObserverTime* o) override;

    uint32_t getElapsedTime() const;
    Time& operator++();


};
