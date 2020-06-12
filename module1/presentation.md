<!-- .slide: data-background="#111111" -->

# Programowanie obiektowe

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## SHM — Symulator Handlu Morskiego

<img height="500" data-src="img/statek.png" alt="Statek" class="plain">

___
<!-- .slide: data-background="#eeeeee" -->

## SHM - Diagram UML

<a href="../shm-uml.svg">
    <img height="500" data-src="../shm-uml.svg" alt="Diagram klas - SHM" class="plain">
</a>
___

## Wprowadzenie do programowania obiektowego

___

### Czym jest obiekt?

Obiekt w C++ niczym się nie różni od rzeczywistego obiektu. Obiekt to "konkretny" obiekt. Możemy mieć wiele identycznych obiektów. Niektórym dla rozróżnienia możemy nadać nazwy. W C++ możemy mieć obiekty takie jak:

* <!-- .element: class="fragment fade-in" --> komputer HP, komputer Lenovo, komputer MacBook
* <!-- .element: class="fragment fade-in" --> drukarka HP, drukarka Epson
* <!-- .element: class="fragment fade-in" --> ołówek Stabilo Schwan 306 HB = 2 1/2
* <!-- .element: class="fragment fade-in" --> kalkulator Casio
* <!-- .element: class="fragment fade-in" --> ...

Obiekt istnieje w pamięci komputera podczas wykonywania programu. Możemy mieć wiele obiektów tego samego typu.
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> Typ: <code>Pies</code>
* <!-- .element: class="fragment fade-in" --> Obiekty typu <code>Pies</code>: <code>Azor</code>, <code>Burek</code>, <code>Decybel</code>, ...

___

### Czym jest klasa?

Klasa to typ.

Klasa w C++ nieco różni się od rzeczywistej klasy :) W C++ (czy też programowaniu obiektowym ogólnie) klasa określa cechy obiektu:
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> jakie właściwości będzie miał ten obiekt (pola)
* <!-- .element: class="fragment fade-in" --> jakie będzie miał metody działania (metody, funkcje)

___

### Pytania

* <!-- .element: class="fragment fade-in" --> jakie właściwości mógłby mieć obiekt komputer?
* <!-- .element: class="fragment fade-in" --> jakie metody mógłby mieć komputer?

```cpp
class Computer {
    // fields (pola, właściwości)
    Processor processor_;
    Drive drive_;
    Motherboard motherboard_;
    GraphicsCard graphics_card_;
    Memory memory_;

    // methods (metody)
    void run();
    void restart();
    void shutdown();
};
```
<!-- .element: class="fragment fade-in" -->

___

## Kompozycja, agregacja

Nic nie stoi na przeszkodzie, by jeden obiekt składał się z innych obiektów. W ten sposób sprawiamy, że struktura naszego kodu staje się bardziej zrozumiała.

Zawieranie się jednego obiektu w drugim nazywa się kompozycją lub agregacją. Nie są to synonimy, są to dwa trochę inne typy zawierania obiektów, ale obecnie to nie jest istotne. Dla przykładu z komputerem:
<!-- .element: class="fragment fade-in" -->

```cpp
class Computer {
    Processor processor_;
    Drive drive_;
    Motherboard motherboard_;
    GraphicsCard graphics_card_;
    Memory memory_;
    // ...
};
```
<!-- .element: class="fragment fade-in" -->

Komputer składa się (jest skomponowany) z procesora, napędu, płyty głównej, karty graficznej, pamięci.
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: data-background="#eeeeee" -->

## Diagram klas - kompozycja, agregacja

<img height="250" data-src="img/composition_aggregation.png" alt="Statek" class="plain">

* <!-- .element: class="fragment fade-in" --> Kompozycja: Samochód (Car) zawiera dokładnie 1 Gaźnik (Carburetor). Gaźnik jest częścią dokładnie jednego samochodu. Bez samochodu gaźnik nic nie robi, nie może więc działać bez niego.
* <!-- .element: class="fragment fade-in" --> Agregacja: Staw (Pond) może zawierać dowolną liczbę (0..*) Kaczek (Duck). Kaczka może być w danej chwili tylko w jednym stawie lub w żadnych (0..1). Kaczka może żyć poza stawem.

[Diagram klas - wikipedia](https://en.wikipedia.org/wiki/Class_diagram)
<!-- .element: class="fragment fade-in" -->

___

## `class` vs `struct`

Do reprezentacji typów poza klasami (`class`) mamy jeszcze struktury (`struct`).
<!-- .element: class="fragment fade-in" -->

Podstawowa różnica polega na tym, że wszystkie elementy struktury - jej metody i zmienne są domyślnie publiczne. Natomiast w klasie są domyślnie prywatne.
<!-- .element: class="fragment fade-in" -->

Słowo `private` oznacza, że tylko wewnątrz klasy mamy dostęp do tych pól. Nie możemy się do nich odwoływać poza tą klasą. Słowo `public` oznacza, że mamy dostęp z zewnątrz do danych.
<!-- .element: class="fragment fade-in" -->

___

## Modyfikatory dostępu

### `private` vs `public`

```cpp
class Computer {
private:
    void restart();
};

Computer computer;
computer.restart(); // Forbidden, restart is a private member
```
<!-- .element: class="fragment fade-in" -->

```cpp
class Computer {
public:
    void restart();
};

Computer computer;
computer.restart(); // Ok
```
<!-- .element: class="fragment fade-in" -->

___

## Modyfikator dostępu `protected`

Istnieje jeszcze jeden modyfikator dostępu w C++ - `protected`.

O nim opowiemy sobie, gdy już wyjaśnimy czym jest dziedziczenie.

___

## Konstruktor

Konstruktor klasy jest to przepis określający jak ma wyglądać nasza klasa w chwili stworzenia.
<!-- .element: class="fragment fade-in" -->

Jest to specjalna funkcja, która nazywa się tak samo jak klasa.
<!-- .element: class="fragment fade-in" -->

Do konstruktora możemy podać wszelkie potrzebne dla nas informacje, np. rozmiar tablicy, datę zakupu etc.
<!-- .element: class="fragment fade-in" -->

```cpp
class Ship {
public:
    Ship(const std::string& name, size_t capacity);  // constructor, c-tor

private:
    std::string name_;
    const size_t capacity_;
};
```
<!-- .element: class="fragment fade-in" -->

___

## Konstruktory

Klasa może posiadać wiele konstruktorów. Muszą się od siebie różnić listą parametrów, bo są to przeciążenia funkcji.
<!-- .element: class="fragment fade-in" -->

Klasa może mieć m.in. konstruktor bezargumentowy (domyślny) np. `Ship()`, który jest generowany automatycznie, jeżeli nie ma ona zdefiniowanego żadnego innego konstruktora.
<!-- .element: class="fragment fade-in" -->

```cpp
class Ship {
    // default c-tor Ship() is generated automatically, no need to write it
    std::string name_;
    const size_t capacity_;
};
```
<!-- .element: class="fragment fade-in" -->

___

## Lista inicjalizacyjna konstruktora

Do inicjalizacji danych w konstruktorze możemy wykorzystać listę inicjalizacyjną.
<!-- .element: class="fragment fade-in" -->

Listę inicjalizacyjną pisze się za sygnaturą konstruktora po dwukropku.
<!-- .element: class="fragment fade-in" -->

```cpp
class Processor {
public:
    Processor(unsigned clock, size_t cores)
        : clock_(clock), cores_(cores)  // init-list
    {}

    // the effect of above constructor is the same as below
    // Processor(unsigned clock, size_t cores) {
    //     clock_ = clock;
    //     cores_ = cores;
    // }

private:
    unsigned clock_;
    size_t cores_;
}
```
<!-- .element: class="fragment fade-in" -->

___

## Delegowanie konstruktorów

Elementem listy inicjalizacyjnej może być nawet inny konstruktor naszej klasy.
<!-- .element: class="fragment fade-in" -->

```cpp
class Ship {
public:
    Ship(const std::string& name, size_t capacity, size_t crew):
        name_(name), capacity_(capacity), crew_(crew)
    {}

    Ship(const std::string& name, size_t capacity):
        Ship(name, capacity, 0)
    {}

private:
    std::string name_;
    const size_t capacity_;
    size_t crew_;
};
```
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.9em" -->

## Destruktor

Destruktor jest specjalną funkcją sprzątającą naszą klasę.
<!-- .element: class="fragment fade-in" -->

Musi nazywać się tak samo jak klasa, ale jej nazwa poprzedzona jest znakiem tyldy `~`.
<!-- .element: class="fragment fade-in" -->

Możemy ją wykorzystać, jeżeli chcemy wywołać konkretne akcje podczas niszczenia obiektu, np. zarejestrowanie tego faktu w dzienniku itp.
<!-- .element: class="fragment fade-in" -->

```cpp
class Ship {
public:
    Ship(const std::string& name, size_t capacity, size_t crew):
        name_(name), capacity_(capacity), crew_(crew)
    {}

    ~Ship() {   // d-tor, destruktor
        std::cout << "Ship destroyed\n";
    }

private:
    std::string name_;
    const size_t capacity_;
    size_t crew_;
};
```
<!-- .element: class="fragment fade-in" -->

___

## Hermetyzacja

Aby zabezpieczyć nasz obiekt, przez niepożądanymi modyfikacjami, możemy dokonać, tzw. hermetyzacji lub enkapsulacji.
<!-- .element: class="fragment fade-in" -->

Polega ona na umieszczeniu wszystkich właściwości (pól) w sekcji prywatnej, a ich modyfikacje umożliwiać przez publiczne funkcje.
<!-- .element: class="fragment fade-in" -->

___

## settery i gettery

Najprostszymi funkcjami umożliwiającymi modyfikacje są tzw. settery.
<!-- .element: class="fragment fade-in" -->

Setter to funkcja, która przypisuje daną wartość konkretnej zmiennej.
<!-- .element: class="fragment fade-in" -->

```cpp
void setName(const std::string& name) { name_ = name; }
```
<!-- .element: class="fragment fade-in" -->

Ponieważ dane są prywatne, ich odczyt również nie jest możliwy, więc dokonujemy go przez tzw. gettery.
<!-- .element: class="fragment fade-in" -->

```cpp
std::string getName() const { return name_ }
```
<!-- .element: class="fragment fade-in" -->

Oczywiście nie zawsze musimy umożliwiać modyfikacje wszystkich zmiennych, tak samo, jak nie wszystkie zmienne mogą mieć swoje gettery. Wybór zależy od programisty.
<!-- .element: class="fragment fade-in" -->

___

## Q&A
