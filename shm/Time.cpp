#include "Time.hpp"
#include <functional>
#include <utility>
#include <limits>
#include <algorithm>
#include <stdexcept>
#include <chrono>
#include <thread> // for sleep only
#include <iostream>

Time* Time::instance_ {nullptr};

Time* Time::getInstance() {
    if(!instance_) {
        instance_ = new Time;
    }
    return instance_;
}

Time::~Time() {
    delete instance_;
}

size_t Time::attach(std::function<void(void)> function) {
    size_t id = generateId();
    list_.push_back(std::make_pair(id, function));
    return id;
}

bool Time::detach(size_t id) {
    auto result = std::find_if(list_.cbegin(), list_.cend(), [=](std::pair<size_t, std::function<void(void)>> pair){
        return id == pair.first;
        });
    if(result != list_.cend()) {
        list_.erase(result);
        return true;
    }
    return false;
}

void Time::update() {
    // Walkaround for lack of proper game main loop
    std::chrono::steady_clock::time_point start(std::chrono::steady_clock::now());
    size_t days {10};
    while (days > 0) {
        std::chrono::milliseconds sleepFor(1000);
        std::this_thread::sleep_for(sleepFor);
        std::chrono::steady_clock::time_point timeNow(std::chrono::steady_clock::now());
        std::chrono::duration<double, std::milli> elapsedTime = timeNow - start;
        if(elapsedTime > dayDuration) {
            start = std::chrono::steady_clock::now();
            std::cout << " --- Day: " << 10 - days  << " ---" << '\n';
            nextDay();
            --days;
        }
    }
    

}

void Time::nextDay() {
    for(auto& function : list_) {
        if(function.second) {
            function.second();
        }
    }
}

size_t Time::generateId() {
    for(size_t i {0}; i < std::numeric_limits<size_t>::max(); ++i) {
        auto result = std::find_if(list_.cbegin(), list_.cend(), [=](std::pair<size_t, std::function<void(void)>> pair){
            return i == pair.first;
            });
        if(result == list_.cend()) {
            return i;
        }
    }
    // I want to intentionally crash the game here
    throw std::range_error("generateId method has failed");
}
