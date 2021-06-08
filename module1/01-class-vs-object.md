<!-- .slide: data-background="#111111" -->

# Programowanie obiektowe

## Klasa vs obiekt

<a href="https://coders.school">
    <img width="500" src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

### Czym jest obiekt?

Obiekt w C++ niczym się nie różni od rzeczywistego obiektu. Obiekt to "konkretny" obiekt. Możemy mieć wiele identycznych obiektów. Niektórym dla rozróżnienia możemy nadać nazwy. W C++ możemy mieć obiekty takie jak:

* <!-- .element: class="fragment fade-in" --> komputer HP, komputer Lenovo, komputer MacBook
* <!-- .element: class="fragment fade-in" --> drukarka HP, drukarka Epson
* <!-- .element: class="fragment fade-in" --> ołówek Stabilo Schwan 306 HB = 2 1/2
* <!-- .element: class="fragment fade-in" --> kalkulator Casio
* <!-- .element: class="fragment fade-in" --> ...

Obiekt istnieje w pamięci komputera podczas wykonywania programu. Możemy mieć wiele obiektów tego samego typu.
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> Typ: <code>Pies</code>
* <!-- .element: class="fragment fade-in" --> Obiekty typu <code>Pies</code>: <code>Azor</code>, <code>Burek</code>, <code>Decybel</code>, ...

___

### Czym jest klasa?

Klasa to typ.
<!-- .element: class="fragment fade-in" -->

Klasa w C++ nieco różni się od rzeczywistej klasy :) W C++ (czy też programowaniu obiektowym ogólnie) klasa określa cechy obiektu:
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> jakie właściwości będzie miał ten obiekt (pola)
* <!-- .element: class="fragment fade-in" --> jakie będzie miał metody działania (metody, funkcje)

___

### Pytania

* <!-- .element: class="fragment fade-in" --> jakie właściwości mógłby mieć obiekt komputer?
* <!-- .element: class="fragment fade-in" --> jakie metody mógłby mieć komputer?

```cpp
class Computer {
    // fields (pola, właściwości)
    Processor processor_;
    Drive drive_;
    Motherboard motherboard_;
    GraphicsCard graphics_card_;
    Memory memory_;

    // methods (metody)
    void run();
    void restart();
    void shutdown();
};
```
<!-- .element: class="fragment fade-in" -->
