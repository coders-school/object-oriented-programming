<!-- .slide: data-background="#111111" -->

# Polimorfizm

___

## Polimorfizm

* <!-- .element: class="fragment fade-in" --> Funkcje wirtualne
* <!-- .element: class="fragment fade-in" --> funkcje czysto wirtualne (<code>=0</code>)
* <!-- .element: class="fragment fade-in" --> Klasy abstrakcyjne
  * <!-- .element: class="fragment fade-in" --> mają co najmniej jedną funkcję czysto wirtualną
* <!-- .element: class="fragment fade-in" --> <code>vtable</code> i <code>vptr</code>
  * <!-- .element: class="fragment fade-in" --> implementacja polimorfizmu
  * <!-- .element: class="fragment fade-in" --> Konstruktor klasy pochodnej przesłania rekordy klasy bazowej w <code>vtable</code>
