#include "Timeable.hpp"
#include "Time.hpp"

Timeable::Timeable() {
    Time* time = Time::getInstance();
    time->attach(this);
}

Timeable::~Timeable() {
    Time* time = Time::getInstance();
    time->detach(this);
}