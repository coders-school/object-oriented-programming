#pragma once

#include <memory>

template <class T>
class Cloneable {
public:
    std::shared_ptr<T> cloneToShared() {
        return static_cast<std::shared_ptr<T>>(cloneToRawPointer());
    }
    std::unique_ptr<T> cloneToUnique() {
        return static_cast<std::unique_ptr<T>>(cloneToRawPointer());
    }

protected:
    virtual T*
    cloneToRawPointer() = 0;
};
