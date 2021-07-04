#pragma once
#include <memory>
#include <string>
#include <vector>
#include "Cargo.hpp"

class Ship {
    size_t capacity_;
    size_t maxCrew_;
    size_t crew_;
    size_t speed_;
    std::string name_;
    const size_t id_;
    std::vector<std::unique_ptr<Cargo>> cargoVec_;

public:
    Ship();
    Ship(int capacity, int maxCrew, int speed, const std::string& name, size_t id, std::vector<std::unique_ptr<Cargo>> cargoVec);
    Ship(int maxCrew, int speed, size_t id);

    void setName(const std::string& name);

    Ship& operator-=(size_t num);
    Ship& operator+=(size_t num);

    size_t getCapacity() const;
    size_t getMaxCrew() const;
    size_t getSpeed() const;
    std::string getName() const;
    size_t getId() const;
    const std::vector<std::unique_ptr<Cargo>>& getCargoVec() const;

    void load(std::unique_ptr<Cargo> cargo) {
        if (!cargo) {
            return;
        }

        Cargo* storedCargo = nullptr;
        for(const auto& el : cargoVec_){
            if(*cargo == *el){
                storedCargo = el.get();
                break;
            }
        }

        if (!storedCargo) {
            for (auto& el : cargoVec_) {
                if (!el) {
                    el = std::move(cargo);  //move cargo into empty cargo space
                    return;
                }
            }
            cargoVec_.push_back(std::move(cargo));  //move cargo into vector
            return;
        }
        *storedCargo += cargo->getAmount();  //transfer amount into comperable cargo
        //here cargo will be destroyed
    }

    void unload(const Cargo* const cargo) {  //ver A
        if (!cargo) {
            return;
        }
        for (auto& el : cargoVec_) {
            if (el.get() == cargo) {  //equal pointers -> equal amount
                el.reset();
                //we leave empty cargo space in store here
                cargoVec_.erase(std::remove(begin(cargoVec_), end(cargoVec_), nullptr), end(cargoVec_));
                return;
            }
        }
        throw std::logic_error("Store: Not my Cargo!");
    }
};
