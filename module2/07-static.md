<!-- .slide: data-background="#111111" -->

# Programowanie obiektowe

## Pola i funkcje statyczne

<a href="https://coders.school">
    <img width="500" src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___
<!-- .slide: style="font-size: 0.85em" -->

## Pola klasy

Czasami chcielibyśmy przypisać jakąś stałą cechę do klasy.
Nie konkretnych obiektów, a klasy samej w sobie, tak, aby była ona wspólna dla wszystkich obiektów tej klasy.
Np. każdy obiekt klasy ma nazwę "Object".
<!-- .element: class="fragment fade-in" -->

```cpp
class Object {
public:
    std::string getName() const { return name_; }

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

Nawet jeżeli obiekt zajmowałby dużo miejsca w pamięci, a my chcielibyśmy tylko jego nazwę i tak musimy go utworzyć, ponieważ tylko na nim możemy zawołać metodę `getName()`.
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.8em" -->

## `static`

Rozwiązaniem tej uciążliwości jest `static`. Co więcej, problem ten możemy rozwiązać na 2 sposoby. Nie musimy w ten sposób tworzyć specjalnie obiektu, aby dostać się do cechy klasy, jaką jest jej nazwa.

```cpp
class ClassA {
public:
    static std::string getName() { return "ClassA"; }
};

class ClassB {
public:
    static std::string name_;
};

std::string ClassB::name_{"ClassB"};

int main() {
    std::cout << ClassA::getName() << '\n';
    std::cout << ClassB::name_ << '\n';

    ClassA objA;
    std::cout << objA.getName() << '\n';
    ClassB objB;
    std::cout << objB.name_ << '\n';

    return 0;
}
```
<!-- .element: class="fragment fade-in" -->

<!-- TODO: Brakuje tu motywacji na jakimś konkretnym przykładzie -->
