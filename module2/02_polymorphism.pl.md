<!-- .slide: data-background="#111111" -->

# Programowanie obiektowe

## Polimorfizm

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Słowo kluczowe `virtual`

Jeżeli chcemy, aby przy używaniu wskaźników lub referencji na klasę bazową, jakaś metoda zachowywała się inaczej w zależności od prawdziwego typu obiektu, to należy ją oznaczyć słowem kluczowym `virtual`. Jest to tzw. <span class="fragment highlight-green">funkcja wirtualna</span>.

___
<!-- .slide: style="font-size: 0.9em" -->

## Funkcja nie-wirtualna

```cpp
#include <iostream>

struct Bird {
    void sing() { std::cout << "tweet, tweet\n"; }
};

struct Sparrow : Bird {
    void sing() { std::cout << "chirp, chirp\n"; }
};

int main() {
    Sparrow sparrow;
    Bird& bird = sparrow;
    bird.sing();
    return 0;
}
```

Co pojawi się na ekranie?
<!-- .element: class="fragment fade-in" -->

`tweet, tweet`
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.9em" -->

## Funkcja wirtualna

```cpp
#include <iostream>

struct Bird {
    virtual void sing() { std::cout << "tweet, tweet\n"; }
};

struct Sparrow : Bird {
    void sing() { std::cout << "chirp, chirp\n"; }
};

int main() {
    Sparrow sparrow;
    Bird& bird = sparrow;
    bird.sing();
    return 0;
}
```

Co pojawi się na ekranie?
<!-- .element: class="fragment fade-in" -->

`chirp, chirp`
<!-- .element: class="fragment fade-in" -->

[Sprawdź na ideone.com](https://ideone.com/yW43Tq)
<!-- .element: class="fragment fade-in" -->

___

## Słowo kluczowe `override`

Jeżeli w klasie pochodnej **nadpisujemy** metodę wirtualną, czyli zmieniamy jej zachowanie, to należy dodać słowo `override`.
<!-- .element: class="fragment fade-in" -->

```cpp
class Interface {
public:
    virtual void doSth() = 0;
};

class SomeClass : public Interface {
public:
    void doSth() override;   // there should be an implementation in cpp file
};

int main() {
    // Interface interface;    // Compilation error, Interface is pure virtual
    SomeClass someClass;    // OK
    Interface* interface = &someClass;  // OK, we hold a pointer
}
```
<!-- .element: class="fragment fade-in" -->

___

### Mała uwaga

`override` jest opcjonalne. Jeśli go nie podamy za sygnaturą funkcji klasy pochodnej to metoda z klasy bazowej i tak zostanie nadpisana.
<!-- .element: class="fragment fade-in" -->

Jego użycie jest jednak dobrą praktyką, bo dzięki niemu kompilator sprawdzi czy faktycznie nadpisujemy metodę z klasy bazowej i jeśli nie, to program się nie skompiluje.
<!-- .element: class="fragment fade-in" -->

Bez `override` mogłaby zostać utworzona nowa metoda w klasie pochodnej, która nie nadpisuje niczego z klasy bazowej.
<!-- .element: class="fragment fade-in" -->

Metody wirtualne **nadpisujemy**, nie przeciążamy.
<!-- .element: class="fragment fade-in" -->

___

## Nadpisywanie metod - `override`

Wracając do przykładu o ptakach, klasy `Penguin`, `Hummingbird` oraz `Goose` to klasy pochodne, które dziedziczą po pewnych klasach bazowych jak `Bird`, `Flyable`, `Soundable`, `Swimmable` oraz nadpisują kilka ich metod jak:

* <!-- .element: class="fragment fade-in" --> <code>void eat() override</code>
* <!-- .element: class="fragment fade-in" --> <code>void sleep() override</code>
* <!-- .element: class="fragment fade-in" --> <code>void makeSound() override</code>
* <!-- .element: class="fragment fade-in" --> <code>void fly() override</code>
* <!-- .element: class="fragment fade-in" --> <code>void swim() override</code>

Nadpisanie takich metod powoduje, że możemy zmienić ich implementacje.
<!-- .element: class="fragment fade-in" -->

___

## `override`

```cpp
class Soundable {
public:
    virtual void makeSound() = 0;
};
```

```cpp
class Goose : public Soundable {
public:
    void makeSound() override { std::cout << "Honk! Honk!"; }
};
```

```cpp
class Hen : public Soundable {
public:
    void makeSound() override { std::cout << "Cluck! Cluck!"; }
};
```

```cpp
class Duck : public Soundable {
public:
    void makeSound() override { std::cout << "Quack! Quack!"; }
};
```

___

## Wspólna klasa bazowa

Ponieważ wspólnym rodzicem wszystkich klas jest klasa `Soundable` możemy przechowywać w kontenerze wskaźniki typu `Soundable`.

```cpp
std::vector<std::shared_ptr<Soundable>> birds_;
```

### Jakie dane otrzymamy na wyjściu? <!-- .element: class="fragment fade-in" -->

```cpp
std::vector<std::shared_ptr<Soundable>> birds_;
birds_.push_back(std::make_shared<Goose>());
birds_.push_back(std::make_shared<Hen>());
birds_.push_back(std::make_shared<Duck>());

std::cout << birds_[0]->makeSound() << '\n';
std::cout << birds_[1]->makeSound() << '\n';
std::cout << birds_[2]->makeSound() << '\n';
```
<!-- .element: class="fragment fade-in" -->

___

## Polimorfizm

Zjawisko, które właśnie zaobserwowaliśmy, nazywa się polimorfizmem.

Polimorfizm pozwala funkcji przybrać różne formy (implementacje), tak jak na przykładzie.
<!-- .element: class="fragment fade-in" -->

Dlatego, jeżeli utworzymy kolejno obiekty `Goose`, `Hen` i `Duck` w zależności od obiektu zostanie wywołana jego wersja metody `makeSound`.
<!-- .element: class="fragment fade-in" -->

Polimorfizm włącza się, gdy mamy funkcje wirtualne i używamy wskaźników lub referencji na typ bazowy.
<!-- .element: class="fragment fade-in" -->

### Kto grał lub czytał Wiedźmina?
<!-- .element: class="fragment fade-in" -->

___

## Doppler 🙂

W uniwersum wykreowanym przez naszego rodzimego pisarza Andrzeja Sapkowskiego, występuje pewna intrygująca i ciekawa rasa zwana Dopplerami.
<!-- .element: class="fragment fade-in" -->

Rasa ta potrafi przyjąć, postać różnych form życia, może stać się człowiekiem, elfem, krasnoludem. Zmienia w ten sposób swoje cechy jak głos, kolor włosów, a nawet ubranie!
<!-- .element: class="fragment fade-in" -->

Pomimo że rasa ta jest typu Doppler, potrafi w różnych okolicznościach podszywać się pod inne rasy jak elf, krasnolud czy człowiek.
<!-- .element: class="fragment fade-in" -->

Z punktu widzenia C++ nasz Doppler podlega zjawisku polimorfizmu.
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.85em" -->

```cpp
class Doppler {
public:
    virtual sayHello() { std::cout << "I'm Doppler!"; }
};

class Dwarf : public Doppler {
public:
    virtual sayHello() { std::cout << "I'm Dwarf!"; }
};

class Elf : public Doppler {
public:
    virtual sayHello() { std::cout << "I'm Elf!"; }
};

class Human : public Doppler {
public:
    virtual sayHello() { std::cout << "I'm Human!"; }
};

int main() {
    std::shared_ptr<Doppler> doppler1 = std::make_shared<Dwarf>();
    std::shared_ptr<Doppler> doppler2 = std::make_shared<Elf>();
    std::shared_ptr<Doppler> doppler3 = std::make_shared<Human>();

    std::cout << doppler1->sayHello() << '\n';
    std::cout << doppler2->sayHello() << '\n';
    std::cout << doppler3->sayHello() << '\n';
}
```

<!-- TODO: Pokazać, że bez słowa virtual też kod się skompiluje, ale zachowa się inaczej -->

Jak widzimy, nasz Doppler może przyjąć różne formy i zachowywać się tak jak one. Wskaźnik jest typu Doppler, ale program dobrze wie, kiedy Doppler podszywa się pod człowieka, kiedy pod krasnoluda, a kiedy pod elfa.

___
<!-- .slide: style="font-size: 0.9em" -->

## Nie-wirtualne destruktory

Bardzo ważne w przypadku tworzenia metod wirtualnych i dziedziczenia jest tworzenie wirtualnych destruktorów.
Jeżeli korzystamy z dobroci polimorfizmu i nie oznaczymy destruktor jako `virtual` to destruktor ten nie zostanie wywołany.

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
    Child child;    // ok, object on stack, not a pointer
}
```

___

## Nie-wirtualne destruktory - problem

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
    std::unique_ptr<Parent> child = std::make_unique<Child>();

    // But shared_ptr will cleanup properly
    std::shared_ptr<Parent> child2 = std::make_shared<Child>();
}
```

___

## Wirtualny destruktor

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

## Q&A

___

## Zadanie 3

Napisz klasę `DryFruit`, która dziedziczyć będzie po klasie `Fruit`.

Klasa ta powinna nadpisywać metody `getPrice()`, `getName()` oraz `operator--`.

`operator--` powinien odejmować zużycie raz na 10 wywołań.

Metoda `getPrice()` powinna zwracać trzykrotnie większą wartość w porównaniu do ceny bazowej.

Przetestuj wywołania polimorficzne oraz podziel się wnioskami.
