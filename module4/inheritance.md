<!-- .slide: data-background="#111111" -->

# Inheritance

___

## Inheritance

* <!-- .element: class="fragment fade-in" --> Constructors and destructors call order
  * <!-- .element: class="fragment fade-in" --> Constructors - base class first, then derived
  * <!-- .element: class="fragment fade-in" --> <a href="https://ideone.com/Kgb46n">ideone.com</a>
* <!-- .element: class="fragment fade-in" --> Diamond problem
  * <!-- .element: class="fragment fade-in" --> virtual inheritance
* <!-- .element: class="fragment fade-in" --> <code>class</code> from <code>struct</code> inheritance is...
  * <!-- .element: class="fragment fade-in" --> <a href="https://ideone.com/Rdd6Uf"><code>private</code></a>
* <!-- .element: class="fragment fade-in" --> <code>struct</code> from <code>class</code> inheritance is...
  * <!-- .element: class="fragment fade-in" --> <a href="https://ideone.com/x46OvN"><code>public</code></a>

___

## Inheritance access modifiers

|                            |                    <code>public</code>                    |                  <code>protected</code>                   |                  <code>private</code>                   |
| :------------------------: | :-------------------------------------------------------: | :-------------------------------------------------------: | :-----------------------------------------------------: |
|  **<code>public</code>**   | public   <!-- .element style="background-color: #0a0;"--> | protected<!-- .element style="background-color: #da0;"--> | private<!-- .element style="background-color: #a00;"--> |
| **<code>protected</code>** | protected<!-- .element style="background-color: #da0;"--> | protected<!-- .element style="background-color: #da0;"--> | private<!-- .element style="background-color: #a00;"--> |
|  **<code>private</code>**  | private  <!-- .element style="background-color: #a00;"--> | private  <!-- .element style="background-color: #a00;"--> | private<!-- .element style="background-color: #a00;"--> |
