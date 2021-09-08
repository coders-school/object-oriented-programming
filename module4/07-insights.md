<!-- .slide: data-background="#111111" -->

# 🎭 Co siedzi pod maską?

___

## Układ klas w pamięci

* użycie słowa <code>virtual</code> powoduje wygenerowanie dodatkowego pola <code>vptr</code> oraz zaalokowania na stercie <code>vtable</code>

```cpp
class A {
    virtual void f();
    virtual void g();
    virtual ~A();
    int a;
    double b;
};
```

```text
stos:   | *vptr | int a | double b |
            |
            V
sterta: | void (*f)() | void (*g)() | destructor |
                 |             |           |
                 V             V           V
               A::f          A::g        A::~()
```

___

## Układ klas w pamięci

```cpp
class A { int a; };
class B : public A { int b; };
class C : public A { int c; };
class D : public B, public C { int d; };
```

```text
| int a | int b | int a | int c | int d |
^-------^       ^-------^
    A               A
^---------------^---------------^
        B               C
^---------------------------------------^
                  D
```

___

## Układ klas w pamięci

### Dziedziczenie wirtualne

* użycie wirtualnego dziedziczenie powoduje, że będzie tylko jedna instancja obiektu klasy bazowej

```cpp
class A { int a; };
class B : public virtual A { int b; };
class C : public virtual A { int c; };
class D : public B, public C { int d; };
```

```text
| int a | int b | int c | int d |
^-------^-------^-------^
    A       B       C
^-------------------------------^
                  D
```

___

## Name mangling

* <!-- .element: class="fragment fade-in" --> overloading = name mangling
* <!-- .element: class="fragment fade-in" --> <code>c++filt</code> odkodowuje nazwy symboli
  * <code>f()</code> -> <code>_Z1fv</code>
  * <code>f(int a, double b)</code> -> <code>_Z1fid</code>
* <!-- .element: class="fragment fade-in" --> Zobacz w <a href="https://godbolt.org">godbolt.org</a>

___

## Metody

* <!-- .element: class="fragment fade-in" --> metody to funkcje z ukrytym argumentem - wskaźnik <code>this</code>
* <!-- .element: class="fragment fade-in" --> metody <code>const</code> to po prostu wskaźnik <code>this</code> na stały obiekt klasy

```cpp
class Ex {
    int a;
public:
    void setA(int aa);
    int getA() const;
};
```
<!-- .element: class="fragment fade-in" -->

```cpp
class Ex {
    int a;
}
void setA(Ex* this, int aa);
int getA(const Ex* this);
```
<!-- .element: class="fragment fade-in" -->
