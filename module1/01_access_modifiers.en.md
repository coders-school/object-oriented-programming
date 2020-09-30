<!-- .slide: data-background="#111111" -->

# Object oriented programming

## Access modifiers

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## `class` vs `struct`

To represent types outside classes (`class`) we still have structures (`struct`).
<!-- .element: class="fragment fade-in" -->

The main difference is that all structure elements - its methods and variables - are public by default. By contrast, in the class they are private by default.
<!-- .element: class="fragment fade-in" -->

Word `private` means that we only have access to these fields inside the class. We cannot appeal to them outside of this class. Word `public` means that we have external access to the data.
<!-- .element: class="fragment fade-in" -->

___

## Access modifiers

### `private` vs `public`

```cpp
class Computer {
private:
    void restart();
};

Computer computer;
computer.restart(); // Forbidden, restart is a private member
```
<!-- .element: class="fragment fade-in" -->

```cpp
class Computer {
public:
    void restart();
};

Computer computer;
computer.restart(); // Ok
```
<!-- .element: class="fragment fade-in" -->

___

### Access modifier `protected`

There is one more access modifier in C++ - `protected`.

We will tell about it when we explain what inheritance is.

___

## Q&A
