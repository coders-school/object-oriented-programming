#pragma once

#include <memory>

class Cargo; 

class Warehouse {
public:
    using CargoVec = std::vector<std::unique_ptr<Cargo>>;

    Warehouse() = default;
    Warehouse(CargoVec cargoVec);
    virtual ~Warehouse() = default;

    const CargoVec& getCargoVec() const;

    virtual void load(std::unique_ptr<Cargo>);
    virtual void unload(const Cargo*);

protected:
    CargoVec cargoVec_ = {};
};


