<!-- .slide: data-background="#111111" -->

# Programowanie obiektowe

## Zadania

<a href="https://coders.school">
    <img width="500" src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Zadanie 8

Napisz/przekształć klasę `Coordinates`, która ma określać współrzędne na mapie. Powinna ona przyjmować w konstruktorze 2 parametry `positionX`, `positionY` oraz operator porównania.

Ma ona posiadać funkcję statyczną `distance`:

```cpp
static size_t distance(const Coordinates& lhs, const Coordinates& rhs)
```

Funkcja ta powinna zwracać dystans pomiędzy dwoma pozycjami.
