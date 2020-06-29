#include <string>

class Ship {
public:
    Ship() {}
    Ship(int capacity, int maxCrew, int speed, const std::string& name, size_t id);
    Ship(int maxCrew, int speed, size_t id);

    void setName(const std::string& name);

    size_t getCapacity() const;
    size_t getMaxCrew() const;
    size_t getSpeed() const;
    std::string getName() const;
    size_t getId() const;

private:
    size_t capacity_;
    size_t maxCrew_;
    size_t speed_;
    std::string name_;
    const size_t id_;
};
