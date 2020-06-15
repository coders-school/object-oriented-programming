<!-- .slide: data-background="#111111" -->

# Programowanie obiektowe

## Zmienne i funkcje statyczne

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___
<!-- .slide: style="font-size: 0.9em" -->

## Zmienne i funkcje statyczne

Czasami chcielibyśmy przypisać jakąś stałą cechę do klasy. Nie konkretnych obiektów, a klasy samej w sobie. Np. Każdy obiekt klasy ma nazwę "Obiekt".

```cpp
class Object {
public:
    std::string GetName() const { return name_; }

private:
    const std::string name_ = "Object";
};
```

W celu otrzymania nazwy tego obiektu, musimy najpierw utworzyć obiekt, a następnie zawołać `getName()`.

```cpp
int main() {
    Object obj;
    std::cout << obj.getName() << '\n';
}
```

Nawet jeżeli obiekt zajmowałby dużo miejsca w pamięci a my chcielibyśmy tylko jego nazwę i tak musimy go utworzyć, ponieważ tylko na nim możemy zawołać metodę `getName()`.

___
<!-- .slide: style="font-size: 0.9em" -->

## `static`

Rozwiązaniem tej uciążliwości jest `static`. Co więcej, problem ten możemy rozwiązać na 2 sposoby. Nie musimy w ten sposób tworzyć specjalnie obiektu, aby dostać się do cechy klasy, jaką jest jej nazwa.

```cpp
class Object {
public:
    static std::string getName() { return "Object"; }
};

class Object2 {
public:
    static std::string name_;
};

std::string Object2::name_{"Object2"};

int main() {
    std::cout << Object::getName() << '\n';
    std::cout << Object2::name_ << '\n';

    return 0;
}
```

<!-- TODO: Brakuje tu motywacji na jakimś konkretnym przykładzie -->

___

## Q&A
