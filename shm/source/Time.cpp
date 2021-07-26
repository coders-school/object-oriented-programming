#include "Time.hpp"
#include "Observer.hpp"

#include <algorithm>

Time::Time():
	timeElapsed_(0),
	observers_()
{}

void Time::AddObserver(Observer* obs) {
	observers_.push_back(obs);
}

void Time::RemoveObserver(Observer* obs) {
	auto it = std::find_if(observers_.begin(), observers_.end(), [obs](const auto* lhs) { return lhs == obs; } );

	if (it != observers_.end()) {
		std::iter_swap(it, (observers_.end() - 1));
		observers_.pop_back();
	}
}

size_t Time::GetElpasedTime() const {
	return timeElapsed_;
}

Time& Time::operator++() {
	++timeElapsed_;
	for (auto* observer : observers_) {
		observer->nextDay();
	}
	return *this;
}

// ObserverIT GetObserverIt(Observer* obs);

