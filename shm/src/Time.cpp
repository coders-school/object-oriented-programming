#include "shm/inc/Time.hpp"

#include <algorithm>

#include "shm/inc/Subscriber.hpp"

void Time::addSubscriber(Subscriber* subscriber) {
    subscribers_.push_back(subscriber);
}

void Time::removeSubscriber(Subscriber* subscriber) {
    subscribers_.erase(std::remove(subscribers_.begin(), subscribers_.end(), subscriber),
                       subscribers_.end());
}
