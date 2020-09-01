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

1. <!-- .element: class="fragment fade-in" --> klasy
2. <!-- .element: class="fragment fade-in" --> obiekty
3. <!-- .element: class="fragment fade-in" --> pola, właściwości
4. <!-- .element: class="fragment fade-in" --> metody, funkcje klasy
5. <!-- .element: class="fragment fade-in" --> modyfikatory dostępu - `public`, `private`
6. <!-- .element: class="fragment fade-in" --> konstruktory
7. <!-- .element: class="fragment fade-in" --> destruktory
8. <!-- .element: class="fragment fade-in" --> hermetyzacja
9. <!-- .element: class="fragment fade-in" --> gettery
10. <!-- .element: class="fragment fade-in" --> settery

___

### Pre-work

* Poczytaj i pooglądaj wideo o dziedziczeniu i polimorfizmie

___

## Projekt grupowy

Wykorzystajcie kod napisany podczas zajęć. Możecie też skorzystać z kodu w katalogu [solutions](solutions)

Projekt grupowy. Polecane grupy 5 osobowe (4-6 też są ok).

Zróbcie Fork tego repo, a cały projekt ma się znaleźć w katalogu [shm](../shm)

Współpracujcie na jednym forku za pomocą branchy lub Pull Requestów z waszych własnych forków.

___

## Organizacja prac

Do podziału zadań i śledzenia statusu możecie wykorzystać zakładkę [Projects na GitHubie](https://github.com/coders-school/object-oriented-programming/projects). Możecie skonfigurować go z szablonu Automated kanban with reviews.

### Planning

Rozpocznijcie planowaniem, na którym utworzycie karteczki na każde zadanie w kolumnie To Do. Najlepiej przekonwertować je na Issues. Dzięki temu można przypisywać się do zadań i pisać w nich komentarze. Napiszcie też przy każdym zadaniu na ile dni pracy je szacujecie. Po zakończonym planningu wyślijcie proszę na kanale `#planning` linka do waszej tablicy projektowej na GitHubie.

### Daily

Podczas prac na bieżąco aktualizujcie zadania. Każdego dnia o stałej porze synchronizujecie się i mówicie jakie są problemy.

___

### Code Review

Każde dostarczenie zadania musi być poprzedzone Code Review innej osoby z zespołu (lub najlepiej kilku), aby zachować spójność i współdziałanie całości.

### Zakończenie

Ten projekt będzie jeszcze dalej rozwijany. Oczekujemy, że niezależnie od liczby wykonanych zadań zrobicie Pull Request przed 28.06 (w Scrumie to zespół decyduje ile zadań uda mu się zrobić na określony termin).

___

### Punktacja

* Każde dostarczone zadanie to 5 punktów
* 20 punktów za dostarczenie wszystkich 8 zadań przed 28.06.2020 (niedziela) do 23:59
* brak punktów bonusowych za dostarczenie tylko części zadań przed 28.06.
* 6 punktów za pracę w grupie dla każdej osoby z grupy.

___

## Zadanie 1

W klasie `Cargo` napisz operator porównania (`operator==`), który będzie sprawdzał, czy towary są takie same.

___

## Zadanie 2

Do klasy `Cargo` dopisz gettery oraz odpowiedni konstruktor, który wypełni wszystkie pola tej klasy.

___

## Zadanie 3

Napisz klasę `Island`, która będzie posiadała zmienną `Coordinates position_` oraz odpowiedni getter.

Klasa `Coordinates` ma określać współrzędne na mapie. Również ją napisz. Powinna przyjmować w konstruktorze 2 parametry `positionX`, `positionY` oraz operator porównania.
<!-- Klasa `Island` powinna posiadać także sklep. -->

___

## Zadanie 4

Napisz klasę `Map`, która będzie posiadała `std::vector<Island>` przechowujący wszystkie wyspy na mapie, oraz zmienną `Island* currentPosition_` określającą aktualną pozycję gracza na mapie.

___

## Zadanie 5

W klasie `Map` utwórz konstruktor bezargumentowy, a w jego ciele utwórz 10 wysp, które przechowasz w `std::vector<Island>`.
Do wygenerowania losowych wartości pozycji wysp na mapie skorzystaj z [przykładu na cppreference](https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution).
Wymyśl sposób, aby pozycje wysp się nie powielały.

___

## Zadanie 6

W klasie `Map` napisz funkcję

`Island* getIsland(const Island::Coordinates& coordinate)`

Powinna ona przeszukać `std::vector<Island>` i zwrócić szukaną wyspę.

___

## Zadanie 7

Napisz klasę `Player`, która posiadać będzie 3 pola:

* `std::shared_ptr<Ship> ship_` (dla chętnych, spróbuj użyć `std::unique_ptr<>`)
* `money_`
* `availableSpace_`

Dopisz także odpowiednie gettery oraz konstruktor.

Dopisz także 2 funkcje, które powinny zwracać dane ze statku:

* `size_t getSpeed() const`
* `Cargo* getCargo(size_t index) const`

___

## Zadanie 8

W klasie `Player` napisz prywatną funkcję, która obliczać będzie `availableSpace_` na podstawie aktualnej ilości towaru na statku.
