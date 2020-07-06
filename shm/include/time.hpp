#pragma once

#include <list>

class Observer {
public:
    virtual void nextDay() = 0;
    virtual ~Observer() {}
};

class Time {
public:
    Time();
    Time(int game_days);
    void addObserver(Observer* obs);
    void removeObserver(Observer* obs);
    size_t getElapsedTime() const;
    // Prefix increment operator (decrement elapsed time)
    Time& operator++();
    // Postfix increment operator (decrement elapsed time)
    Time operator++(int);

private:
    std::list<Observer*> observers_;
    size_t time_elapsed_;
};
