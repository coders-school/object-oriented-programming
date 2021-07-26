#include "Store.hpp"

// Store(Time* time);

// ~Store() override;

void Store::nextDay() {
	for (auto& good : cargo_) {
		good->nextDay();
	}
}

// Cargo* GetCargo(const size_t pos);

// Response Buy(Cargo* cargo, size_t amount, Player* player);

// Response Sell(Cargo* caergo, size_t amount, Player* player);

// friend std::ostream& operator<<(std::ostream& out, const Store& store);

// void GenerateCargo();

// Cargo* FindMatchCargo(Cargo* cargo);

// void RemoveFromStore(Cargo* cargo);