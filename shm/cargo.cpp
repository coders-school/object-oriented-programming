#include <limits>
#include "cargo.hpp"
#include "player.hpp"
#include "ship.hpp"

Cargo::Cargo(std::string name, size_t amount, size_t basePrice) :name_(name), amount_(amount), basePrice_(basePrice){}

/*size_t Player::gettingCargoAmount()
{
    std::vector<Cargo*> shipCargo = ship_->getCargo();
}
*/
Cargo &Cargo::operator+=(size_t amount)
{
    auto ship = std::make_unique<Ship>(20, 1, 2, "titanic", 3);
    Player player(std::move(ship), 1, 1);

    //if(amount + amount > player.getCargo(0)->getAmount())
    amount_ += amount;
    return *this;
}

Cargo &Cargo::operator-=(size_t amount)
{
    if(amount_ < amount){
        amount_ = 0;
    }
    else{
        amount_ -= amount;
    }
    return *this;
}

bool Cargo::operator==(const Cargo &cargo) const
{
    return name_ == cargo.name_ && amount_ == cargo.amount_ && basePrice_ == cargo.basePrice_;
}

void Cargo::printCargo() const {
    std::cout << "Cargo Name: " << name_ << ", amount: " << amount_ << '\n';
}