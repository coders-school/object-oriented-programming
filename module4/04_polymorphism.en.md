<!-- .slide: data-background="#111111" -->

# Polymorphism

___

## Polymorphism

* <!-- .element: class="fragment fade-in" --> Virtual functions
* <!-- .element: class="fragment fade-in" --> Pure virtual functions (<code>=0</code>)
* <!-- .element: class="fragment fade-in" --> Abstract classes
  * <!-- .element: class="fragment fade-in" --> have at least one pure virtual function
* <!-- .element: class="fragment fade-in" --> <code>vtable</code> and <code>vptr</code>
  * <!-- .element: class="fragment fade-in" --> implementation of polymorphism
  * <!-- .element: class="fragment fade-in" --> constructor of derived class overrides base class records in <code>vtable</code>
