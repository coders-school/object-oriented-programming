<!-- .slide: data-background="#111111" -->

# Object oriented programming

## Polymorphism

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Keyword `virtual`

If we want a method to behave differently depending on the real type of the object when using pointers or references to the base class, then it should be marked with the keyword `virtual`. This is called <span class="fragment highlight-green">virtual function</span>.

___
<!-- .slide: style="font-size: 0.9em" -->

## Non-virtual function

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

What will appear on the screen?
<!-- .element: class="fragment fade-in" -->

`tweet, tweet`
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.9em" -->

## Virtual function

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

What will appear on the screen?
<!-- .element: class="fragment fade-in" -->

`chirp, chirp`
<!-- .element: class="fragment fade-in" -->

[Check it out at ideone.com](https://ideone.com/yW43Tq)
<!-- .element: class="fragment fade-in" -->

___

## Keyword `override`

If in the derived class **we overwrite** virtual method, i.e. changing its behavior, you should add a keyword `override`.
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

### A little note

`override` is optional. If we do not give it after the signature of the derived class function then the base class method will be overwritten anyway.
<!-- .element: class="fragment fade-in" -->

Its use, however, is a good practice, because thanks to it the compiler will check whether we are actually overwriting the method from the base class and if not, the program will not compile.
<!-- .element: class="fragment fade-in" -->

Without `override` a new method could be created in the derived class that does not overwrite anything from the base class.
<!-- .element: class="fragment fade-in" -->

**We overwrite** virtual methods, not overload them.
<!-- .element: class="fragment fade-in" -->

___

## Overwriting methods - `override`

Returning to the bird example, classes `Penguin`, `Hummingbird` and `Goose` are derived classes that inherit from certain base classes like `Bird`, `Flyable`, `Soundable`, `Swimmable` and override some of their methods, such as:

* <!-- .element: class="fragment fade-in" --> <code>void eat() override</code>
* <!-- .element: class="fragment fade-in" --> <code>void sleep() override</code>
* <!-- .element: class="fragment fade-in" --> <code>void makeSound() override</code>
* <!-- .element: class="fragment fade-in" --> <code>void fly() override</code>
* <!-- .element: class="fragment fade-in" --> <code>void swim() override</code>

Overwriting such methods means that we can change their implementations.
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

## Common base class

Because the common parent of all classes is the class `Soundable` we can store type pointers in a container `Soundable`.

```cpp
std::vector<std::shared_ptr<Soundable>> birds_;
```

### What data will we get on the output? <!-- .element: class="fragment fade-in" -->

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

## Polymorphism

The phenomenon we just observed is called polymorphism.

Polymorphism allows a function to take various forms (implementations), as in the example.
<!-- .element: class="fragment fade-in" -->

Therefore, if we create objects `Goose`, `Hen` and `Duck`, depending on the object, its version of the method `makeSound` will be called.
<!-- .element: class="fragment fade-in" -->

Polymorphism turns on when we have virtual functions and we use pointers or references to the base type.
<!-- .element: class="fragment fade-in" -->

### Who has played or read The Witcher?
<!-- .element: class="fragment fade-in" -->

___

## Doppler 🙂

In the universe created by our native writer Andrzej Sapkowski, there is an intriguing and interesting race called the Dopplers.
<!-- .element: class="fragment fade-in" -->

This race can take the form of various life forms, it can become a human, an elf, or a dwarf. It changes its characteristics like voice, hair color and even clothes!
<!-- .element: class="fragment fade-in" -->

Despite the fact that this race is of the Doppler type, it can in various circumstances impersonate other races such as elf, dwarf or human.
<!-- .element: class="fragment fade-in" -->

From the C++ point of view, our Doppler is subject to the phenomenon of polymorphism.
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

As we can see, our Doppler can take various forms and behave like them. The pointer is Doppler, but the program knows well when a Doppler impersonates a human, a dwarf, and an elf.

___
<!-- .slide: style="font-size: 0.9em" -->

## Non-virtual destructors

Very important when creating virtual methods and inheritance is creating virtual destructors.
If we use the goodness of polymorphism and we don't mark the destructor as `virtual` the destructor will not be called.

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

## Non-virtual destructors - problem

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

## Virtual destructor

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

## Exercise 3

Write a class `DryFruit` that will inherit from the class `Fruit`.

This class should override methods `getPrice()`, `getName()` and `operator--`.

`operator--` should subtract consumption once every 10 times.

Method `getPrice()` should return three times the value of the base price.

Test polymorphic calls and share your conclusions.
