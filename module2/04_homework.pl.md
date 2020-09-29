<!-- .slide: data-background="#111111" -->

# Programowanie obiektowe

## Podsumowanie

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Co pamiętasz z dzisiaj?

### Napisz na czacie jak najwięcej haseł
<!-- .element: class="fragment fade-in" -->

1. <!-- .element: class="fragment fade-in" --> dziedziczenie
2. <!-- .element: class="fragment fade-in" --> wielodziedziczenie
3. <!-- .element: class="fragment fade-in" --> funkcje wirtualne
4. <!-- .element: class="fragment fade-in" --> funkcje czysto wirtualne
5. <!-- .element: class="fragment fade-in" --> klasy abstrakcyjne
6. <!-- .element: class="fragment fade-in" --> interfejsy
7. <!-- .element: class="fragment fade-in" --> polimorfizm
8. <!-- .element: class="fragment fade-in" --> pola i metody statyczne

___

### Pre-work

* Dowiedzcie się czym jest problem diamentowy
* Poczytajcie o zasadach SOLID, dotyczących pisania dobrego kodu obiektowego
* Lektura o wzorcach projektowych z przykładami w C++ - [refactoring.guru](https://refactoring.guru/design-patterns)
* Spróbujcie w grupie metodą Copy & Paste dorzucić system budowania cmake do projektu. W tym celu popatrzcie na dotychczasowe zadania domowe i plik CMakeLists.txt.

___

## Projekt grupowy

Wykorzystajcie kod napisany podczas zajęć. Możecie też skorzystać z kodu w katalogu [solutions](solutions)

Projekt grupowy - kontynuacja. Możecie zmienić grupę jeśli chcecie 🙂

___

## Organizacja prac

* Jak wyglądało wasze daily?
* Czy Code Review nie jest zaniedbane?
* Czy współpraca idzie gładko?
* Zróbcie sobie retrospektywę 🙂

___

### Punktacja

* 3 pierwsze zadania - 5 punktów
* zadania 4, 5, 6 - 8 punktów
* 20 punktów za dostarczenie wszystkich 6 zadań przed 05.07.2020 (niedziela) do 23:59
* brak punktów bonusowych za dostarczenie tylko części zadań przed 05.07
* 6 punktów za pracę w grupie dla każdej osoby z grupy.

___

## Zadanie 1

Napisz klasę `Store`, która będzie umożliwiała dokonywanie zakupów. Wykorzystaj poniższy enum i funkcje.

```cpp
enum class Response {done, lack_of_money, lack_of_cargo, lack_of_space};

Response buy(Cargo* cargo, size_t amount, Player* player);
Response sell(Cargo* cargo, size_t amount, Player* player);
```

___

## Zadanie 2

W klasach `Alcohol`, `Fruit`, `Item` dopisz brakujące metody oraz ich implementacje.

```cpp
// override from Cargo
size_t getPrice() const override;
std::string getName() const override { return name_; }
size_t getAmount() const override { return amount_; }
size_t getBasePrice() const override { return base_price_; }
Cargo& operator+=(size_t amount) override;
Cargo& operator-=(size_t amount) override;
bool operator==(Cargo& cargo) const override;
```

___

## Zadanie 3

Dopisz do klasy `Ship`, `Cargo` oraz `Store` metodę `nextDay()`

* Klasa `Ship`: Metoda powinna odejmować po 1 sztuce monety za każdego członka załogi.
* Klasa `Cargo`: Metoda powinna powodować psucie się towarów.
* Klasa `Store`: Metoda powinna zmieniać ilość towaru w sklepach.

___

## Zadanie 4 (dla ambitnych)

Spróbuj napisać klasę `Time`, która będzie odpowiadać za zarządzanie czasem w grze.

Klasa ta powinna informować inne klasy, takie jak `Cargo`, `Ship`, `Store` o upłynięciu każdego dnia.

Poczytaj czym jest wzorzec projektowy [`Observer`](https://refactoring.guru/design-patterns/observer).

___

## Zadanie 5 (dla ambitnych)

Napisz zaprzyjaźniony operator wypisywania do strumienia

```cpp
friend std::ostream& operator<<(std::ostream& out, const Store& store);
```

Ma on w przystępny sposób wypisywać towar, jaki znajduje się w danym sklepie.

___

## Zadanie 6 (dla ambitnych)

Napisz klasę `Game`, która zarządzać będzie całą rozgrywką.

Dodaj jej jedną metodę publiczną `startGame()`.

Finalnie plik main powinien wyglądać tak:

```cpp
#include "Game.hpp"

constexpr size_t start_money = 1'000;
constexpr size_t game_days = 100;
constexpr size_t final_goal = 2'000;

int main() {
    Game game(start_money, game_days, final_goal);
    game.startGame();

    return 0;
}
```
