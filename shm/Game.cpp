#include "Game.hpp"
#include "Cargos/Cargos.hpp"
#include "Commands/Commands.hpp"

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

void Game::startGame() {
    init();

    unsigned char letter;
    while (!endGame and !playerWin) {
        printStoreCargoList(store);
        printShipCargoList(player);

        printPlayerStatus(player);
        printPlayerGoal(goal_);

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

void fillCargo(Warehouse &holder, size_t number) {
    holder.clear();
    for (size_t i = 0; i < number; ++i) {
        auto cargo = generateCargo();
        std::cout << cargo->getName() << '\n';
        holder.load(std::move(cargo));
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
