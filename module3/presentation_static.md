<!-- .slide: data-background="#111111" -->

# Programowanie obiektowe

## Zmienne i funkcje statyczne

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___
<!-- .slide: style="font-size: 0.85em" -->

## "Zmienna lub stała klasy"

Czasami chcielibyśmy przypisać jakąś stałą cechę do klasy.
Nie konkretnych obiektów, a klasy samej w sobie.
Np. każdy obiekt klasy ma nazwę "Object".
<!-- .element: class="fragment fade-in" -->

```cpp
class Object {
public:
    std::string GetName() const { return name_; }

private:
    const std::string name_ = "Object";
};
```
<!-- .element: class="fragment fade-in" -->

W celu otrzymania nazwy tego obiektu, musimy najpierw utworzyć obiekt, a następnie zawołać `getName()`.
<!-- .element: class="fragment fade-in" -->

```cpp
int main() {
    Object obj;
    std::cout << obj.getName() << '\n';
}
```
<!-- .element: class="fragment fade-in" -->

Nawet jeżeli obiekt zajmowałby dużo miejsca w pamięci a my chcielibyśmy tylko jego nazwę i tak musimy go utworzyć, ponieważ tylko na nim możemy zawołać metodę `getName()`.
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.9em" -->

## `static`

Rozwiązaniem tej uciążliwości jest `static`. Co więcej, problem ten możemy rozwiązać na 2 sposoby. Nie musimy w ten sposób tworzyć specjalnie obiektu, aby dostać się do cechy klasy, jaką jest jej nazwa.

```cpp
class ObjectA {
public:
    static std::string getName() { return "ObjectA"; }
};

class ObjectB {
public:
    static std::string name_;
};

std::string ObjectB::name_{"ObjectB"};

int main() {
    std::cout << ObjectA::getName() << '\n';
    std::cout << ObjectB::name_ << '\n';

    return 0;
}
```
<!-- .element: class="fragment fade-in" -->

<!-- TODO: Brakuje tu motywacji na jakimś konkretnym przykładzie -->

___

## Q&A

___

## Zadanie 4

Przekształć klasę bazową `Coordinates`, tak aby miała funkcję statyczną

```cpp
static size_t distance(const Coordinates& lhs, const Coordinates& rhs)
```

Funkcja ta powinna zwracać dystans pomiędzy dwoma pozycjami.
