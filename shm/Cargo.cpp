#include "Cargo.h"

Cargo::Cargo(std::string name, size_t amount, size_t basePrice, Time* time)
    : name_(name),
      amount_(amount),
      basePrice_(basePrice),
      time_(time) {
    time_->subscribe(this);
}

Cargo::~Cargo() {
    time_->unsubscribe(this);
}

void Cargo::update() {
    this->nextDay();
}
