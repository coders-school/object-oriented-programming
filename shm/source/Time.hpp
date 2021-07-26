#pragma once

#include <vector>

class Observer;

class Time {
	size_t timeElapsed_;
	std::vector<Observer*> observers_;

public:
	Time();

	void AddObserver(Observer* obs);

	void RemoveObserver(Observer* obs);

	size_t GetElpasedTime() const;

	Time& operator++();

	// ObserverIT GetObserverIt(Observer* obs);
};
