#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>

#include "alcohol.hpp"
#include "fruit.hpp"
#include "item.hpp"
#include "store.hpp"

constexpr char FRUIT_NAME[] = "melon";
constexpr size_t FRUIT_SPOIL_TIME = 5;
constexpr size_t FRUIT_BASEPRICE = 10;
constexpr size_t FRUIT_AMOUNT = 100;

constexpr char ITEM_NAME[] = "coffee";
constexpr size_t ITEM_AMOUNT = 100;
constexpr size_t ITEM_BASEPRICE = 30;
constexpr Item::Rarity ITEM_RARITY = Item::Rarity::common;

constexpr char ALCOHOL_NAME[] = "vodka";
constexpr size_t ALCOHOL_BASEPRICE = 20;
constexpr size_t ALCOHOL_STRENGTH = 40;
constexpr size_t ALCOHOL_AMOUNT = 100;

Store::Store(Time* time, size_t capacity,size_t availableFunds) :
    capacity_(capacity),    
    availableFunds_(availableFunds),
    time_(time)
{
     time_->addObserver(this);
     generateCargo();
}

Store::~Store()
{
    time_->removeObserver(this);
}

/*public*/
//-----------------------------------------------------------------------------------
// <summary> The buy method allows Player to purchase cargo in store
//-----------------------------------------------------------------------------------
Store::Response Store::buy(Cargo* cargo, size_t amount, Player* player, Store* store)
{
    if (cargo) {
        if (getCargo(cargo->getName()) != nullptr) {
            size_t totalPrice = store->getCargo(cargo->getName())->getPrice() * amount;
    
            if (player->getMoney() < totalPrice)
                return Response::lack_of_money;

            if (getCargo(cargo->getName())->getAmount() < amount)
                return Response::lack_of_cargo;

            if (player->getAvailableSpace() < getCargo(cargo->getName())->getAmount())
                return Response::lack_of_space;

            setAvailableFunds(getAvailableFunds() + totalPrice);
            updateCargo(cargo, amount, updateMode::BUY);

            std::cout << "\n# Unit price: " << store->getCargo(cargo->getName())->getPrice() << '\n';
            std::cout << "# Total price: " << totalPrice << '\n';

            std::unique_ptr<Cargo> purchase = cargo->clone();
            purchase->setAmount(amount);
            player->purchaseCargo(std::move(purchase), totalPrice);

            return Response::done;
        }
    }
    return Response::invalid_cargo;
}

/*public*/
//-----------------------------------------------------------------------------------
// <summary> The sell method allows Player to sell cargo in store
//-----------------------------------------------------------------------------------
Store::Response Store::sell(Cargo* cargo, size_t amount, Player* player)
{
    if (cargo) {
        if (getCargo(cargo->getName()) != nullptr) {
            size_t totalPrice = player->getCargo(cargo->getName())->getPrice() * amount;

            if (getAvailableFunds() < totalPrice)
                return Response::lack_of_money;

            if (player->getCargo(cargo->getName())->getAmount() < amount)
                return Response::lack_of_cargo;

            if (getAvaiableSpace() < player->getCargo(cargo->getName())->getAmount())
                return Response::lack_of_space;

            setAvailableFunds(getAvailableFunds() - totalPrice);
            updateCargo(cargo, amount, updateMode::SELL);

            std::cout << "\n# Unit price: " << player->getCargo(cargo->getName())->getPrice() << '\n';
            std::cout << "# Total price: " << totalPrice << '\n';

            std::unique_ptr<Cargo> sale = cargo->clone();
            sale->setAmount(amount);
            player->sellCargo(std::move(sale), totalPrice);

            return Response::done;
        }
    }
    return Response::invalid_cargo;
}

/*public*/
//-----------------------------------------------------------------------------------
// <summary> This method allows to add cargo to the store / updated the cargo vec
//-----------------------------------------------------------------------------------
bool Store::addCargo(Cargo* cargo)
{
    bool success = false;
    if (getAvaiableSpace() >= cargo->getAmount()) {
        auto ptrCargo = getCargo(cargo->getName());
        if (ptrCargo == nullptr) {
            cargo_.emplace_back(cargo->clone());
        } else {
            size_t tmpAmount = ptrCargo->getAmount() + cargo->getAmount();
            ptrCargo->setAmount(tmpAmount);
        }
        success = true;
    }
    return success;
}

/*public*/
//-----------------------------------------------------------------------------------
// <summary> Finds particular cargo in cargo vec using std::name for comparsion
//-----------------------------------------------------------------------------------
Cargo* Store::getCargo(const std::string& name)
{
    return Common::getCargo(name, cargo_);
}

/*public*/
//-----------------------------------------------------------------------------------
// <summary> Checks the Store's avaiable space
//-----------------------------------------------------------------------------------
size_t Store::getAvaiableSpace() const
{
    return Common::getAvailableSpace(capacity_, cargo_);
}

/*public*/
//-----------------------------------------------------------------------------------
// <summary> Checks the Store's avaiable funds
//-----------------------------------------------------------------------------------
size_t Store::getAvailableFunds() const 
{
    return availableFunds_;
}

/*public*/
//-----------------------------------------------------------------------------------
// <summary> Sets the Store's avaiable capacity
//-----------------------------------------------------------------------------------
void Store::setCapacity(const size_t amount)
{
    capacity_ = amount;
}

/*public*/
//-----------------------------------------------------------------------------------
// <summary> Sets the Store's avaiable funds
//-----------------------------------------------------------------------------------
void Store::setAvailableFunds(const size_t amount)
{
    availableFunds_ = amount;
}

/*public*/
//-----------------------------------------------------------------------------------
// <summary> Prints out the cargo vector content
//-----------------------------------------------------------------------------------
bool Store::printStoreCargo()
{
    return Common::printCargo(cargo_);
}

/*private*/
//-----------------------------------------------------------------------------------
// <summary> This method is used for updating the cargo amount in cargo vec while
//           player is buying/selling goods
//-----------------------------------------------------------------------------------
void Store::updateCargo(Cargo* cargo, size_t amount, updateMode mode)
{
    if (mode == BUY) {
        if (getCargo(cargo->getName())->getAmount() == amount) {
            auto it = std::find_if(cargo_.begin(), cargo_.end(),
                                   [=](std::unique_ptr<Cargo>& el) { return el->getName() == cargo->getName(); });
            cargo_.erase(it);
        } else {
            size_t tmpAmount = getCargo(cargo->getName())->getAmount() - amount;
            getCargo(cargo->getName())->setAmount(tmpAmount);
        }
    } else if (mode == SELL) {
        size_t tmpAmount = getCargo(cargo->getName())->getAmount() + amount;
        getCargo(cargo->getName())->setAmount(tmpAmount);
    }
}

/*public*/
//-----------------------------------------------------------------------------------
// <summary> Prints the relevant Response message
//-----------------------------------------------------------------------------------
void Store::printResponseMessage(Response& response)
{
    if (response == Response::invalid_cargo)
        std::cout << "Response Message: Invalid cargo.\n";
    else if (response == Response::done)
        std::cout << "Response Message: Transaction completed.\n";
    else if (response == Response::lack_of_cargo)
        std::cout << "Response Message: There might be not enough cargo.\n";
    else if (response == Response::lack_of_money)
        std::cout << "Response Message: Not enought money.\n";
    else if (response == Response::lack_of_space)
        std::cout << "Response Message: Not enouhg space.\n";
}

std::ostream& operator<<(std::ostream& out, const Store& store)
{
    for (const auto& cargo : store.cargo_) {
        out << "Product: " << cargo->getName() << '\n';
        out << "Amount: " << cargo->getAmount() << '\n';
        out << "Base price: " << cargo->getBasePrice() << '\n';

        if (typeid(*cargo) == typeid(Fruit)) {
            Fruit* fruit = static_cast<Fruit*>(cargo.get());
            out << "Current price: " << fruit->getPrice() << '\n';
            out << "Expires in: " << fruit->getTimeToSpoilLeft() << '\n';
        } else if (typeid(*cargo) == typeid(Item)) {
            Item* item = static_cast<Item*>(cargo.get());
            out << "Current price: " << item->getPrice() << '\n';
            switch (item->getRarity()) {
                case (Item::Rarity::common):
                    out << "Rarity: common\n";
                    break;
                case (Item::Rarity::epic):
                    out << "Rarity: epic\n";
                    break;
                case (Item::Rarity::legendary):
                    out << "Rarity: legendary\n";
                    break;
                case (Item::Rarity::rare):
                    out << "Rarity: rare\n";
                    break;
            }
        } else if (typeid(*cargo) == typeid(Alcohol)) {
            Alcohol* alcohol = static_cast<Alcohol*>(cargo.get());
            out << "Strength: " << alcohol->getStrength() << '\n';
            out << "Price: " << alcohol->getPrice() << '\n';
        }
    }
    return out;
}

void Store::nextDay() 
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<size_t> amountAvailable(AMOUNT_MIN, AMOUNT_MAX);

    for (const auto& item : cargo_) {
        item->setAmount(amountAvailable(generator));
    }
}

void Store::generateCargo() 
{
    Fruit fruit(FRUIT_NAME, FRUIT_AMOUNT, FRUIT_BASEPRICE, FRUIT_SPOIL_TIME, time_);
    addCargo(&fruit);

    Item item(ITEM_NAME, ITEM_AMOUNT, ITEM_BASEPRICE, ITEM_RARITY, time_);
    addCargo(&item);

    Alcohol alcohol(ALCOHOL_NAME, 
                      ALCOHOL_AMOUNT, 
                      ALCOHOL_BASEPRICE, 
                      ALCOHOL_STRENGTH, 
                      time_);
    addCargo(&alcohol);
}
