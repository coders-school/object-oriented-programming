<!-- .slide: data-background="#111111" -->

# Object oriented programming

## Inheritance

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Introduction to Inheritance

When implementing classes, we can often notice that some of the class's component features can also be used in other classes.
<!-- .element: class="fragment fade-in" -->

Let's take a closer look at the class `Computer`. If we would like to create classes: `Laptop`, `PC`, `Tablet`, we would have to duplicate some of the methods and class members.
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

## How to simplify the structure of our program?

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

## Base classes and derived classes

The class from which we inherit is called  <span class="fragment highlight-green">**base class**</span>.
<!-- .element: class="fragment fade-in" -->

The class that it inherits is called  <span class="fragment highlight-green">**derived class**</span>.
<!-- .element: class="fragment fade-in" -->

In other words, the class we inherit from is the parent class.
<!-- .element: class="fragment fade-in" -->

The class that inherits is child class.
<!-- .element: class="fragment fade-in" -->

___

### What about class methods `Laptop` and `Tablet`?

#### Is it possible to distinguish another class?
<!-- .element: class="fragment fade-in" -->

```cpp
void display();
void getUserInput();
```
<!-- .element: class="fragment fade-in" -->

___

## Classes `Screen` and `TouchScreen`

Suppose we add a class `Screen`. This class displays the user interface in real time.
<!-- .element: class="fragment fade-in" -->

We also want to create a class that represents a touchscreen - `TouchScreen` which also allows you to read actions from the user and display them.
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

### How to simplify the above code?
<!-- .element: class="fragment fade-in" -->

___

## Using inheritance to simplify code

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

## Multi-inheritance

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

## Multi-inheritance - disclaimer

Multi-inheritance is inheriting from several base classes.

The choice of implementation is up to the developer.
<!-- .element: class="fragment fade-in" -->

Multi-inheritance will not always be a better solution.
<!-- .element: class="fragment fade-in" -->

You should always consider whether inheriting from a specific class will simplify the program and whether it will not cause any complications in the further process of developing our program.
<!-- .element: class="fragment fade-in" -->

In the worst case, you will have to refactor the program 🙂
<!-- .element: class="fragment fade-in" -->

___

## Inheritance - problems

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

## Inheritance - LSP principle

If we now try to simplify the class through inheritance, the problem will arise:

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

We will make the situation even more difficult when we add more classes, such as Ostrich, in the future. Before the implementation, we always need to think about how to divide the responsibility into individual classes so that
avoid similar problems.

___

### For the curious

Read about the Liskov Substitution Principle (LSP). It tells how an object code should / should not be designed. This rule was broken in the last example.

You can also read about all SOLID principles.

___

## Q&A
