#include "Game.hpp"

struct GoodsData {
    constexpr GoodsData(const char* name)
        : name(name) {}
    constexpr GoodsData(const char* name, size_t value)
        : name(name), value(value) {}

    const char* name;
    size_t value = 0;
};

std::unique_ptr<Cargo> generateCargo() {
    // https://portroyale3.fandom.com/wiki/Goods
    constexpr std::array goods{
        GoodsData{"Wood", 33},
        GoodsData{"Adobe Bricks", 33},
        GoodsData{"Wheat", 33},
        GoodsData{"Fruits", 50},
        GoodsData{"Corn", 50},
        GoodsData{"Sugar", 50},
        GoodsData{"Hemp", 50},
        GoodsData{"Textiles", 150},
        GoodsData{"Metal", 83},
        GoodsData{"Cotton", 50},
        GoodsData{"Metal Goods", 200},
        GoodsData{"Dyes", 100},
        GoodsData{"Coffee", 140},
        GoodsData{"Cocao", 140},
        GoodsData{"Tobacco", 100},
        GoodsData{"Meat", 300},
        GoodsData{"Clothing", 450},
        GoodsData{"Ropes", 150},
        GoodsData{"Rum", 267},
        GoodsData{"Bread", 142},
    };
    auto randomCargo = std::rand() % goods.size();
    auto randomAmount = std::rand() % 99 + 1;
    auto good = goods[randomCargo];
    auto ptr = std::make_unique<Fruit>(good.name, randomAmount, good.value, 10);
    return ptr;  // RVO
}

void printResponse(Response response) {
    std::array text{
        std::string("done"),
        std::string("lack_of_money"),
        std::string("lack_of_cargo"),
        std::string("lack_of_space")};
    std::cout << "Response: " << text[static_cast<size_t>(response)] << "\n";
}

void printPlayerStatus(const Player& player) {
    std::cout << "Player money: " << player.getMoney() << "\t\tTarget money: " << final_goal << '\n';
}

void printMenu(std::vector<std::unique_ptr<Command>>& commands) {
    std::cout << "\n\nMENU -------\n";
    int index = 0;
    for (const auto& command : commands) {
        std::cout << index << " - " << command->getName() << '\n';
        ++index;
    }
    std::cout << index << " - Exit\n";
}

void printStoreCargoList(const Store& store) {
    printf("\033[31m");
    std::cout << "STORE LIST -------\n";
    for (size_t i = 0; i < store.getCargoVec().size(); ++i) {
        std::cout << i << "\t"                                              //
                  << "Name: " << store.getCargoVec()[i]->getName() << "\t\t"    //
                  << "Amount: " << store.getCargoVec()[i]->getAmount() << "\t"  //
                  << "Price: " << store.getCargoVec()[i]->getPrice() << "\n";   //
    }
    printf("\033[0m\n");
}

void printShipCargoList(const Player& player) {
    printf("\033[33;44m");
    std::cout << "SHIP LIST -------\n";
    for (size_t i = 0; i < player.getShip()->getCargoVec().size(); ++i) {
        std::cout << i << "\t"                                                              //
                  << "Name: " << player.getShip()->getCargoVec()[i]->getName() << "\t\t"    //
                  << "Amount: " << player.getShip()->getCargoVec()[i]->getAmount() << "\t"  //
                  << "Price: " << player.getShip()->getCargoVec()[i]->getPrice() << "\n";   //
    }
    printf("\033[0m\n");
}

//universal function to get value in range from user
size_t ChoseOption(size_t limit) {
    size_t result = 0;
    std::string input;
    std::cout << "Chose between [0," << (limit - 1) << "], or " << limit << " to abort:\n";

    do {
        std::cin >> input;
        result = atoi(input.c_str());
    } while (result > limit);

    return static_cast<size_t>(result);
}

const Cargo* ChoseCargoFromStore(size_t chose, Store& store) {
    auto limit = store.getCargoVec().size();
    if (chose == limit) {
        return nullptr;
    }
    return store.getCargoVec()[chose].get();
}

const Cargo* ChoseCargoFromShip(size_t chose, Player& player) {
    auto limit = player.getShip()->getCargoVec().size();
    if (chose == limit) {
        return nullptr;
    }
    return player.getShip()->getCargoVec()[chose].get();
}

class Menu : public Command {
public:
    Menu() = default;
    void operator()(Player& player, Store& store) override {
        printStoreCargoList(store);
        printShipCargoList(player);
    }

    std::string getName() const override { return "Show menu"; }
};

class Trade : public Command {
public:
    Trade() = default;
    void operator()([[maybe_unused]]Player& player, [[maybe_unused]]Store& store) override {
    }

    std::string getName() const override { return "Go to store"; }
};

class TradeBuy : public Command {
public:
    TradeBuy() = default;
    void operator()(Player& player, Store& store) override {
        while (true) {
            size_t limit = 0;

            printStoreCargoList(store);
            printPlayerStatus(player);

            std::cout << "Which Cargo want to Buy from store?\n";
            limit = store.getCargoVec().size();
            auto chose = ChoseOption(limit);
            if (chose >= limit) {
                return;
            }
            const Cargo* const cargo = ChoseCargoFromStore(chose, store);

            std::cout << "Amount:\n";
            limit = player.getMoney() / cargo->getPrice();
            limit = std::min(limit, cargo->getAmount()) + 1;
            size_t amount = ChoseOption(limit);
            if (amount >= limit) {
                return;
            }
            
            Response response = store.sell(cargo, amount, &player);
            printResponse(response);
        }
    }

    std::string getName() const override { return "Buy"; }
};

class TradeSell : public Command {
public:
    TradeSell() = default;
    void operator()(Player& player, Store& store) override {
        while (true) {
            size_t limit = 0;
            printShipCargoList(player);
            printPlayerStatus(player);

            std::cout << "Which Cargo want to sell to store?\n";
            limit = player.getShip()->getCargoVec().size();
            auto chose = ChoseOption(limit);
            if (chose >= limit) {
                break;
            }
            const Cargo* const cargo = ChoseCargoFromShip(chose, player);

            std::cout << "Amount:\n";
            limit = player.getMoney() / cargo->getPrice();
            limit = std::min(limit, cargo->getAmount()) + 1;
            size_t amount = ChoseOption(limit);
            if (amount >= limit) {
                break;
            }

            Response response = store.buy(cargo, amount, &player);
            printResponse(response);
        }
    }

    std::string getName() const override { return "Sell"; }
};

class NextDay : public Command {
public:
    NextDay() = default;
    void operator()([[maybe_unused]] Player& player, [[maybe_unused]] Store& store) override {
        Time::getInstance()->nextDay();
    }

    std::string getName() const override { return "Next day"; }
};

class Travel : public Command {
public:
    Travel() = default;
    void operator()([[maybe_unused]] Player& player, [[maybe_unused]] Store& store) override {
        for (size_t day = 1; day <= distance; ++day) {
            nextDay(player, store);
            std::cout << "Day " << day << " on travel\n";
        }
    }

    std::string getName() const override { return "Travel"; }

private:
    NextDay nextDay;
    size_t distance = 5;//for show concept
};

void Game::startGame() {
    init();
    //auto time = Time::getInstance();

    unsigned char letter;
    while (!endGame and !playerWin) {
        printStoreCargoList(store);
        printShipCargoList(player);

        printPlayerStatus(player);

        printMenu(commands);
        std::cin >> letter;
        //std::cin.clear();

        size_t optionId = static_cast<size_t>(letter - '0');
        if (optionId < commands.size()) {
            Command& command = *commands[optionId];
            command(player, store);
        } else if (optionId == commands.size()) {
            endGame = true;
        }

        playerWin = player.getMoney() >= goal_;
    }
}

void Game::init() {
    auto payMethod = [this](size_t cost){return this->player.pay(cost);};
    player.getShip()->setDebt(payMethod);

    auto changeAssortment = [this](){fillCargo(this->store, Game::storeCargoNumber);};
    store.changeAssortment = changeAssortment;

    fillCargo(*player.getShip(), startingPlayerCargoNumber);

    std::cout << '\n';

    fillCargo(store, storeCargoNumber);

    commands.push_back(std::make_unique<Menu>());
    commands.push_back(std::make_unique<TradeBuy>());
    commands.push_back(std::make_unique<TradeSell>());
    commands.push_back(std::make_unique<NextDay>());
}
