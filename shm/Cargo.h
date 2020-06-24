#pragma once
#include <string>

#include<string>

class Cargo {
public:
	Cargo(std::string name, size_t amount, size_t basePrice);
	
	Cargo& operator+=(size_t amount);
	Cargo& operator-=(size_t amount);
	bool operator==(const Cargo& cargo) const;

	constexpr std::string getName() const;
	constexpr size_t getAmount() const;
	constexpr size_t getBasePrice() const;

protected:
	std::string name_;
	size_t amount_;
	size_t basePrice_;
};
