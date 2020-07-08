#include "store.hpp"
#include "constValues.hpp"

#include <algorithm>
#include <iomanip>
#include <random>

Store::Store(Time* gameTime) : timeTracker_(gameTime) {
    generateGoods();
}

Response Store::buys(Cargo* cargo, size_t amount, Player* player, size_t totalPrice) {
    if (cargo->getAmount() < amount) {
        return Response::lack_of_cargo;
    }
    if (player->getAvailableSpace() < amount) {
        return Response::lack_of_space;
    }
    if (player->getMoney() < totalPrice) {
        return Response::lack_of_money;
    }
    *cargo -= amount;
    player->takeMoney(totalPrice);
    return Response::done;
}

Response Store::buy(Cargo* cargo, size_t amount, Player* player) {
    size_t totalPrice = cargo->getPrice() * amount;

    if (cargo->getAmount() < amount) {
        return Response::lack_of_cargo;
    }
    if (player->getAvailableSpace() < amount) {
        return Response::lack_of_space;
    }
    if (player->getMoney() < totalPrice) {
        return Response::lack_of_money;
    }

    }
    Alcohol alcoBought(alco->getName(), amount, alco->getBasePrice(), alco->getPower(), timeTracker_);
    alcosSold_.push_back(std::move(alcoBought));
    player->giveCargo(&alcosSold_.back());
    return result;
}

Response Store::buy(Fruit* fruit, size_t amount, Player* player) {
    size_t totalPrice = fruit->getPrice() * amount;
    Response result = Store::buys(fruit, amount, player, totalPrice);
    if (result != Response::done) {
        return result;
    }
    Fruit fruitBought(fruit->getName(), amount, fruit->getBasePrice(), fruit->getExpiryDate(), fruit->getTimeElapsed(),
                      timeTracker_);
    fruitsSold_.push_back(std::move(fruitBought));
    player->giveCargo(&fruitsSold_.back());
    return result;
}

Response Store::buy(Cargo* cargo, size_t amount, Player* player) {
    size_t totalPrice = cargo->getPrice() * amount;
    Response result = Store::buys(item, amount, player, totalPrice);
    if (result != Response::done) {
        return result;
    }
    Item itemBought(item->getName(), amount, item->getBasePrice(), static_cast<int>(item->getRarity()), timeTracker_);
    itemsSold_.push_back(std::move(itemBought));
    player->giveCargo(&itemsSold_.back());
    return result;
}

Response Store::sells(Cargo* item, size_t amount, Player* player, size_t totalPrice) {
    if (item->getAmount() < amount) {
        return Response::lack_of_cargo;
    }
    *item -= amount;
    player->giveMoney(item->getPrice() * amount);
    return Response::done;
}

Response Store::sell(Alcohol* alco, size_t amount, Player* player) {
    size_t totalPrice = alco->getPrice() * amount;
    Response result = Store::sells(alco, amount, player, totalPrice);
    if (result != Response::done) {
        return result;
    }
    if (alco->getAmount() == 0) {
        player->removeAlco(alco);
    }
    return Response::done;
}

Response Store::sell(Fruit* fruit, size_t amount, Player* player) {
    size_t totalPrice = fruit->getPrice() * amount;
    Response result = Store::sells(fruit, amount, player, totalPrice);
    if (result != Response::done) {
        return result;
    }
    if (fruit->getAmount() == 0) {
        player->removeFruit(fruit);
    }
    return Response::done;
}

Response Store::sell(Item* item, size_t amount, Player* player) {
    size_t totalPrice = item->getPrice() * amount;
    Response result = Store::sells(item, amount, player, totalPrice);
    if (result != Response::done) {
        return result;
    }
    if (item->getAmount() == 0) {
        player->removeItem(item);
    }
    return Response::done;
}

void Store::generateGoods() {
    cargoToSell_.clear();
    std::random_device device;
    std::mt19937 generator(device());
    randomVal itemNumber(1, 8);
    randomVal expiryDate(constValues::minExpiryDate, constValues::maxExpiryDate);
    randomVal amount(constValues::minAmount, constValues::maxAmount);

    for (size_t i = 0; i < constValues::numerOfItems; i++) {
        AddGeneratedCargo(expiryDate(generator), amount(generator), i);
    }
}

void Store::AddGeneratedCargo(size_t expiryDate, size_t amount, size_t pos) {
    switch (pos) {
    case 1:
            cargoToSell_.emplace_back(std::make_shared<Store>(
                Fruit("Bananas", amount, 35, expiryDate, 0, timeTracker_));
            break;
        case 2:
            cargoToSell_.emplace_back(std::make_shared<Store>(
                Fruit("Watermelon", amount, 35, expiryDate, 0, timeTracker_)));
            break;
        case 3:
            cargoToSell_.emplace_back(
                std::make_shared<Store>(Alcohol("Jack Daniel’s", amount, 35, 40, timeTracker_)));
            break;
        case 4:
            cargoToSell_.emplace_back(
                std::make_shared<Store>(Alcohol("Spirit", amount, 35, 96, timeTracker_)));
        case 5:
            cargoToSell_.emplace_back(
                Item("Pistol", amount, 500, static_cast<int>(Rarity::common), timeTracker_));
            break;
        case 6:
            cargoToSell_.emplace_back(
                Item("Cannon", amount, 2000, static_cast<int>(Rarity::common), timeTracker_));
            break;
        case 7:
            cargoToSell_.emplace_back(
                Item("Flag", amount, 65, static_cast<int>(Rarity::common), timeTracker_));
            break;
        case 8:
            cargoToSell_.emplace_back(std::make_shared<Store>(
                Fruit("Apples", amount, 35, expiryDate, 0, timeTracker_)));
            break;
        default:
            std::cerr << "RNG error!\n";
            break;
    }
}

std::ostream& operator<<(std::ostream& print, const Store& store) {
    std::string trail("-", 40);
    print << "What you want to buy or sell: \n";
    print << std::setw(5) << "No.||" << std::setw(10) << " Name    ||" << std::setw(9) << " Amount ||" << std::setw(14)
          << " Sell Price ||" << std::setw(14) << " Buy Price ||"
          << "\n";

    std::for_each(store.cargoToSell_.begin(), store.cargoToSell_.end(),
                  [&print, &store, i{0}](const auto& cargo) mutable {
                      print << std::setw(2) << ++i << " ||" << std::setw(8) << cargo.getName() << " ||" << std::setw(7)
                            << cargo.getAmount() << " ||" << std::setw(11) << cargo.getPrice() << " ||"
                            << "\n";
                  });
    return print;
}
