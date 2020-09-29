<!-- .slide: data-background="#111111" -->

# Object oriented programming

## Static variables and functions

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___
<!-- .slide: style="font-size: 0.85em" -->

## "Class variable or constant"

Sometimes we would like to assign some permanent trait to a class.
Not specific objects, but a class itself.
For example, each class object is named "Object".
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

In order to get the name of this object, we need to create the object first and then call it `getName()`.
<!-- .element: class="fragment fade-in" -->

```cpp
int main() {
    Object obj;
    std::cout << obj.getName() << '\n';
}
```
<!-- .element: class="fragment fade-in" -->

Even if the object would take up a lot of memory and we only want its name, we still have to create it, because only on it we can call the method `getName()`.
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.9em" -->

## `static`

The solution to this nuisance is `static`. Moreover, we can solve this problem in two ways. We don't have to create an object this way to get to the class attribute, which is its name.

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

## Task 4

Convert base class `Coordinates` so that it has a static function

```cpp
static size_t distance(const Coordinates& lhs, const Coordinates& rhs)
```

This function should return the distance between two positions.
