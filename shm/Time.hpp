#pragma once

#include <functional>
#include <utility>
#include <list>
#include <chrono>

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

    void update();
    void nextDay();

private:
    Time() = default;
    static Time* instance_;
    std::list<Timeable*> list_;

    static constexpr std::chrono::milliseconds dayDuration {5000};
};
