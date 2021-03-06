<!-- .slide: data-background="#111111" -->

# Programowanie obiektowe

## Konstruktory i destruktory

<a href="https://coders.school">
    <img width="500" src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Konstruktor

Konstruktor klasy jest to przepis określający jak ma wyglądać obiekt naszej klasy zaraz po utworzeniu.
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

Do inicjalizacji danych w konstruktorze możemy (a raczej powinniśmy) wykorzystać listę inicjalizacyjną.
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
};
```
<!-- .element: class="fragment fade-in" -->

___

## Inicjalizacja w ciele klasy (C++11)

Od C++11 możemy inicjalizować obiekty klasy domyślnymi wartościami w ciele klasy
<!-- .element: class="fragment fade-in" -->

```cpp
class Processor {
private:
    unsigned clock_ = 3'000'000'000u;    // 3 GHz
    size_t cores_ = 8u;
};
```
<!-- .element: class="fragment fade-in" -->

___

## Delegowanie konstruktorów (C++11)

Elementem listy inicjalizacyjnej może być nawet inny konstruktor naszej klasy.
<!-- .element: class="fragment fade-in" -->

```cpp
class Ship {
public:
    Ship(const std::string& name, size_t capacity, size_t crew)
        : name_(name)
        , capacity_(capacity)
        , crew_(crew)
    {}

    Ship(const std::string& name, size_t capacity)
        : Ship(name, capacity, 0)
    {}

private:
    std::string name_;
    const size_t capacity_;
    size_t crew_;
};
```
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.8em" -->

## Destruktor

Destruktor jest specjalną funkcją sprzątającą naszą klasę.
<!-- .element: class="fragment fade-in" -->

Musi nazywać się tak samo jak klasa, ale jej nazwa poprzedzona jest znakiem tyldy `~`.
<!-- .element: class="fragment fade-in" -->

Rzadko powinna być potrzeba pisania własnych destruktorów. Na pewno musisz o nich pamiętać, jeśli jako pól klasy używasz zwykłych wskaźników i alokujesz pamięć w konstruktorze.
<!-- .element: class="fragment fade-in" -->

Destruktor wykorzystujesz, jeżeli chcesz wywołać konkretne akcje podczas niszczenia obiektu, np. zarejestrowanie tego faktu w dzienniku itp.
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
