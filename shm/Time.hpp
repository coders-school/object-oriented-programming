#pragma once

#include <chrono>
#include <functional>
#include <list>
#include <utility>
#include <memory>

class Timeable;

// Singleton with global access point
// Class responsible for managing game time flow
class Time {
public:
    // Static method which calls private constructor if instance of Time does not exist
    // otherwise returns the instance pointer
    static Time* getInstance();
    ~Time();

    // Singletons are not clonable
    Time(Time&) = delete;

    // Singletons are not assignable
    void operator=(const Time&) = delete;

    // Add subscription
    void attach(Timeable* subscriber);

    // Cancels subscription
    bool detach(Timeable* subscriber);

    void nextDay();

private:
    Time() = default;
    static std::unique_ptr<Time> instance_;
    std::list<Timeable*> list_;
};
