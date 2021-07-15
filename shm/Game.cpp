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
    auto ptr = std::make_unique<CargoDefault>(good.name, randomAmount, good.value);
    return ptr;  // RVO
}

void Game::startGame() {
    init();
    auto time = Time::getInstance();

    char letter;
    while (!endGame and !playerWin) {
        printPlayerStatus();
        printMenu();
        std::cin >> letter;
        std::cin.clear();

        switch (letter) {
        case '0':
            ShowOption();
            break;
        case '1':  //buy
            BuyOption();
            break;
        case '2':  //sell
            SellOption();
            break;
        case '3':  //next day
            time->update();
            break;
        case '4':  //end game
            endGame = true;
            break;
        default:
            break;
        }

        playerWin = player.getMoney() == goal_;
    }
}

void Game::ShowOption() {
    printStoreCargoList();
    printShipCargoList();
}

void Game::BuyOption() {
    Cargo* cargo = nullptr;
    size_t amount = 0;
    size_t limit = 0;
    Response response;

    while (true) {
        cargo = nullptr;
        amount = 0;
        limit = 0;

        printStoreCargoList();
        printPlayerStatus();

        std::cout << "Which Cargo want to Buy from store?\n";
        limit = store.cargoVec_.size();
        auto chose = ChoseOption(limit);
        if (amount >= limit) {
            break;
        }
        cargo = ChoseCargoFromStore(chose);
        std::cout << "Amount:\n";
        limit = player.getMoney() / cargo->getPrice();
        limit = std::min(limit, cargo->getAmount()) + 1;
        amount = ChoseOption(limit);
        if (amount >= limit) {
            break;
        }
        response = store.sell(cargo, amount, &player);
        printResponse(response);
    }
}

void Game::SellOption() {
    Cargo* cargo = nullptr;
    size_t amount = 0;
    size_t limit = 0;
    Response response;

    while (true) {
        printShipCargoList();
        printPlayerStatus();
        std::cout << "Which Cargo want to sell to store?\n";
        limit = player.getShip()->getCargoVec().size();
        auto chose = ChoseOption(limit);
        if (chose >= limit) {
            break;
        }
        cargo = ChoseCargoFromShip(chose);
        std::cout << "Amount:\n";
        limit = player.getMoney() / cargo->getPrice();
        limit = std::min(limit, cargo->getAmount()) + 1;
        amount = ChoseOption(limit);
        if (amount >= limit) {
            break;
        }
        response = store.buy(cargo, amount, &player);
        printResponse(response);
    }
}

void Game::init() {
    for (int i = 0; i < 3; ++i) {
        auto cargo = generateCargo();
        std::cout << cargo->getName() << '\n';
        player.getShip()->load(std::move(cargo));
    }
    std::cout << '\n';
    for (int i = 0; i < 3; ++i) {
        auto cargo = generateCargo();
        std::cout << cargo->getName() << '\n';
        store.load(std::move(cargo));
    }
}

void Game::printResponse(Response response) const {
    std::array text{
        std::string("done"),
        std::string("lack_of_money"),
        std::string("lack_of_cargo"),
        std::string("lack_of_space")};
    std::cout << "Response: " << text[static_cast<size_t>(response)] << "\n";
}

void Game::printPlayerStatus() const {
    std::cout << "Player money: " << player.getMoney() << "\t\tTarget money: " << goal_ << '\n';
}

void Game::printMenu() const {
    std::cout << "\n\nSTORE LIST -------\n";
    std::cout << "0 - show store and ship cargo\n";
    std::cout << "1 - buy\n";
    std::cout << "2 - sell\n";
    std::cout << "3 - next day\n";
    std::cout << "4 - end game\n";
}

void Game::printStoreCargoList() const {
    printf("\033[31m");
    std::cout << "STORE LIST -------\n";
    for (size_t i = 0; i < store.cargoVec_.size(); ++i) {
        std::cout << i << "\t"                                              //
                  << "Name: " << store.cargoVec_[i]->getName() << "\t\t"    //
                  << "Amount: " << store.cargoVec_[i]->getAmount() << "\t"  //
                  << "Price: " << store.cargoVec_[i]->getPrice() << "\n";   //
    }
    printf("\033[0m\n");
}

void Game::printShipCargoList() const {
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

size_t Game::ChoseOption(size_t limit) const {
    size_t result = 0;
    std::string input;
    std::cout << "Chose between [0," << (limit - 1) << "], or " << limit << " to abort:\n";

    do {
        std::cin >> input;
        result = atoi(input.c_str());
    } while (result > limit);

    return static_cast<size_t>(result);
}

Cargo* Game::ChoseCargoFromStore(size_t chose) {
    auto limit = store.cargoVec_.size();
    if (chose == limit) {
        return nullptr;
    }
    return store.cargoVec_[chose].get();
}

Cargo* Game::ChoseCargoFromShip(size_t chose) {
    auto limit = player.getShip()->getCargoVec().size();
    if (chose == limit) {
        return nullptr;
    }
    return player.getShip()->getCargoVec()[chose].get();
}
