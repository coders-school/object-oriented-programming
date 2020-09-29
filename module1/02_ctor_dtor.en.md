<!-- .slide: data-background="#111111" -->

# Object oriented programming

## Constructors and destructors

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Constructor

The class constructor is a recipe that determines how our class should look at the time of creation.
<!-- .element: class="fragment fade-in" -->

This is a special function with the same name as the class.
<!-- .element: class="fragment fade-in" -->

We can provide the constructor with all the information we need, e.g. the size of the array, the date of purchase, etc.
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

## Constructors

A class can have multiple constructors. They must differ in the parameter list because they are function overloads.
<!-- .element: class="fragment fade-in" -->

A class may have, among others argumentless (default) constructor e.g. `Ship()` which is automatically generated if it has no other constructor defined.
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

## Constructor initialization list

We can use the initialization list to initialize the data in the constructor.
<!-- .element: class="fragment fade-in" -->

The initialization list is written after the constructor signature after the colon.
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

## Constructor delegation

An element of the initialization list can even be another constructor of our class.
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

## Destructor

Destructor is a special function to clean our class.
<!-- .element: class="fragment fade-in" -->

Must be named the same as the class, but preceded by a tilde character `~`.
<!-- .element: class="fragment fade-in" -->

We can use it if we want to trigger specific actions while destroying the object, e.g. registering this fact in the log, etc.
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

## Q&A
