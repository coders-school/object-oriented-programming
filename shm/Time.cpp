#include "Time.h";

#include <algorithm>

//override from Subject
void Time::subscribe(Observer* observer) {
    observers_.push_back(observer);
}
//override from Subject
void Time::unsubscribe(Observer* observer) {
    observers_.erase(std::remove_if(observers_.begin(), observers_.end(), [observer](auto registerdObserver) {
        return observer == registerdObserver;
    }));
}
//override from Subject
void Time::notify() {
    for (auto it : observers_) {
        it->update();
    }
}
