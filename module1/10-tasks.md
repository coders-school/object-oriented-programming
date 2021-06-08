<!-- .slide: data-background="#111111" -->

# Programowanie obiektowe

## Zadania

<a href="https://coders.school">
    <img width="500" src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Zadanie 3

Dodaj do klasy `Ship`:

* zmienną `size_t crew_` określającą aktualną liczbę załogi na statku
* `Ship& operator+=(const int)`, który dodawać będzie załogę do statku
* `Ship& operator-=(const int)`, który będzie ją odejmował.

___

## Zadanie 4

Utwórz klasę `Cargo`. Ma ona reprezentować 1 typ towaru na statku. Będzie ona posiadać 3 pola:

* `name_` - nazwa towaru
* `amount_` - ilość towaru
* `basePrice_` - bazowa cena towaru

Następnie napisz w klasie `Cargo`:

* `Cargo& operator+=(const size_t)`, który będzie dodawać podaną ilość towaru
* `Cargo& operator-=(const size_t)`, który będzie odejmował podaną ilość towaru

Zastanów się także jak będziesz przechowywać towary na statku.
