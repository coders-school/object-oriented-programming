#include "Time.hpp"
#include <algorithm>
#include <iostream>
#include <memory>
#include "Timeable.hpp"

std::shared_ptr<Time> Time::instance_{nullptr};

std::shared_ptr<Time> Time::getInstance() {
    if (!instance_) {
        instance_ = std::shared_ptr<Time>(new Time);
    }
    return instance_;
}

Time::~Time() {
    // dupaprint to prove that this solution is working
    // std::cout << "Time destructor called\n";
}

void Time::attach(Timeable* subscriber) {
    list_.push_back(subscriber);
}

bool Time::detach(Timeable* subscriber) {
    auto result = std::find(list_.cbegin(), list_.cend(), subscriber);
    if (result != list_.cend()) {
        list_.erase(result);
        return true;
    }
    return false;
}

void Time::nextDay() {
    for (auto& timableObj : list_) {
        if (timableObj) {
            timableObj->nextDay();
        }
    }
}
