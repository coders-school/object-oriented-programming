<!-- .slide: data-background="#111111" -->

# Object oriented programming

## Virtual methods, interfaces, abstract classes

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___
<!-- .slide: style="font-size: 0.9em" -->

## Pure virtual methods

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

Methods `eat()` and `sleep()` are called pure virtual methods. Therefore we have `= 0;`. This means that we will not find their implementation for the `Bird` class. Classes that inherit from `Bird` will have to implement it themselves.
<!-- .element: class="fragment fade-in" -->

For now we will not talk about the meaning of the `virtual` keyword. The only thing you need to know for now is that for the method to be purely virtual `= 0;` it must be proceeded by `virtual`.
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.9em" -->

## Interfaces

One of the ideas for solving the problem of multi-inheritance is creating the so-called interfaces, their inheritance and overloading the implementation of methods from base classes. Interfaces define "skills" and are easy to connect with each other.

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

## Use of interfaces

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

## What is an interface?

An interface is a set of functions that the class implementing it must implement.
<!-- .element: class="fragment fade-in" -->

An interface is a set of functions that a class that inherits from it must implement.
<!-- .element: class="fragment fade-in" -->

Failure to implement a purely virtual function is a linker error (undefined reference).
<!-- .element: class="fragment fade-in" -->

### Interface definition
<!-- .element: class="fragment fade-in" -->

A fully valid interface definition is the public part of a class / functional set. They can be methods, fields, or types, but most often we will use the interface words for public methods of a class.
<!-- .element: class="fragment fade-in" -->

[See the vector interface on cppreference.com](https://en.cppreference.com/w/cpp/container/vector)
<!-- .element: class="fragment fade-in" -->

There you will find a description of its public methods (member functions), internal types (member types), and loose functions that use it (non-member functions).
<!-- .element: class="fragment fade-in" -->

___

## Abstract class

It's impossible to create an object of a class that has <span class="fragment highlight-green">**at least one pure virtual function**</span>.
<!-- .element: class="fragment fade-in" -->

A pure virtual function has no implementation, so there cannot be an object for which the linker does not find an implementation of one of its functions.
<!-- .element: class="fragment fade-in" -->

We can store a pointer to the type of this class, but we cannot create an instance of it (an object) because we do not have its behavior defined.
<!-- .element: class="fragment fade-in" -->

This class is called  <span class="fragment highlight-green">**an abstract class**</span> and is only used to unify the interface, not to create objects.
<!-- .element: class="fragment fade-in" -->

Only an object of a derived class that implements all the missing methods can be created.
<!-- .element: class="fragment fade-in" -->

___

## Keywords `virtual` and `override`

What are these keywords? What are they doing? About this in a moment 🙂
<!-- .element: class="fragment fade-in" -->

___

## Q&A

___

## Task 1

Convert class `Cargo` into an interface with 4 pure virtual methods.

```cpp
virtual size_t getPrice() const = 0;
virtual std::string getName() const = 0;
virtual size_t getAmount() const = 0;
virtual size_t getBasePrice() const = 0;
```

___

## Task 1 cont.

Create 3 classes derived from `Cargo`:

* `Fruit`
* `Alcohol`
* `Item`

Class `Fruit` should have an additional variable specifying the time to spoil and `operator--` which will subtract this time by 1.
Method `getPrice()` it should reduce the price accordingly with the spoilage time of our fruit.

Class `Alcohol` should have an additional variable specifying the percentage of spirit.
Method `getPrice()` should be proportionally higher depending on the alcohol strength.
A base price should be set for 96% spirit.

Class `Item` should have an additional enum variable specifying the rarity of the item (common, rare, epic, legendary).
Method `getPrice()` should be adequately calculated from the item's rarity level.

___

## Exercise 2

Using a common base class `Cargo` try to store all the goods in one vector in the `Ship` class.

Add a feature `void load(std::shared_ptr<Cargo> cargo)` that adds the goods and (for those willing) `void unload(Cargo* cargo)` that removes the item from the class object `Ship`.
