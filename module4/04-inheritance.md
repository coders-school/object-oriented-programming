<!-- .slide: data-background="#111111" -->

# Dziedziczenie

___

## Kolejność wywołań konstruktorów i destruktorów

* <!-- .element: class="fragment fade-in" --> Konstruktory - najpierw klasa bazowa, potem pochodna
* <!-- .element: class="fragment fade-in" --> Destruktory - zawsze w odwrotnej kolejności niż konstruktory
* <!-- .element: class="fragment fade-in" --> <a href="https://ideone.com/Kgb46n">Birthday cake</a>

___

### Co wyświetli się na ekranie?

```cpp
#include <iostream>

using namespace std;

class Chocolate {
public:
    Chocolate()  { cout << "Chocolate ctor" << endl; }
    ~Chocolate() { cout << "Chocolate dtor" << endl; }
};

class ChocolateCake {
public:
    ChocolateCake()  { cout << "ChocolateCake ctor" << endl; }
    ~ChocolateCake() { cout << "ChocolateCake dtor" << endl; }
private:
    Chocolate chocolate;
};

class Candles {
public:
    Candles()  { cout << "Candles ctor" << endl; }
    ~Candles() { cout << "Candles dtor" << endl; }
};

class BirthdayCake : public ChocolateCake {
public:
    BirthdayCake()  { cout << "BirthdayCake ctor" << endl; }
    ~BirthdayCake() { cout << "BirthdayCake dtor" << endl; }
private:
    Candles candles;
};

int main(int argc, char *argv[]) {
    BirthdayCake birthdayCake;
    return 0;
}
```

#### Napisz w komentarzu 🙂
<!-- .element: class="fragment fade-in" -->

___

## `private` czy `public`?

* <!-- .element: class="fragment fade-in" --> Dziedziczenie <code>class</code> po <code>struct</code> jest...?

  ```cpp
  struct A { int a; };
  class B : A {};
  int main() {
      B item;
      item.a = 5;
  }
  ```

  * <!-- .element: class="fragment fade-in" --> <a href="https://ideone.com/NCxKcA"><code>private</code></a>
  * <!-- .element: class="fragment fade-in" --> <code>error: ‘int A::a’ is inaccessible within this context</code>

___

## `private` czy `public`?

* <!-- .element: class="fragment fade-in" --> Dziedziczenie <code>struct</code> po <code>class</code> jest...?

  ```cpp
  class A {
  public:
      int a;
  };
  struct B : A {};

  int main() {
      B item;
      item.a = 5;
  }
  ```

  * <!-- .element: class="fragment fade-in" --> <a href="https://ideone.com/x46OvN"><code>public</code></a>

___

## Inheritance access modifiers

|                            |                    <code>public</code>                    |                  <code>protected</code>                   |                  <code>private</code>                   |
| :------------------------: | :-------------------------------------------------------: | :-------------------------------------------------------: | :-----------------------------------------------------: |
|  **<code>public</code>**   | public   <!-- .element style="background-color: #0a0;"--> | protected<!-- .element style="background-color: #da0;"--> | private<!-- .element style="background-color: #a00;"--> |
| **<code>protected</code>** | protected<!-- .element style="background-color: #da0;"--> | protected<!-- .element style="background-color: #da0;"--> | private<!-- .element style="background-color: #a00;"--> |
|  **<code>private</code>**  | private  <!-- .element style="background-color: #a00;"--> | private  <!-- .element style="background-color: #a00;"--> | private<!-- .element style="background-color: #a00;"--> |

___

## Problem diamentowy

```text
                            A               Animal
                           / \             /      \
                          B   C         Mammal   Fish
                           \ /             \      /
                            D               Dolphin
```

* <!-- .element: class="fragment fade-in" --> Deadly Diamond of Death
* <!-- .element: class="fragment fade-in" --> Wirtualne dziedziczenie
  * <!-- .element: class="fragment fade-in" --> <code>class B : virtual public A</code>
  * <!-- .element: class="fragment fade-in" --> <code>class C : virtual public A</code>
  * <!-- .element: class="fragment fade-in" --> <code class="fragment highlight-red">class D : virtual public B, virtual public C</code>
