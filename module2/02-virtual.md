<!-- .slide: data-background="#111111" -->

# Programowanie obiektowe

## Metody czysto wirtualne, interfejsy, klasy abstrakcyjne

<a href="https://coders.school">
    <img width="500" src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___
<!-- .slide: style="font-size: 0.9em" -->

## Metody czysto wirtualne

```cpp
class Bird {
public:
    size_t getWeight() const    { return weight_; }
    size_t getHeight() const    { return height_; }
    std::string getName() const { return name_; }

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

Metody `eat()` oraz `sleep()` to tzw. metody czysto wirtualne (ang. pure virtual functions). Świadczy o tym `= 0;`. Oznacza to, że nigdzie nie znajdziemy ich implementacji dla klasy `Bird`. Klasy które dziedziczą po `Bird` będą ją musiały zaimplementować same.
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
class Penguin : public Bird,
                public Swimmable,
                public Soundable {
public:
    // Override from Bird
    void eat() override;
    void sleep() override;

    // Override from Swimmable
    void swim() override;

    // Override from Soundable
    void makeSound() override;
};

class Hummingbird : public Bird,
                    public Flyable {
public:
    // Override from Bird
    void eat() override;
    void sleep() override;

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

Co to za słowa? Co one robią? O tym w jednym z następnych wideo ;)
<!-- .element: class="fragment fade-in" -->
