#include "Game.hpp"
#include "Cargos.hpp"
#include "Commands.hpp"

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
    return std::make_unique<Fruit>(good.name, randomAmount, good.value, 10);
}

void Game::fillCargo(Warehouse& holder, size_t number) {
    holder.clear();
    for (size_t i = 0; i < number; ++i) {
        auto cargo = generateCargo();
        std::cout << cargo->getName() << '\n';
        holder.load(std::move(cargo));
    }
}

void Game::startGame() {
    init();

    std::string menuOptionName;
    while (!endGame and !playerWin) {
        printStoreCargoList(store);
        printShipCargoList(player);

        printPlayerStatus(player);
        printPlayerGoal(goal_);

        printMenu(commands);
        std::cin >> menuOptionName;
        try {
            Command& command = *commands.at(menuOptionName);
            command(player, store);
        } catch (...) {
        }
        playerWin = player.getMoney() >= goal_;
    }
    if(playerWin){
        std::cout << " Congratulation !!!\n"
                     "You won the game !!!\n";
    }else{
        std::cout << "    GAME\n"
                     "    OVER\n";
    }
}

void fillCargo(Warehouse &holder, size_t number) {
    holder.clear();
    for (size_t i = 0; i < number; ++i) {
        auto cargo = generateCargo();
        std::cout << cargo->getName() << '\n';
        holder.load(std::move(cargo));
    }
}

void Game::init() {
    auto payMethod = [this](size_t cost) { return this->player.pay(cost); };
    player.getShip()->setDebt(payMethod);

    auto changeAssortment = [this]() { fillCargo(this->store, Game::storeCargoNumber); };
    store.changeAssortment = changeAssortment;

    fillCargo(*player.getShip(), startingPlayerCargoNumber);

    std::cout << '\n';

    fillCargo(store, storeCargoNumber);

    commands["1"] = (std::make_unique<Menu>());
    commands["2"] = (std::make_unique<TradeBuy>());
    commands["3"] = (std::make_unique<TradeSell>());
    commands["4"] = (std::make_unique<NextDay>());
    commands["5"] = (std::make_unique<Exit>(endGame));
}
