<!-- .slide: data-background="#111111" -->

# Programowanie obiektowe

## Zadania

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Zadanie 1

Napisz klasę `Ship`, która przechowywać będzie dane statku:

* `id_`
* `name_`
* `speed_`
* `maxCrew_`
* `capacity_`

Dane powinny być prywatne, a dostęp do nich dostęp powinniśmy mieć przez gettery.

___

## Zadanie 2

Dodaj do klasy `Ship` konstruktory, które przyjmować będą odpowiednie dane. Konstruktorów powinno być 3:

* Pierwszy nieprzyjmujący żadnych argumentów -> `id_` dla takiego obiektu powinno wynosić `-1`
* Drugi przyjmujący wszystkie dane
* Trzeci przyjmujący `id`, `speed` i `maxCrew` (postaraj się wykorzystać drugi konstruktor przy pisaniu trzeciego)

Dodatkowo dodaj metodę `void set_name(const std::string&)`.

___

## Zadanie 3

Dodaj do klasy `Ship`:

* zmienną `size_t crew_` określającą aktualna liczbę załogi na statku
* `Ship& operator+=(const int)`, który dodawać będzie załogę do statku
* `Ship& operator-=(const int)`, który będzie ją odejmował.

___

## Zadanie 4

Utwórz klasę `Cargo`, która posiadać będzie 3 pola:

* `name_` - nazwa towaru
* `amount_` - ilość towaru
* `basePrice_` - bazowa cena towaru

Następnie napisz w klasie statku `Cargo`:

* `Cargo& operator+=(const size_t)`, który będzie dodawać towar do statku
* `Cargo& operator-=(const size_t)`, który będzie odejmował towar

Zastanów się także jak rozwiążesz problem przechowywania towaru na statku.

___

## Q&A
