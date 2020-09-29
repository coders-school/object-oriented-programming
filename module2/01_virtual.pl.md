<!-- .slide: data-background="#111111" -->

# Programowanie obiektowe

## Metody wirtualne, interfejsy, klasy abstrakcyjne

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___
<!-- .slide: style="font-size: 0.9em" -->

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
<!-- .element: class="fragment fade-in" -->

Metody `eat()` oraz `sleep()` to tzw. metody czysto wirtualne. Świadczy o tym `= 0;`. Oznacza to, że nigdzie nie znajdziemy ich implementacji dla klasy `Bird`. Klasy które dziedziczą po `Bird` będą ją musiały zaimplementować same.
<!-- .element: class="fragment fade-in" -->

Znaczenie słowa `virtual` na razie przemilczymy. Jedyne co trzeba na teraz wiedzieć, to aby metoda była czysto wirtualna `= 0;` to musi być przed nią słowo `virtual`.
<!-- .element: class="fragment fade-in" -->

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
<!-- .element: class="fragment fade-in" -->

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

## Co to jest interfejs?

Interfejs to zestaw funkcji, które klasa implementująca go musi zaimplementować (masło maślane).
<!-- .element: class="fragment fade-in" -->

Interfejs to zestaw funkcji, które klasa dziedzicząca po nim musi zaimplementować.
<!-- .element: class="fragment fade-in" -->

Brak implementacji funkcji czysto wirtualnej to błąd linkera (undefined reference).
<!-- .element: class="fragment fade-in" -->

### Definicja interfejsu
<!-- .element: class="fragment fade-in" -->

W pełni poprawna definicja interfejsu to część publiczna klasy / zestawu funkcjonalności. Mogą to być zarówno metody, pola, typy, ale najczęściej będziemy słowa interfejs używać w odniesieniu do publicznych metod klasy.
<!-- .element: class="fragment fade-in" -->

[Zobacz interfejs wektora na cppreference.com](https://en.cppreference.com/w/cpp/container/vector)
<!-- .element: class="fragment fade-in" -->

Znajdziesz tam opis jego publicznych metod (member functions), typów wewnętrznych (member types) oraz luźnych funkcji, które go wykorzystują (non-member functions).
<!-- .element: class="fragment fade-in" -->

___

## Klasa abstrakcyjna

Nie można utworzyć obiektu klasy, która posiada <span class="fragment highlight-green">**co najmniej jedną funkcję czysto wirtualną**</span>.
<!-- .element: class="fragment fade-in" -->

Funkcja czysto wirtualna nie ma implementacji, więc nie może istnieć obiekt, dla którego linker nie znajdzie implementacji jednej z jego funkcji.
<!-- .element: class="fragment fade-in" -->

Możemy przechowywać wskaźnik wskazujący na typ tej klasy, ale nie możemy stworzyć jej instancji (obiektu), ponieważ nie mamy zdefiniowanych jej zachowań.
<!-- .element: class="fragment fade-in" -->

Klasa taka nazywa się  <span class="fragment highlight-green">**klasą abstrakcyjną**</span> i służy tylko do ujednolicania interfejsu, a nie tworzenia obiektów.
<!-- .element: class="fragment fade-in" -->

Dopiero obiekt klasy pochodnej, która zaimplementuje wszystkie brakujące metody, może zostać utworzony.
<!-- .element: class="fragment fade-in" -->

___

## Słowo `virtual` i `override`

Co to za słowa? Co one robią? O tym za chwilę 🙂
<!-- .element: class="fragment fade-in" -->

___

## Q&A

___

## Zadanie 1

Przekształć klasę `Cargo` w interfejs z 4 czysto wirtualnymi metodami.

```cpp
virtual size_t getPrice() const = 0;
virtual std::string getName() const = 0;
virtual size_t getAmount() const = 0;
virtual size_t getBasePrice() const = 0;
```

___

## Zadanie 1 cd.

Utwórz 3 pochodne klasy `Cargo`:

* `Fruit`
* `Alcohol`
* `Item`

Klasa `Fruit` powinna mieć dodatkową zmienną określającą czas do zepsucia oraz `operator--` który będzie odejmował ten czas o 1.
Metoda `getPrice()` powinna redukować cenę odpowiednio wraz z czasem psucia naszego owocu.

Klasa `Alcohol` powinna mieć dodatkową zmienną określającą procentowy udział spirytusu.
Metoda `getPrice()` powinna być proporcjonalnie wyższa w zależności od mocy alkoholu.
Należy ustalić bazową cenę za spirytus 96%.

Klasa `Item` powinna mieć dodatkową zmienną enum określającą rzadkość przedmiotu (common, rare, epic, legendary).
Metoda `getPrice()` powinna być adekwatnie wyliczana od poziomu rzadkości przedmiotu.

___

## Zadanie 2

Wykorzystując wspólną klasę bazową `Cargo` spróbuj przechowywać wszystkie towary w jednym wektorze w klasie `Ship`.

Dodaj funkcję `void load(std::shared_ptr<Cargo> cargo)`, która dodaje towar i (dla chętnych) `void unload(Cargo* cargo)`, która usuwa towar z obiektu klasy `Ship`.
