<!-- .slide: data-background="#111111" -->

# Programowanie obiektowe

## Dziedziczenie

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

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

## Q&A
