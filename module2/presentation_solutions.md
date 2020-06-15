<!-- .slide: data-background="#111111" -->

# Programowanie obiektowe

## Przykładowe rozwiązania

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

### Zadanie 1

Cargo.hpp

```cpp
bool operator==(const Cargo& cargo) const;
```

Cargo.cpp

```cpp
bool Cargo::operator==(const Cargo& cargo) const {
    return Cargo.getBasePrice() == base_price_ && Cargo.getName() == name_;
}
```

___

### Zadanie 2

Cargo.hpp

```cpp
std::string getName() const;
size_t getAmount() const;
size_t getBasePrice() const;
```

Cargo.cpp

```cpp
std::string Cargo::getName() const { return name_; }
size_t Cargo::getAmount() const { return amount_; }
size_t Cargo::getBasePrice() const { return base_price_; }
```

___

### Zadanie 3 #1

Island.hpp

```cpp
#include <iostream>
#include <memory>

#include "Store.hpp"

class Time;

// Class describes position of island and available store.
class Island {
public:
    class Coordinates {
    public:
        Coordinates() = default;
        Coordinates(size_t pos_x, size_t pos_y)
            : pos_x_(pos_x), pos_y_(pos_y) {}

        bool operator==(const Coordinates& lhs) const {
            return this->pos_x_ == lhs.pos_x_ && this->pos_y_ == lhs.pos_y_;
        }

    private:
        const size_t pos_x_{0};
        const size_t pos_y_{0};
    };

    Island() {}
    Island(size_t pos_x, size_t pos_y, Time* time);
    Coordinates getCoordinates() const { return position_; }
    Store* getStore() const { return store_.get(); }

private:
    std::unique_ptr<Store> store_;
    Coordinates position_;
};
```

___

### Zadanie 3 #2

Island.cpp

```cpp
#include "GTime.hpp"
#include "Island.hpp"

Island::Island(size_t pos_x, size_t pos_y, Time* time)
    : position_(Coordinates(pos_x, pos_y)),
      store_(std::make_unique<Store>(time)) {
}
```

___

## Zadanie 4/5/6 #1

Map.hpp

```cpp
class Time;

// Class responsible for map generation which will be used to travel.
class Map {
public:
    Map(Time* time);
    void travel(Island* destination);
    Island* getIsland(const Island::Coordinates& coordinate);
    Island* getCurrentPosition() const { return current_position_; }
    friend std::ostream& operator<<(std::ostream& out, const Map& map);

private:
    Island* current_position_;
    std::vector<Island> islands_;
};
```

___

### Zadanie 4/5/6 #2

Map.cpp

```cpp
constexpr size_t kIslandNum = 10;
constexpr size_t kWidth = 50;
constexpr size_t kHeight = 50;

Map::Map(Time* time) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> widthGen(0, kWidth);
    std::uniform_int_distribution<> heightGen(0, kHeight);
    std::vector<Island> islands(kIslandNum);
    std::vector<std::pair<size_t, size_t>> usedPositions;

    // Generate map
    for (size_t i = 0; i < kIslandNum; ++i) {
        while (true) {
            size_t x = widthGen(gen);
            size_t y = heightGen(gen);
            if (std::find_if(begin(usedPositions),
                             end(usedPositions),
                             [x, y](const auto& pos) {
                                 return pos.first == x && pos.second == y;
                             }) == std::end(usedPositions)) {
                usedPositions.push_back({x, y});
                islands_.push_back(Island(x, y, time));
                break;
            }
        }
    }

    current_position_ = &islands_.front();
}

Island* Map::getIsland(const Island::Coordinates& coordinate) {
    auto island = std::find_if(std::begin(islands_),
                               std::end(islands_),
                               [&coordinate](const Island& island) {
                                   return coordinate == island.GetCoordinates();
                               });
    return island != std::end(islands_) ? &*island : nullptr;
}

void Map::travel(Island* destination) {
    current_position_ = destination;
}
```

___

### Zadanie7/8 #1

Player.hpp

```cpp
#include <memory>

#include "Cargo.hpp"
#include "Ship.hpp"

class Time;

// Class is responsible for every action made by player
class Player {
public:
    Player(size_t money, Time* time);
    virtual ~Player() = default;

    virtual size_t getAvailableSpace() const;
    virtual size_t getMoney() const;
    virtual size_t getSpeed() const;
    virtual Cargo* getCargo(size_t index) const;

private:
    std::unique_ptr<Ship> ship_;
    size_t money_;
    size_t available_space_;
};

```

___

### Zadanie 7/8 #2

Player.cpp

```cpp
constexpr size_t kCapacity = 100;
constexpr size_t kCrew = 50;
constexpr size_t kSpeed = 10;
constexpr char kName[] = "BLACK WIDOW";
constexpr size_t kId = 10;

Player::Player(size_t money, Time* time)
    : ship_(std::make_unique<Ship>(kCapacity, kCrew, kSpeed, kName, kId, time, this)),
      money_(money),
      available_space_(kCapacity) {
}

size_t Player::getMoney() const {
    return money_;
}

size_t Player::getSpeed() const {
    return ship_->getSpeed();
}

Cargo* Player::getCargo(size_t index) const {
    return ship_->getCargo(index);
}

size_t Player::getAvailableSpace() const {
    available_space_ = 0;
    for (const auto cargo : ship_->getCargos()) {
        available_space_ += cargo->getAmount();
    }

    return available_space_;
}
```

___

## Q&A
