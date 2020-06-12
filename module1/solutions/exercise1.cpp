#include <string>

class Ship {
public:
    size_t getCapacity() const { return capacity_; }
    size_t getCrew() const { return crew_; }
    size_t getSpeed() const { return speed_; }
    std::string getName() const { return name_; }
    size_t getId() const { return id_; }

private:
    size_t capacity_;
    size_t crew_;
    size_t speed_;
    std::string name_;
    size_t id_;
};
