<!-- .slide: data-background="#111111" -->

# Programowanie obiektowe

## Hermetyzacja

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Hermetyzacja

Aby zabezpieczyć nasz obiekt, przez niepożądanymi modyfikacjami, możemy dokonać, tzw. hermetyzacji lub enkapsulacji.
<!-- .element: class="fragment fade-in" -->

Polega ona na umieszczeniu wszystkich właściwości (pól) w sekcji prywatnej, a ich modyfikacje umożliwiać przez publiczne funkcje.
<!-- .element: class="fragment fade-in" -->

___

## settery i gettery

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
std::string getName() const { return name_ }
```
<!-- .element: class="fragment fade-in" -->

Oczywiście nie zawsze musimy umożliwiać modyfikacje wszystkich zmiennych, tak samo, jak nie wszystkie zmienne mogą mieć swoje gettery. Wybór zależy od programisty.
<!-- .element: class="fragment fade-in" -->

___

## Q&A
