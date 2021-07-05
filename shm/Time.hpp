#pragma once

#include <functional>
#include <utility>
#include <list>
#include <chrono>

// Singleton with global access point
// Class responsible for managing game time flow
class Time {
public:
    // Static method which calls private constructor if instance of Time does not exist
    // otherwise returns reference to the instance pointer
    static Time* getInstance();
    ~Time();

    // Singletons are not clonable
    Time(Time&) = delete;

    // Singletons are not assignable
    void operator=(const Time&) = delete;

    // Returns unique id of subscriber function
    size_t attach(std::function<void(void)> function);

    // Cancels subscription based on provided id
    bool detach(size_t id);

    void update();
    void nextDay();

private:
    Time() = default;
    static Time* instance_;
    size_t generateId();
    std::list<std::pair<size_t, std::function<void(void)>>> list_;

    static constexpr std::chrono::milliseconds dayDuration {5000};
};
