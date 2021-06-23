<!-- .slide: data-background="#111111" -->

# Programowanie obiektowe

## Dziedziczenie

<a href="https://coders.school">
    <img width="500" src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Wprowadzenie do dziedziczenia

Podczas implementacji klas, często możemy zauważyć, że część cech składowych klasy można wykorzystać także w innych klasach.
<!-- .element: class="fragment fade-in" -->

Weźmy pod lupę klasę `Computer`. Jeżeli chcielibyśmy utworzyć klasy: `Laptop`, `PC`, `Tablet`, to część metod oraz składowych klasy musielibyśmy powielić.
<!-- .element: class="fragment fade-in" -->

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
};
```
<!-- .element: class="fragment fade-in" -->

___

## Klasy bazowe i pochodne

Klasa, po której dziedziczymy, nazywają się  <span class="fragment highlight-green">**klasą bazową (base class)**</span>.
<!-- .element: class="fragment fade-in" -->

Klasa, która dziedziczy nazywa się  <span class="fragment highlight-green">**klasą pochodną (derived class)**</span>.
<!-- .element: class="fragment fade-in" -->

Inaczej, klasa, po której dziedziczymy to rodzic (parent class).
<!-- .element: class="fragment fade-in" -->

Klasa, która dziedziczy to dziecko (child class).
<!-- .element: class="fragment fade-in" -->

___

### Co z metodami klas `Laptop` i `Tablet`?

#### Czy można wydzielić kolejną klasę?
<!-- .element: class="fragment fade-in" -->

```cpp
void display();
void getUserInput();
```
<!-- .element: class="fragment fade-in" -->

___

## Klasa `Screen` i `TouchScreen`

Załóżmy, że dodajemy klasę `Screen`. Klasa ta wyświetla na bieżąco interfejs użytkownika.
<!-- .element: class="fragment fade-in" -->

Chcemy też stworzyć klasę reprezentującą ekran dotykowy - `TouchScreen`, który również umożliwia odczyt akcji od użytkownika i ich wyświetlanie.
<!-- .element: class="fragment fade-in" -->

<div class="multicolumn">
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
<!-- .element: class="fragment fade-in" -->

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
<!-- .element: class="fragment fade-in" -->

</div>
</div>

### Jak uprościć powyższy kod?
<!-- .element: class="fragment fade-in" -->

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
```
<!-- .element: class="fragment fade-in" -->

```cpp
class TouchScreen : public Screen {
public:
    void getUserInput();

private:
    void displayKeyboard();
};
```
<!-- .element: class="fragment fade-in" -->

___

## Wielodziedziczenie

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

## Wielodziedziczenie - disclaimer

Wielodziedziczenie to dziedziczenie z kliku klas bazowych.

Wybór implementacji zależy od programisty.
<!-- .element: class="fragment fade-in" -->

Nie zawsze wielodziedziczenie będzie lepszym rozwiązaniem.
<!-- .element: class="fragment fade-in" -->

Należy się zawsze zastanowić czy dziedziczenie po konkretnej klasie uprości nam program i czy nie będzie powodować żadnych komplikacji w dalszym procesie rozbudowy naszego programu.
<!-- .element: class="fragment fade-in" -->

Najwyżej trzeba będzie refaktoryzować program ;)
<!-- .element: class="fragment fade-in" -->

___

## Dziedziczenie - problemy

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

## Dziedziczenie - zasada LSP

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

Jeszcze bardziej utrudnimy sytuację, gdy w przyszłości dodamy sobie kolejne klasy jak Struś. Zawsze przed implementacją musimy się zastanowić jak podzielić odpowiedzialność na poszczególne klasy, aby
uniknąć podobnych problemów.

___

### Dla ciekawskich

Poczytajcie o zasadzie Liskov Substitution Principle (LSP). Mówi ona jak powinno / nie powinno się projektować kodu obiektowego. Ta zasada została złamana w ostatnim przykładzie.

Możecie też poczytać o wszystkich zasadach SOLID.

___

## Q&A
