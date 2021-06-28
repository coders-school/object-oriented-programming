#include <memory>
#include <algorithm>

class Cargo;

class Ship {
public:
    void load(std::unique_ptr<Cargo> cargo) {
        if (auto match_cargo = findMatchCargo(cargo.get())) {
            *match_cargo += cargo->getAmount();
            return;
        }
        cargo_.push_back(std::move(cargo));
    }

    void unload(Cargo* cargo) {
        removeFromStorage(cargo);
    }

    Cargo* findMatchCargo(Cargo* cargo) {
        for (auto el : cargo_) {
            if (el->getName() == "Fruit") {
                if (el->getName() == cargo->getName() &&
                    el->getBasePrice() == cargo->getBasePrice() &&
                    el->getExpiryDate() == cargo->getExpiryDate())
                    return el.get();
            } else if (el->getName() == "Alcohol") {
                if (el->getName() == cargo->getName() &&
                    el->getBasePrice() == cargo->getBasePrice() &&
                    el->getPercentage() == cargo->getPercentage())
                    return el.get();
            } else {
                if (el->getName() == cargo->getName() &&
                    el->getBasePrice() == cargo->getBasePrice() &&
                    el->getRarity() == cargo->getRarity())
                    return el.get();
            }
        }
    }

    void removeFromStorage(Cargo* cargo) {
        cargo_.erase(std::find_if(std::begin(cargo_), std::end(cargo_),
                                  [cargo](const auto& el) {
                                      return *el == *cargo;
                                  }));
    }
};
