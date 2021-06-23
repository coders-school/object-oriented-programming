<!-- .slide: data-background="#111111" -->

# Programowanie obiektowe

## Projekt SHM

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Projekt grupowy

Wykorzystajcie kod napisany podczas zajęć. Możecie też skorzystać z kodu w katalogu [solutions](solutions)

Kontynuujemy i rozwijamy dotychczasową aplikację 🙂

___

## Organizacja prac

* Jak wyglądało wasze daily?
* Czy Code Review nie jest zaniedbane?
* Czy współpraca idzie gładko?
* Zróbcie sobie retrospektywę :)

___

### Punktacja

* zadania 1, 2, 3 - 5 punktów
* zadania 4, 5, 6 - 8 punktów
* 15 punktów za dostarczenie wszystkich 6 zadań przed 18.07.2020 (niedziela) do 23:59
* brak punktów bonusowych za dostarczenie tylko części zadań w terminie
* 6 punktów za pracę w grupie dla każdej osoby z grupy

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
