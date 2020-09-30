<!-- .slide: data-background="#111111" -->

# Dziedziczenie

___

## Dziedziczenie

* <!-- .element: class="fragment fade-in" --> Porządek wywoływania konstruktorów i destruktorów
  * <!-- .element: class="fragment fade-in" --> Konstruktory - najpierw klasa bazowa, potem pochodna
  * <!-- .element: class="fragment fade-in" --> <a href="https://ideone.com/Kgb46n">ideone.com</a>
* <!-- .element: class="fragment fade-in" --> Problem diamentowy
  * <!-- .element: class="fragment fade-in" --> dziedziczenie wirtualne
* <!-- .element: class="fragment fade-in" --> dziedziczenie <code>class</code> od <code>struct</code> jest ...
  * <!-- .element: class="fragment fade-in" --> <a href="https://ideone.com/Rdd6Uf"><code>private</code></a>
* <!-- .element: class="fragment fade-in" --> dziedziczenie <code>struct</code> od <code>class</code> jest ...
  * <!-- .element: class="fragment fade-in" --> <a href="https://ideone.com/x46OvN"><code>public</code></a>

___

## Modyfikatory dostępu do dziedziczenia

| |                    <code>public</code>                    |                  <code>protected</code>                   |                  <code>private</code>                   |
| : ------------------------: | : ------------------------------------------------- ------: | : ------------------------------------------------- ------: | : ------------------------------------------------- ----: |
|  **<code>public</code>**   | publiczny   <!-- .element style="background-color: #0a0;"--> | chroniony<!-- .element style="background-color: #da0;"--> | prywatny<!-- .element style="background-color: #a00;"--> |
| **<code>protected</code>** | chroniony<!-- .element style="background-color: #da0;"--> | chroniony<!-- .element style="background-color: #da0;"--> | prywatny<!-- .element style="background-color: #a00;"--> |
|  **<code>private</code>**  | prywatny  <!-- .element style="background-color: #a00;"--> | prywatny  <!-- .element style="background-color: #a00;"--> | prywatny<!-- .element style="background-color: #a00;"--> |
