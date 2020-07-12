#include <memory>

#include "locators.hpp"

const std::unique_ptr<Time> defaultTime = std::make_unique<Time>();

Time* TimeServiceLocator::time_ = defaultTime.get();

void TimeServiceLocator::provide(Time* time) {
    time_ = time;
}

Time* TimeServiceLocator::getTime() {
    return time_;
};
