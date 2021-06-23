<!-- .slide: data-background="#111111" -->

# Programowanie obiektowe

## Zadania

<a href="https://coders.school">
    <img width="500" src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Zadanie 5

Przekształć klasę `Cargo` w interfejs z 4 czysto wirtualnymi metodami.

```cpp
virtual size_t getPrice() const = 0;
virtual std::string getName() const = 0;
virtual size_t getAmount() const = 0;
virtual size_t getBasePrice() const = 0;
```

___

## Zadanie 5 cd.

Utwórz 3 pochodne klasy `Cargo`:

* `Fruit`
* `Alcohol`
* `Item`

Klasa `Fruit` powinna mieć dodatkową zmienną określającą czas do zepsucia oraz `operator--` który będzie odejmował ten czas o 1.
Metoda `getPrice()` powinna redukować cenę odpowiednio wraz z czasem psucia naszego owocu.

Klasa `Alcohol` powinna mieć dodatkową zmienną określającą procentowy udział spirytusu.
Metoda `getPrice()` powinna być proporcjonalnie wyższa w zależności od mocy alkoholu.
Należy ustalić bazową cenę za spirytus 96%.

Klasa `Item` powinna mieć dodatkową zmienną enum określającą rzadkość przedmiotu (common, rare, epic, legendary).
Metoda `getPrice()` powinna być adekwatnie wyliczana od poziomu rzadkości przedmiotu.

___

## Zadanie 6

Wykorzystując wspólną klasę bazową `Cargo` spróbuj przechowywać wszystkie towary w jednym wektorze w klasie `Ship`.

Dodaj funkcję `void load(std::shared_ptr<Cargo> cargo)`, która dodaje towar i (dla chętnych) `void unload(Cargo* cargo)`, która usuwa towar z obiektu klasy `Ship`.
