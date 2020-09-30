<!-- .slide: data-background="#111111" -->

# Abstraction

___

## Abstraction

* <!-- .element: class="fragment fade-in" --> Interface
  * <!-- .element: class="fragment fade-in" --> The public part of a class
    * <!-- .element: class="fragment fade-in" --> Member function - obvious
    * <!-- .element: class="fragment fade-in" --> Non-member function
    * <!-- .element: class="fragment fade-in" --> Member types
    * <!-- .element: class="fragment fade-in" --> Member fields
    * <!-- .element: class="fragment fade-in" --> Template parameters
    * <!-- .element: class="fragment fade-in" --> Specializations
  * <!-- .element: class="fragment fade-in" --> Example: <a href="https://en.cppreference.com/w/cpp/container/vector"><code>std::vector</code> on cppreference.com</a>
  * <!-- .element: class="fragment fade-in" --> The private part (implementation) is unknown
* <!-- .element: class="fragment fade-in" --> Object Oriented Design (OOD)

> Make interfaces easy to use correctly and hard to use incorrectly
>
> \-\- Scott Meyers, [Effective C++](https://blog.ycshao.com/2012/11/23/effective-c-item-18-make-interfaces-easy-to-use-correctly-and-hard-to-use-incorrectly/)
<!-- .element: class="fragment fade-in" -->

___

## Bad interface example

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
