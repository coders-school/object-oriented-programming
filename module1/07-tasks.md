<!-- .slide: data-background="#111111" -->

# Programowanie obiektowe

## Zadania

<a href="https://coders.school">
    <img width="500" src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Zadanie 1

Napisz klasę `Ship`, która przechowywać będzie dane statku:

* `id_` - identyfikator statku
* `name_` - nazwa statku
* `speed_` - prędkość statku
* `maxCrew_` - maksymalna liczna załogi
* `capacity_` - ładowność statku

Dane powinny być prywatne, a dostęp do nich dostęp powinniśmy mieć przez gettery.
Pomyśl samodzielnie jakiego typu powinny to być dane.

___

## Zadanie 2

Dodaj do klasy `Ship` konstruktory, które przyjmować będą odpowiednie dane. Chcemy 3 konstruktory:

* Pierwszy nieprzyjmujący żadnych argumentów. `id_` dla takiego obiektu powinno wynosić `-1`
* Drugi przyjmujący wszystkie dane
* Trzeci przyjmujący `id`, `speed` i `maxCrew` (postaraj się wykorzystać drugi konstruktor przy pisaniu trzeciego - patrz Delegowanie konstruktorów)

Dodatkowo dodaj metodę `void setName(const std::string&)`, która pozwoli na ustawianie nazwy statku.
