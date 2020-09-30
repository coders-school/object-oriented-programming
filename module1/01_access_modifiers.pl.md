<!-- .slide: data-background="#111111" -->

# Programowanie obiektowe

## Modyfikatory dostępu

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## `class` vs `struct`

Do reprezentacji typów poza klasami (`class`) mamy jeszcze struktury (`struct`).
<!-- .element: class="fragment fade-in" -->

Podstawowa różnica polega na tym, że wszystkie elementy struktury - jej metody i zmienne są domyślnie publiczne. Natomiast w klasie są domyślnie prywatne.
<!-- .element: class="fragment fade-in" -->

Słowo `private` oznacza, że tylko wewnątrz klasy mamy dostęp do tych pól. Nie możemy się do nich odwoływać poza tą klasą. Słowo `public` oznacza, że mamy dostęp z zewnątrz do danych.
<!-- .element: class="fragment fade-in" -->

___

## Modyfikatory dostępu

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

### Modyfikator dostępu `protected`

Istnieje jeszcze jeden modyfikator dostępu w C++ - `protected`.

O nim opowiemy sobie, gdy już wyjaśnimy czym jest dziedziczenie.

___

## Q&A
