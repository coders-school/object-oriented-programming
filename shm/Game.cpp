#include "Game.hpp"
#include "Cargos.hpp"
#include "Commands.hpp"

#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace ns {
template <typename D>
void to_json(json& j, const std::unique_ptr<CargoDefault, D>& cargo) {
    j = json{
        {"type", "default"},
        {"name", cargo->getName()},
        {"amount", cargo->getAmount()},
        {"value", cargo->getPrice()}};
}
template <typename D>
void to_json(json& j, const std::unique_ptr<Fruit, D>& cargo) {
    j = json{
        {"type", "fruit"},
        {"name", cargo->getName()},
        {"amount", cargo->getAmount()},
        {"best before", cargo->getMaxFreshTime()},
        {"value", cargo->getPrice()}};
}
template <typename D>
void to_json(json& j, const std::unique_ptr<DryFruit, D>& cargo) {
    j = json{
        {"type", "dry fruit"},
        {"name", cargo->getName()},
        {"amount", cargo->getAmount()},
        {"best before", cargo->getMaxFreshTime()},
        {"value", cargo->getPrice()}};
}
template <typename D>
void to_json(json& j, const std::unique_ptr<Alcohol, D>& cargo) {
    j = json{
        {"type", "alcohol"},
        {"name", cargo->getName()},
        {"amount", cargo->getAmount()},
        {"percentage", cargo->getPercentage()},
        {"value", cargo->getPrice()}};
}
template <typename D>
void to_json(json& j, const std::unique_ptr<Item, D>& cargo) {
    j = json{
        {"type", "item"},
        {"name", cargo->getName()},
        {"amount", cargo->getAmount()},
        {"quality", static_cast<size_t>(cargo->getQuality())},
        {"value", cargo->getPrice()}};
}

void from_json(const json& j, std::unique_ptr<Cargo>& cargo) {
    auto type = j["type"].get<std::string>();
    auto name = j["name"].get<std::string>();
    auto amount = j["amount"].get<size_t>();

    if (type == "fruit") {
        auto value = j["value"].get<size_t>();
        auto bb = j["best before"].get<size_t>();
        cargo = std::make_unique<Fruit>(name, amount, value, bb);
    } else if (type == "alcohol") {
        auto percentage = j["percentage"].get<char>();
        cargo = std::make_unique<Alcohol>(name, amount, percentage);
    } else if (type == "dry fruit") {
        auto value = j["value"].get<size_t>();
        auto bb = j["best before"].get<size_t>();
        cargo = std::make_unique<DryFruit>(name, amount, value, bb);
    } else if (type == "item") {
        auto value = j["value"].get<size_t>();
        auto quality = j["quality"].get<size_t>();
        cargo = std::make_unique<Item>(name, amount, value, static_cast<Quality>(quality));
    } else {
        auto value = j["value"].get<size_t>();
        cargo = std::make_unique<CargoDefault>(name, amount, value);
    }
}
}  // namespace ns

json j{};

class JsonLoader {
public:
    static void loadCargo(const std::string& filename) {
        std::ifstream file(filename);
        file >> j;
    }

    template <typename T>
    static void saveCargo(const std::string& filename, const T& cargo) {
        json nj;
        ns::to_json(nj, cargo);
        j.push_back(nj);
        std::ofstream file(filename);
        file << j.dump(2);
    }
};

struct GoodsData {
    constexpr GoodsData(const char* name)
        : name(name) {}
    constexpr GoodsData(const char* name, size_t value, const char* type = "default")
        : name(name), value(value), type(type) {}
    const char* name;
    size_t value = 0;
    const char* type = "default";
};

std::unique_ptr<Cargo> generateCargo() {
    // https://portroyale3.fandom.com/wiki/Goods
    constexpr std::array goods{
        GoodsData{"Wood", 33},
        GoodsData{"Adobe Bricks", 33, "item"},
        GoodsData{"Wheat", 33},
        GoodsData{"Fruits", 50, "fruit"},
        GoodsData{"Corn", 50},
        GoodsData{"Sugar", 50},
        GoodsData{"Hemp", 50, "dry fruit"},
        GoodsData{"Textiles", 150},
        GoodsData{"Metal", 83},
        GoodsData{"Cotton", 50},
        GoodsData{"Metal Goods", 200, "item"},
        GoodsData{"Dyes", 100, "dry fruit"},
        GoodsData{"Coffee", 140, "dry fruit"},
        GoodsData{"Cocao", 140, "dry fruit"},
        GoodsData{"Tobacco", 100},
        GoodsData{"Meat", 300},
        GoodsData{"Clothing", 450, "item"},
        GoodsData{"Ropes", 150, "item"},
        GoodsData{"Rum", 267, "alcohol"},
        GoodsData{"Bread", 142},
    };

    if (j.empty()) {// create json with cargo types
        constexpr auto fruitType = "fruit";
        constexpr auto dryfruitType = "dry fruit";
        constexpr auto alcoholType = "alcohol";
        constexpr auto itemType = "item";

        for (const auto& good : goods) {
            auto randomAmount = std::rand() % 99 + 1;
            if (good.type == fruitType) {
                auto cargo = std::make_unique<Fruit>(good.name, randomAmount, good.value, 5);
                JsonLoader::saveCargo("test.json", cargo);
            } else if (good.type == dryfruitType) {
                auto cargo = std::make_unique<DryFruit>(good.name, randomAmount, good.value, 5);
                JsonLoader::saveCargo("test.json", cargo);
            } else if (good.type == alcoholType) {
                auto cargo = std::make_unique<Alcohol>(good.name, randomAmount, 40);
                JsonLoader::saveCargo("test.json", cargo);
            } else if (good.type == itemType) {
                auto cargo = std::make_unique<Item>(good.name, randomAmount, good.value, Quality::common);
                JsonLoader::saveCargo("test.json", cargo);
            } else {
                auto cargo = std::make_unique<CargoDefault>(good.name, randomAmount, good.value);
                JsonLoader::saveCargo("test.json", cargo);
            }
        }
    }

    if (j.empty()) {//load types from json
        JsonLoader::loadCargo("test.json");
    }
    std::unique_ptr<Cargo> cargo{};
    ns::from_json(j[std::rand() % 20], cargo);
    return cargo;
}

namespace {
constexpr static size_t startingPlayerCargoNumber{10ul};
constexpr static size_t storeCargoNumber{10ul};
}  // namespace

Game::Game(size_t startMoney, size_t daysLimit, size_t goal)
    : startMoney_(startMoney), daysLimit_(daysLimit), goal_(goal) {}

void Game::fillCargo(Warehouse& holder, size_t number) {
    holder.clear();
    for (size_t i = 0; i < number; ++i) {
        auto cargo = generateCargo();
        //std::cout << cargo->getName() << '\n';
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
    if (playerWin) {
        std::cout << " Congratulation !!!\n"
                     "You won the game !!!\n";
    } else {
        std::cout << "    GAME\n"
                     "    OVER\n";
    }
}

void fillCargo(Warehouse& holder, size_t number) {
    holder.clear();
    for (size_t i = 0; i < number; ++i) {
        auto cargo = generateCargo();
        //std::cout << cargo->getName() << '\n';
        holder.load(std::move(cargo));
    }
}

void Game::init() {
    auto payMethod = [this](size_t cost) { return this->player.pay(cost); };
    player.getShip()->setDebt(payMethod);

    store.setChangeAssortmentCallback([this]() {
        fillCargo(this->store, storeCargoNumber);
    });

    fillCargo(*player.getShip(), startingPlayerCargoNumber);

    std::cout << '\n';

    fillCargo(store, storeCargoNumber);

    commands["1"] = (std::make_unique<Menu>());
    commands["2"] = (std::make_unique<TradeBuy>());
    commands["3"] = (std::make_unique<TradeSell>());
    commands["4"] = (std::make_unique<NextDay>());
    commands["q"] = (std::make_unique<Exit>(endGame));
}
