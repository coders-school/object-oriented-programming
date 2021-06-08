<!-- .slide: data-background="#111111" -->

# Programowanie obiektowe

## Metody `const`

<a href="https://coders.school">
    <img width="500" src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

### Przykład

```cpp
class Person {
    const std::string name_;
    unsigned age_;

public:
    Person(const std::string & name, unsigned age)
        : name_(name), age_(age)
    {}

    std::string getName() const { return name_; }
    // void setName(const std::string & name) { name_ = name; }
    // not allowed, name_ is const

    unsigned getAge() const { return age_; }
    void setAge(unsigned age) { age_ = age; }
};
```
<!-- .element: class="fragment fade-in" -->

#### [Otwórz pełny kod](person.cpp)
<!-- .element: class="fragment fade-in" -->

___

### `const`'owe metody

```cpp
std::string getName() const { return name_; }
```

Metody `const` można wywołać na obiektach klasy, które są stałe.
<!-- .element: class="fragment fade-in" -->

Metody, które nie są `const` wywołane na stałych obiektach powodują błąd kompilacji.
<!-- .element: class="fragment fade-in" -->

Zazwyczaj nie tworzymy stałych obiektów, ale przekazujemy je przez `const&`, aby nie pozwolić na ich modyfikację.
<!-- .element: class="fragment fade-in" -->