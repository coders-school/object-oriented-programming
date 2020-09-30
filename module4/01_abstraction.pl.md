<!-- .slide: data-background="#111111" -->

# Abstrakcja

___

## Abstrakcja

* <!-- .element: class="fragment fade-in" --> Interfejs
  * <!-- .element: class="fragment fade-in" --> Publiczna część klasy
    * <!-- .element: class="fragment fade-in" --> Metody klasy
    * <!-- .element: class="fragment fade-in" --> Funkcje niebędące składowymi klasy
    * <!-- .element: class="fragment fade-in" --> Typy klasy
    * <!-- .element: class="fragment fade-in" --> Pola klasy
    * <!-- .element: class="fragment fade-in" --> Parametry szablonu
    * <!-- .element: class="fragment fade-in" --> Specjalizacje
  * <!-- .element: class="fragment fade-in" --> Przykład: <a href="https://en.cppreference.com/w/cpp/container/vector"><code>std::vector</code> na cppreference.com</a>
  * <!-- .element: class="fragment fade-in" --> Część prywatna (implementacja) jest nieznana
* <!-- .element: class="fragment fade-in" --> Projektowanie zorientowane obiektowo (OOD - Object Oriented Design)

> Make interfaces easy to use correctly and hard to use incorrectly
>
> \ - \ - Scott Meyers, [Efektywne C ++](https://blog.ycshao.com/2012/11/23/effective-c-item-18-make-interfaces-easy-to-use-correctly-and-hard-to-use-incorrectly/)
<!-- .element: class="fragment fade-in" -->

___

## Zły przykład interfejsu

```c++
// A date class which is easy to use but also easy to use wrong.
class Date {
    public:
        Date(int month, int day, int year);
        ...
};

// Both are ok, but some european programmer may use it wrong,
// because european time format is dd/mm/yyyy instead of mm/dd/yyyy.
Date d(3, 4, 2000);
Date d(4, 3, 2000);
```
