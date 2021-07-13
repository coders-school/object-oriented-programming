#include "Time.hpp"
#include "Timeable.hpp"
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

void Time::attach(Timeable* subscriber) {
    list_.push_back(subscriber);
}

bool Time::detach(Timeable* subscriber) {
    auto result = std::find(list_.cbegin(), list_.cend(), subscriber);
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
    for(auto& timableObj : list_) {
        if(timableObj) {
            timableObj->nextDay();
        }
    }
}
