<!-- .slide: data-background="#111111" -->

# Object oriented programming

## Hermetization

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Hermetization

In order to protect our object against unwanted modifications, we can make the so-called hermetization or encapsulation.
<!-- .element: class="fragment fade-in" -->

It consists in placing all properties (fields) in the private section and enabling their modification by public functions.
<!-- .element: class="fragment fade-in" -->

___

## setters and getters

The simplest functions that allow modifications are the so-called setters.
<!-- .element: class="fragment fade-in" -->

A setter is a function that assigns a given value to a specific variable.
<!-- .element: class="fragment fade-in" -->

```cpp
void setName(const std::string& name) { name_ = name; }
```
<!-- .element: class="fragment fade-in" -->

Since the data is private, it is also not possible to read it, so we do it through getters.
<!-- .element: class="fragment fade-in" -->

```cpp
std::string getName() const { return name_ }
```
<!-- .element: class="fragment fade-in" -->

Of course, we don't always need to allow all variables to be modified, just as not all variables can have getters. The choice is up to the developer.
<!-- .element: class="fragment fade-in" -->

___

## Q&A
