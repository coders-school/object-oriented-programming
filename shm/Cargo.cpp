#include "Cargo.h"

	Cargo::Cargo (std::string name, size_t amount, size_t basePrice) :
				name_(name), 
				amount_(amount),
				basePrice_(basePrice)
				{}

	Cargo::Cargo& operator+=(size_t amount) {
		amount_ += amount;
		return *this;
	}

	Cargo::Cargo& operator-=(size_t amount) {
		amount_ -= amount;
		return *this;
	}

	bool Cargo::operator==(const Cargo& cargo) const {
		return this->name_ == cargo.getName() && this->amount_ == cargo.getAmount() && this->basePrice_ == cargo.getBasePrice();
	}

	constexpr std::string Cargo::GetName() {
		return name_;
	}

	constexpr size_t Cargo::GetAmount() {
		return amount_;
	}

	constexpr size_t Cargo::GetBestPrice() {
		return basePrice_;
	}
};
