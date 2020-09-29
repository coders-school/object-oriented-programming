<!-- .slide: data-background="#111111" -->

# Object oriented programming

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## SHM (Sea Trade Simulator)

<img height="500" data-src="img/statek.png" src="https://github.com/coders-school/object-oriented-programming/raw/master/module1/img/statek.png" alt="Statek" class="plain">

___
<!-- .slide: data-background="#eeeeee" -->

## SHM - UML diagram

<a href="https://raw.githubusercontent.com/coders-school/object-oriented-programming/master/shm-uml.svg">
    <img height="500" data-src="../shm-uml.svg" src="https://raw.githubusercontent.com/coders-school/object-oriented-programming/master/shm-uml.svg" alt="Diagram klas - SHM" class="plain">
</a>

___

## Introduction to object oriented programming

___

### What is an Object?

An object in C++ is no different from an actual object in real life. An object is a "specific" object. We can have many identical objects. Some of them can be distinguished by names. In C++ we can have objects such as:

* <!-- .element: class="fragment fade-in" --> HP computer, Lenovo computer, MacBook computer
* <!-- .element: class="fragment fade-in" --> HP printer, Epson printer
* <!-- .element: class="fragment fade-in" --> Stabilo Schwan 306 HB pencil = 2 1/2
* <!-- .element: class="fragment fade-in" --> Casio calculator
* <!-- .element: class="fragment fade-in" --> ...

The object exists in computer memory while the program is running. We can have many objects of the same type.
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> Type: <code>Dog</code>
* <!-- .element: class="fragment fade-in" --> Objects of type <code>Dog</code>: <code>Max</code>, <code>Milo</code>, <code>Coco</code>, ...

___

### What is a class?

A class is a type.
<!-- .element: class="fragment fade-in" -->

A class in C++ is slightly different from an actual class 🙂 In C++ (or object-oriented programming in general) a class defines the characteristics of an object:
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> what properties will this object have (fields)
* <!-- .element: class="fragment fade-in" --> what methods of operation will it have (methods, functions)

___

### Questions

* <!-- .element: class="fragment fade-in" --> what properties could a <code>computer</code> object have?
* <!-- .element: class="fragment fade-in" --> what methods could the <code>computer</code> have?

```cpp
class Computer {
    // fields
    Processor processor_;
    Drive drive_;
    Motherboard motherboard_;
    GraphicsCard graphics_card_;
    Memory memory_;

    // methods
    void run();
    void restart();
    void shutdown();
};
```
<!-- .element: class="fragment fade-in" -->

___

## Composition, aggregation

Nothing prevents one object from being composed of other objects. In this way, we make the structure of our code more understandable.

Containing one object within another is called composition or aggregation. These are not synonyms, they are two slightly different types of object containment, but that doesn't matter at the moment. For example with a computer:
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

A computer consists (is composed of) of a processor, drive, motherboard, graphics card, memory.
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: data-background="#eeeeee" -->

## Class diagram - composition, aggregation

<img height="250" data-src="img/composition_aggregation.png" src="https://github.com/coders-school/object-oriented-programming/raw/master/module1/img/composition_aggregation.png" alt="Kompozycja i agregacja" class="plain">

* <!-- .element: class="fragment fade-in" --> Composition: A car contains exactly 1 Carburetor. The carburetor is part of exactly one car. Without a car, the carburetor does nothing, so it cannot function without it.
* <!-- .element: class="fragment fade-in" --> Aggregation: Pond can contain any number (0 .. *) of Ducks. The duck may be in only one pond at a time or in none (0..1). The duck can live outside the pond.

[Class diagram - wikipedia](https://en.wikipedia.org/wiki/Class_diagram)
<!-- .element: class="fragment fade-in" -->

___

## Q&A
