<!-- .slide: data-background="#111111" -->

# Programowanie obiektowe

## Modyfikatory dostępu

<a href="https://coders.school">
    <img width="500" src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

### Analogia

W większości sytuacji nie chcemy, aby ktoś nam grzebał w polach naszej klasy.
<!-- .element: class="fragment fade-in" -->

Wyobraź sobie, że inni widzą Twoje wnętrzności i mają do nich dostęp. Masz otwarty brzuch. Ktoś może w każdej chwili wyjąć Ci serce. To mało komfortowa sytuacja.
<!-- .element: class="fragment fade-in" -->

Wszystko jest zamknięte wewnątrz, a najważniejsze narządy chroni klatka piersiowa. W programowaniu obiektowym powiemy, że dostęp do narządów wewnętrznych jest prywatny 😉.
<!-- .element: class="fragment fade-in" -->

Nie zgadzamy się, aby ktoś miał dostęp naszych narządów wewnętrznych, ale nie mamy natomiast nic przeciwko temu, żeby ktoś miał dostęp do naszych rąk. Może nam wtedy np. wetknąć w nie pieniądze 💵. Przemilczmy kwestię innych narządów i tego czy zgadzamy się żeby ktoś ich używał 😈
<!-- .element: class="fragment fade-in" -->

To co jest dostępne dla innych ma dostęp publiczny. Jest to też tzw. interfejs klasy.
<!-- .element: class="fragment fade-in" -->

___

### `private` vs `public`

```cpp
class Computer {
private:
    void restart();
};

Computer computer;
computer.restart(); // Forbidden, restart is a private member
```
<!-- .element: class="fragment fade-in" -->

```cpp
class Computer {
public:
    void restart();
};

Computer computer;
computer.restart(); // Ok
```
<!-- .element: class="fragment fade-in" -->

___

### `private` vs `public`

```cpp
class Computer {
public:
    void reboot() { restart(); }
private:
    void restart();
};

Computer computer;
computer.restart(); // Forbidden, restart is a private member
computer.reboot();  // Ok, calls restart
```
<!-- .element: class="fragment fade-in" -->

___

### Modyfikator dostępu `protected`

Istnieje jeszcze jeden modyfikator dostępu w C++ - `protected`.

O nim opowiemy sobie, gdy już wyjaśnimy czym jest dziedziczenie.
