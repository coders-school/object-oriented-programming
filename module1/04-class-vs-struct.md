<!-- .slide: data-background="#111111" -->

# Programowanie obiektowe

## `class` vs `struct`

<a href="https://coders.school">
    <img width="500" src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## `private` vs `public`

Do reprezentacji typów poza klasami (`class`) mamy jeszcze struktury (`struct`).
<!-- .element: class="fragment fade-in" -->

Podstawowa (i w zasadzie jedyna) różnica polega na tym, że wszystkie elementy struktury - jej metody i zmienne są domyślnie publiczne. W klasie wszystko jest domyślnie prywatne.
<!-- .element: class="fragment fade-in" -->

Słowo `private` oznacza, że dostęp do tych pól lub metod mamy tylko wewnątrz klasy. Nie możemy się do nich odwoływać poza tą klasą. Słowo `public` oznacza, że mamy też dostęp z zewnątrz.
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.85em" -->

## `class` vs `struct`

```cpp
class Computer {
public:
    void restart();
};
computer.restart(); // Ok
```
<!-- .element: class="fragment fade-in" -->

```cpp
struct Computer {
public:
    void restart();
};
computer.restart(); // Ok
```
<!-- .element: class="fragment fade-in" -->

```cpp
class Computer {
    void restart();
};
computer.restart(); // Forbidden, restart is a private member
```
<!-- .element: class="fragment fade-in" -->

```cpp
struct Computer {
    void restart();
};
computer.restart(); // Ok
```
<!-- .element: class="fragment fade-in" -->

___

## `class` vs `struct`

### Szablony

Jest jeszcze jedna różnica w użyciu słów `class` i `struct`, ale dotyczy ona szablonów.
<!-- .element: class="fragment fade-in" -->

```cpp
template <class T>
void function(T arg);   // Ok
```
<!-- .element: class="fragment fade-in" -->

```cpp
template <struct T>
void function(T arg);   // Compilation error
```
<!-- .element: class="fragment fade-in" -->

```cpp
template <typename T>
void function(T arg);   // Ok
```
<!-- .element: class="fragment fade-in" -->

___

### Wskazówka

* Domyślnie twórz klasy (`class`) i rób wszystko prywatne. Dopiero to co jest niezbędne przestawiaj jako publiczne.
* Często robimy prywatne pola i publiczne metody, które je obsługują (gettery i settery). O nich opowiemy później.
