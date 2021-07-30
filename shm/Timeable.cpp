#include "Timeable.hpp"
#include "Time.hpp"

Timeable::Timeable() {
    std::shared_ptr<Time> time = Time::getInstance();
    time->attach(this);
}

Timeable::~Timeable() {
    std::shared_ptr<Time> time = Time::getInstance();
    time->detach(this);
}