<!-- .slide: data-background="#111111" -->

# Programowanie obiektowe

## Hermetyzacja

<a href="https://coders.school">
    <img width="500" src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Zabezpieczanie dostępu

Aby zabezpieczyć nasz obiekt, przed niepożądanymi modyfikacjami, możemy dokonać, tzw. <span class="fragment highlight-green">hermetyzacji</span> lub <span class="fragment highlight-green">enkapsulacji</span>.
<!-- .element: class="fragment fade-in" -->

Polega ona na umieszczeniu wszystkich właściwości (pól) w sekcji prywatnej, a ich modyfikacje umożliwiać przez publiczne funkcje.
<!-- .element: class="fragment fade-in" -->

___

### Settery i gettery

Najprostszymi funkcjami umożliwiającymi modyfikacje są tzw. settery.
<!-- .element: class="fragment fade-in" -->

Setter to funkcja, która przypisuje daną wartość konkretnej zmiennej.
<!-- .element: class="fragment fade-in" -->

```cpp
void setName(const std::string& name) { name_ = name; }
```
<!-- .element: class="fragment fade-in" -->

Ponieważ dane są prywatne, ich odczyt również nie jest możliwy, więc dokonujemy go przez tzw. gettery.
<!-- .element: class="fragment fade-in" -->

```cpp
std::string getName() const { return name_; }
```
<!-- .element: class="fragment fade-in" -->

Oczywiście nie zawsze musimy umożliwiać modyfikacje wszystkich zmiennych, tak samo, jak nie wszystkie zmienne mogą mieć swoje gettery. Wybór zależy od programisty.
<!-- .element: class="fragment fade-in" -->

___

### Nietrywialne przypisania

Jeśli w obiektach naszej klasy chcemy sprawdzać poprawność przypisywanych danych, to settery są wręcz obowiązkowe.
<!-- .element: class="fragment fade-in" -->

```cpp
void setValue(int newValue) {
    if (newValue >= 0 or newValue < 100) {
        value_ = newValue;
    } // otherwise no effect, could also signal an error
}
```
<!-- .element: class="fragment fade-in" -->

Gdyby pole `value_` było publiczne to taki warunek musielibyśmy sprawdzać w każdym miejscu, gdzie ustawiamy dane. Prościej jest po prostu zabronić bezpośredniego dostępu do `value_` poprzez uczynienie go prywatnym i utworzenie publicznego settera jak powyżej. Dzięki temu mamy pewność, że nikt nie ustawi wartości spoza oczekiwanego zakresu.
<!-- .element: class="fragment fade-in" -->

Jeśli nie potrzebujemy kontroli danych to łatwiej jest używać pól publicznych.
<!-- .element: class="fragment fade-in" -->

___

### `const`'owe gettery

Przypatrz się temu getterowi.
<!-- .element: class="fragment fade-in" -->

```cpp
std::string getName() const { return name_; }
```
<!-- .element: class="fragment fade-in" -->

Gdzie on ma `const`? Co to robi? 🤔
<!-- .element: class="fragment fade-in" -->

Odpowiemy na to pytanie po zadaniach 💻
<!-- .element: class="fragment fade-in" -->