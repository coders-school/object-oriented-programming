#include <memory>
#include <string>
#include <vector>

#include "Cargo.h";

class Ship {
public:
    Ship();
    Ship(size_t capacity, size_t maxCrew, size_t speed, const std::string& name, size_t id);
    Ship(size_t maxCrew, size_t speed, size_t id);

    void setName(const std::string& name);

    Ship& Ship::operator-=(size_t num);
    Ship& Ship::operator+=(size_t num);

    size_t getCapacity() const;
    size_t getMaxCrew() const;
    size_t getSpeed() const;
    std::string getName() const;
    size_t getId() const;
    std::shared_ptr<Cargo> getCargo(size_t index);
    std::vector<std::shared_ptr<Cargo>> getCargos() const;
    void load(std::shared_ptr<Cargo> cargo);
    void unload(Cargo* cargo);

private:
    size_t capacity_;
    size_t crew_;
    size_t max_crew_;
    size_t speed_;
    std::string name_;
    const size_t id_;
    std::vector<std::shared_ptr<Cargo>> cargos_;
};
