<!-- .slide: data-background="#111111" -->

# Polimorfizm

___

## Polimorfizm

* <!-- .element: class="fragment fade-in" --> Funkcje wirtualne
* <!-- .element: class="fragment fade-in" --> Funkcje czysto wirtualne (<code>=0</code>)
* <!-- .element: class="fragment fade-in" --> Klasy abstrakcyjne
  * <!-- .element: class="fragment fade-in" --> mają co najmniej jedną funkcję czysto wirtualną
* <!-- .element: class="fragment fade-in" --> <code>vtable</code> and <code>vptr</code>
  * <!-- .element: class="fragment fade-in" --> implementacja polimorfizmu w C++
  * <!-- .element: class="fragment fade-in" --> konstruktor klasy pochodnej nadpisuje wskaźniki na funkcje klas bazowych w <code>vtable</code>
