<!-- .slide: data-background="#111111" -->

# Programowanie obiektowe

## Hermetyzacja

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Omówienie problemów

___

## Przykładowe rozwiązania

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

## Wprowadzenie do dziedziczenia

Podczas implementacji klas, często możemy zauważyć, że część cech składowych klasy można wykorzystać także w innych klasach.

Weźmy pod lupę klasę Komputer. Jeżeli chcielibyśmy utworzyć klasy: laptop, PC, tablet, to część metod oraz składowych klasy musielibyśmy niepotrzebnie powielić.

___

## `class Computer`

```cpp
class Computer {
public:
    void turnOn();
    void powerOff();
    void restart();

private:
    Processor processor_;
    Drive drive_;
    Motherboard motherboard_;
    GraphicsCard graphics_card_;
    Memory memory_;
};
```

___

## `class Laptop`

```cpp
class Laptop {
public:
    void turnOn();
    void powerOff();
    void restart();
    void display();
    void getUserInput();

private:
    Processor processor_;
    Drive drive_;
    Motherboard motherboard_;
    GraphicsCard graphics_card_;
    Memory memory_;
    Screen screen_;
    Keyboard keyboard_;
};
```

___

## `class Tablet`

```cpp
class Tablet {
public:
    void turnOn();
    void powerOff();
    void restart();
    void display();
    void getUserInput();

private:
    Processor processor_;
    Drive drive_;
    Motherboard motherboard_;
    GraphicsCard graphics_card_;
    Memory memory_;
    Screen screen_;
    Keyboard keyboard_;
};
```

___
<!-- .slide: style="font-size: 0.9em" -->

## Jak uprościć strukturę naszego programu?

```cpp
class Computer {
public:
    void turnOn();
    void powerOff();
    void restart();

protected:
    Processor processor_;
    Drive drive_;
    Motherboard motherboard_;
    GraphicsCard graphics_card_;
    Memory memory_;
};


class Laptop : public Computer {
public:
    void display();
    void getUserInput();

private:
    Screen screen_;
    Keyboard keyboard_;
};


class Tablet : public Computer {
public:
    void display();
    void getUserInput();

private:
    Screen screen_;
    Keyboard keyboard_;
};
```

___

## Klasy bazowe i pochodne

Klasa, po której dziedziczymy, nazywają się  <span class="fragment highlight-green">**klasą bazową**</span>.

Klasy, które dziedziczą nazywa się  <span class="fragment highlight-green">**klasami pochodnymi**</span>.

Inaczej, klasa, po której dziedziczymy to rodzic (parent class).

Klasa, która dziedziczy to dziecko (child class).

___

### Co z metodami klas `Laptop` i `Tablet`, czy można wydzielić kolejną klasę?

```cpp
void display();
void getUserInput();
```

___

## Klasa `Screen` i `TouchScreen`

Załóżmy, że dodajemy klasę `Screen`. Klasa ta wyświetla na bieżąco interfejs użytkownika.

Chcemy też stworzyć klasę reprezentującą ekran dotykowy, który również umożliwia odczyt akcji od użytkownika i ich wyświetlanie.

<style>
.container {
    display: flex;
}
.col {
    flex: 1;
    margin: 1%;
}
</style>

<div class="container">

<div class="col">

```cpp
class Screen {
public:
    void display();

private:
    void process();

    Monitor monitor_;
};
```

</div>

<div class="col">

```cpp
class TouchScreen {
public:
    void display();
    void getUserInput();

private:
    void process();
    void displayKeyboard();

    Monitor monitor_;
};
```

</div>

</div>

### Jak uprościć powyższy kod?

___

## Wykorzystanie dziedziczenia do uproszczenia kodu

```cpp
class Screen {
public:
    void display();

private:
    void process();

    Monitor monitor_;
};

class TouchScreen : public Screen {
public:
    void getUserInput();

private:
    void displayKeyboard();
};
```

___

## Wielodziedziczenie #1

```cpp
class Screen {
public:
    void display();

private:
    void process();

    Monitor monitor_;
};

class TouchScreen : public Screen {
public:
    void getUserInput();

private:
    void displayKeyboard();
};

class Computer {
public:
    void turnOn();
    void powerOff();
    void restart();

protected:
    Processor processor_;
    Drive drive_;
    Motherboard motherboard_;
    GraphicsCard graphics_card_;
    Memory memory_;
};

class Laptop : public Computer,
               public Screen {
    Keyboard keyboard_;
};

class Tablet : public Computer,
               public TouchScreen {
};
```

___

## Wielodziedziczenie #2

Wybór implementacji zależy od programisty. Nie zawsze wielodziedziczenie będzie lepszym rozwiązaniem. Należy się zawsze zastanowić czy dziedziczenie po konkretnej klasie uprości nam program i czy nie będzie powodować żadnych komplikacji w dalszym procesie rozbudowy naszego programu.

___

## Wielodziedziczenie - problemy #1

```cpp
struct Bird {
    fly();
    makeSound();
};

struct Penguin {
    swim();
    makeSound();
};

// Hummingbird is the type of bird which makes so little sound so it
// can be said that it makes no sound.
struct Hummingbird {
    fly();
};
```

___
<!-- .slide: style="font-size: 0.9em" -->

## Wielodziedziczenie - problemy #2

Jeżeli spróbujemy teraz uprościć klasę poprzez dziedziczenie pojawi się problem:

```cpp
struct Bird {
    fly();
    makeSound();
};

struct Penguin : public Bird {
    fly();  // But I can't fly!
    swim();
    makeSound();
};

struct Hummingbird : public Bird {
    fly();
    makeSound();  // But I don't make sound!
};
```

Jeszcze bardziej utrudnimy sytuacje, gdy w przyszłości dodamy sobie kolejne klasy jak Struś. Zawsze przed implementacją musimy się zastanowić jak podzielić odpowiedzialność na poszczególne klasy, aby
uniknąć podobnych problemów.

___

## Metody czysto wirtualne

```cpp
class Bird {
public:
    size_t getWeight();
    size_t getHeight();
    size_t getName();

    // Pure virtual function without implementation
    virtual void eat() = 0;
    virtual void sleep() = 0;

protected:
    size_t weight_;
    size_t height_;
    std::string name_;
};
```

Metody `eat()` oraz `sleep()` to tzw. metody czysto wirtualne. Świadczy o tym `= 0;`. Oznacza to, że nigdzie nie znajdziemy ich implementacji dla klasy `Bird`. Klasy które dziedziczą po `Bird` będą ją musiały zaimplementować same.

___
<!-- .slide: style="font-size: 0.9em" -->

## Interfejsy

Jednym z pomysłów na rozwiązanie problemu wielodziedziczenia jest tworzenie tzw. interfejsów, ich dziedziczenie oraz przeciążanie implementacji metod z klas bazowych. Interfejsy określają "umiejętności" i łatwo je ze sobą łączyć.

```cpp
class Flyable {
public:
    virtual void fly() = 0;

private:
    Wings wings_;
};

class Swimmable {
public:
    virtual void swim() = 0;
};

class Soundable {
public:
    virtual void makeSound() = 0;
};
```

___

## Użycie interfejsów

```cpp
class Penguin : public Bird, public Swimmable {
public:
    // Override from Bird
    void eat() override;
    void sleep() override;

    // Override from Swimmable
    void swim() override;
};

class Hummingbird : public Bird,
                    public Flyable,
                    public Soundable {
public:
    // Override from Bird
    void eat() override;
    void sleep() override;

    // Override from Soundable
    void makeSound() override;

    // Override from Flyable
    void fly() override;
};

class Goose : public Bird,
              public Flyable,
              public Soundable,
              public Swimmable {
public:
    // Override from Bird
    void eat() override;
    void sleep() override;

    // Override from Soundable
    void makeSound() override;

    // Override from Flyable
    void fly() override;

    // Override from Swimmable
    void swim() override;
};
```

___

## Klasa abstrakcyjna

Nie można utworzyć obiektu klasy, która posiada <span class="fragment highlight-green">**co najmniej jedną czysto wirtualną**</span>.

Możemy przechowywać wskaźnik wskazujący na typ tej klasy, ale nie możemy stworzyć jej instancji, ponieważ nie mamy zdefiniowanych jej zachowań.

Klasa taka nazywa się  <span class="fragment highlight-green">**klasą abstrakcyjną**</span> i służy tylko do ujednolicania interfejsu, a nie tworzenia obiektów.

Dopiero obiekt klasy pochodnej, która zaimplementuje wszystkie brakujące metody, może zostać utworzona.

___

## Słowo `virtual` i `override`

Co to za słowa? Co one robią? O tym w kolejnej lekcji ;)

Zostawiamy was z tym niedopowiedzeniem, abyście sami zechcieli poszukać o tym informacji lub przejrzeli wideo pana Zelenta.

___

Jeżeli chcemy, aby jakaś metoda była wirtualna, lub można ją było przeciążyć, należy poinformować kompilator słowem `virtual`.

<!-- TODO: Co to znaczy wirtualna? -->

Jeżeli w klasie pochodnej przeciążamy taką metodę, należy dodać słowo `override`.

```cpp
class Interface {
public:
    virtual void doSth() = 0;
};

class SomeClass : public Interface {
public:
    doSth() override;
};

int main() {
    Interface interface;    // Compilation error, class Interface is pure virtual
    SomeClass someClass;    // OK
    Interface* interface = &someClass;  // OK, we hold a pointer
}
```

___

## Polimorfizm

Wracając do przykładu o ptakach, klasy `Penguin`, `Hummingbird` oraz `Goose` to klasy pochodne, które dziedziczą po pewnych klasach bazowych jak `Bird`, `Flyable`, `Soundable`, `Swimmable` oraz przeciążają kilka ich metod jak:

* `void eat() override`
* `void sleep() override`
* `void makeSound() override`
* `void fly() override`
* `void swim() override`
  
Przeciążanie takich metod powoduje, że możemy zmienić nieco implementacje konkretnych metod:

```cpp
class Soundable {
public:
    virtual void makeSound() = 0;
};
```

```cpp
class Goose : public Soundable {
public:
    // Override from Soundable
    void makeSound() override { std::cout << "Honk! Honk!"; }
};
```

```cpp
class Hen : public Soundable {
public:
    // Override from Soundable
    void makeSound() override { std::cout << "Cluck! Cluck!"; }
};
```

```cpp
class Duck : public Soundable {
public:
    // Override from Soundable
    void makeSound() override { std::cout << "Quack! Quack!"; }
};
```

Ponieważ wspólnym rodzicem wszystkich klas jest klasa `Soundable` możemy przechowywać w kontenerze wskaźniki typu `Soundable`.
`std::vector<std::shared_ptr<Soundable>> birds_;`

### Jakie dane otrzymamy na wyjściu?

```cpp
std::vector<std::shared_ptr<Soundable>> birds_;
birds_.push_back(std::make_shared<Goose>());
birds_.push_back(std::make_shared<Hen>());
birds_.push_back(std::make_shared<Duck>());

std::cout << birds_[0]->MakeSound() << '\n';
std::cout << birds_[1]->MakeSound() << '\n';
std::cout << birds_[2]->MakeSound() << '\n';
```

Zjawisko, które właśnie obserwowaliśmy, nazywa się polimorfizmem.
Polimorfizm pozwala funkcji przybrać różne formy jak na przykładzie.
Dlatego, jeżeli utworzymy kolejno obiekty `Goose`, `Hen` i `Duck` w zależności
od obiektu zostanie wywołana jego wersja metody `MakeSound`.

### Kto grał lub czytał Wiedźmina?

W uniwersum wykreowanym przez naszego rodzimego pisarza Andrzeja Sapkowskiego, występuje pewna
intrygująca i ciekawa rasa zwana Dopplerami. Rasa ta potrafi przyjąć, postać różnych form życia,
może stać się człowiekiem, elfem, krasnoludem. Zmienia w ten sposób swoje cechy jak głos, kolor włosów, a nawet ubranie!
Pomimo że rasa ta jest typu Doppler, potrafi w różnych okolicznościach podszywać się pod inne rasy jak elf, krasnolud czy człowiek.
Z punktu widzenia C++ nasz Doppler podlega zjawisku polimorfizmu.

```cpp
class Doppler {
public:
    virtual SayHallo() {
        std::cout << "I'm Doppler!";
    }
};

class Dwarf : public Doppler {
    virtual SayHallo() {
        std::cout << "I'm Dwarf!";
    }
};

class Elf : public Doppler {
    virtual SayHallo() {
        std::cout << "I'm Elf!";
    }
};

class Human : public Doppler {
    virtual SayHallo() {
        std::cout << "I'm Human!";
    }
};

int main() {
    std::shared_ptr<Doppler> doppler1 = std::make_shared<Dwarf>();
    std::shared_ptr<Doppler> doppler2 = std::make_shared<Elf>();
    std::shared_ptr<Doppler> doppler3 = std::make_shared<Human>();

    std::cout << doppler1->SayHallo() << '\n';
    std::cout << doppler2->SayHallo() << '\n';
    std::cout << doppler3->SayHallo() << '\n';
}
```

<!-- TODO: Pokazać, że bez słowa virtual też kod się skompiluje, ale zachowa się inaczej -->

Jak widzimy, nasz Doppler może przyjąć różne formy i zachowywać się tak jak one. Pomimo że wskaźnik jest typu Doppler.
Program dobrze wie, kiedy Doppler podszywa się pod człowieka, kiedy pod krasnoluda, a kiedy pod elfa.

Bardzo ważne w przypadku tworzenia metod wirtualnych i dziedziczenia jest tworzenie wirtualnych destruktorów.
Jeżeli korzystamy z dobroci polimorfizmu i nie oznaczymy destruktor jako `virtual` lub w klasach pochodnych jako `override`, to destruktor ten nie zostanie wywołany.

```cpp
#include <iostream>
#include <string>

class Parent {
public:
    Parent() { std::cout << "PARENT C'tor called\n"; }
    ~Parent() { std::cout << "PARENT D'tor caller\n"; }
};

class Child : public Parent {
public:
    Child() { std::cout << "CHILD C'tor called\n"; }
    ~Child() { std::cout << "CHILD D'tor caller\n"; }
};

int main() {
    Child child;
}
```

```cpp
#include <iostream>
#include <memory>
#include <string>

class Parent {
public:
    Parent() { std::cout << "PARENT C'tor called\n"; }
    ~Parent() { std::cout << "PARENT D'tor caller\n"; }
};

class Child : public Parent {
public:
    Child() { std::cout << "CHILD C'tor called\n"; }
    ~Child() { std::cout << "CHILD D'tor caller\n"; }
};

int main() {
    // Problem
    std::unique_ptr<Parent> child2 = std::make_unique<Child>();

    // But shared_ptr will clenup propelry
    std::shared_ptr<Parent> child2 = std::make_shared<Child>();
}
```

```cpp
#include <iostream>
#include <memory>
#include <string>

class Parent {
public:
    Parent() { std::cout << "PARENT C'tor called\n"; }
    virtual ~Parent() { std::cout << "PARENT D'tor caller\n"; }
};

class Child : public Parent {
public:
    Child() { std::cout << "CHILD C'tor called\n"; }
    ~Child() override { std::cout << "CHILD D'tor caller\n"; }
};

int main() {
    std::unique_ptr<Parent> child2 = std::make_unique<Child>();
}
```

___

## Zmienne i funkcje statyczne

Czasami chcielibyśmy przypisać jakąś stałą cechę do klasy. Nie konkretnych obiektów, a klasy samej w sobie. Np. Każdy obiekt klasy ma nazwę "Obiekt".

```cpp
class Object {
public:
    std::string GetName() const { return name_; }

private:
    const std::string name_ = "Object";
};
```

W celu otrzymania nazwy tego obiektu, musimy najpierw utworzyć obiekt, a następnie zawołać `getName()`.

```cpp
int main() {
    Object obj;
    std::cout << obj.getName() << '\n';
}
```

Nawet jeżeli obiekt zajmowałby dużo miejsca w pamięci a my chcielibyśmy tylko jego nazwę i tak musimy go utworzyć, ponieważ tylko na nim możemy zawołać metodę `getName()`.

Rozwiązaniem tej uciążliwości jest `static`. Co więcej, problem ten możemy rozwiązać na 2 sposoby:

```cpp
class Object {
public:
    static std::string getName() { return "Object"; }
};

class Object2 {
public:
    static std::string name_;
};

std::string Object2::name_{"Object2"};

int main() {
    std::cout << Object::getName() << '\n';
    std::cout << Object2::name_ << '\n';

    return 0;
}
```

Nie musimy w ten sposób tworzyć specjalnie obiektu, aby dostać się do cechy klasy, jaką jest jej nazwa.

<!-- TODO: Brakuje tu motywacji na jakimś konkretnym przykładzie -->

___

## Q&A
