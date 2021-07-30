#include "Timeable.hpp"
#include "Time.hpp"

Timeable::Timeable() {
    auto time = Time::getInstance();
    time->attach(this);
}

Timeable::~Timeable() {
    auto time = Time::getInstance();
    time->detach(this);
}
