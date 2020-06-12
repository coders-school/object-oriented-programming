<!-- .slide: data-background="#111111" -->

# Programowanie obiektowe

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## SHM — Symulator Handlu Morskiego

<img height="500" data-src="https://github.com/coders-school/object-oriented-programming/raw/master/module1/img/statek.png" alt="Statek" class="plain">

___
<!-- .slide: data-background="#eeeeee" -->

## SHM - Diagram UML

<a href="https://raw.githubusercontent.com/coders-school/object-oriented-programming/master/shm-uml.svg">
    <img height="500" data-src="https://raw.githubusercontent.com/coders-school/object-oriented-programming/master/shm-uml.svg" alt="Diagram klas - SHM" class="plain">
</a>

___

## Wprowadzenie do programowania obiektowego

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

___

## Kompozycja, agregacja

Nic nie stoi na przeszkodzie, by jeden obiekt składał się z innych obiektów. W ten sposób sprawiamy, że struktura naszego kodu staje się bardziej zrozumiała.

Zawieranie się jednego obiektu w drugim nazywa się kompozycją lub agregacją. Nie są to synonimy, są to dwa trochę inne typy zawierania obiektów, ale obecnie to nie jest istotne. Dla przykładu z komputerem:
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

Komputer składa się (jest skomponowany) z procesora, napędu, płyty głównej, karty graficznej, pamięci.
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: data-background="#eeeeee" -->

## Diagram klas - kompozycja, agregacja

<img height="250" data-src="https://github.com/coders-school/object-oriented-programming/raw/master/module1/img/composition_aggregation.png" alt="Kompozycja i agregacja" class="plain">

* <!-- .element: class="fragment fade-in" --> Kompozycja: Samochód (Car) zawiera dokładnie 1 Gaźnik (Carburetor). Gaźnik jest częścią dokładnie jednego samochodu. Bez samochodu gaźnik nic nie robi, nie może więc działać bez niego.
* <!-- .element: class="fragment fade-in" --> Agregacja: Staw (Pond) może zawierać dowolną liczbę (0..*) Kaczek (Duck). Kaczka może być w danej chwili tylko w jednym stawie lub w żadnych (0..1). Kaczka może żyć poza stawem.

[Diagram klas - wikipedia](https://en.wikipedia.org/wiki/Class_diagram)
<!-- .element: class="fragment fade-in" -->

___

## Q&A
