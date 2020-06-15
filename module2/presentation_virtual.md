<!-- .slide: data-background="#111111" -->

# Programowanie obiektowe

## Metody wirtualne, interfejsy, klasy abstrakcyjne

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Metody czysto wirtualne

```cpp
class Bird {
public:
    size_t getWeight();
    size_t getHeight();
    size_t getName();

    // Pure virtual function without implementation
    virtual void eat() = 0;
    virtual void sleep() = 0;

protected:
    size_t weight_;
    size_t height_;
    std::string name_;
};
```

Metody `eat()` oraz `sleep()` to tzw. metody czysto wirtualne. Świadczy o tym `= 0;`. Oznacza to, że nigdzie nie znajdziemy ich implementacji dla klasy `Bird`. Klasy które dziedziczą po `Bird` będą ją musiały zaimplementować same.

___
<!-- .slide: style="font-size: 0.9em" -->

## Interfejsy

Jednym z pomysłów na rozwiązanie problemu wielodziedziczenia jest tworzenie tzw. interfejsów, ich dziedziczenie oraz przeciążanie implementacji metod z klas bazowych. Interfejsy określają "umiejętności" i łatwo je ze sobą łączyć.

```cpp
class Flyable {
public:
    virtual void fly() = 0;

private:
    Wings wings_;
};

class Swimmable {
public:
    virtual void swim() = 0;
};

class Soundable {
public:
    virtual void makeSound() = 0;
};
```

___

## Użycie interfejsów

```cpp
class Penguin : public Bird, public Swimmable {
public:
    // Override from Bird
    void eat() override;
    void sleep() override;

    // Override from Swimmable
    void swim() override;
};

class Hummingbird : public Bird,
                    public Flyable,
                    public Soundable {
public:
    // Override from Bird
    void eat() override;
    void sleep() override;

    // Override from Soundable
    void makeSound() override;

    // Override from Flyable
    void fly() override;
};

class Goose : public Bird,
              public Flyable,
              public Soundable,
              public Swimmable {
public:
    // Override from Bird
    void eat() override;
    void sleep() override;

    // Override from Soundable
    void makeSound() override;

    // Override from Flyable
    void fly() override;

    // Override from Swimmable
    void swim() override;
};
```

___

## Klasa abstrakcyjna

Nie można utworzyć obiektu klasy, która posiada <span class="fragment highlight-green">**co najmniej jedną czysto wirtualną**</span>.

Możemy przechowywać wskaźnik wskazujący na typ tej klasy, ale nie możemy stworzyć jej instancji, ponieważ nie mamy zdefiniowanych jej zachowań.

Klasa taka nazywa się  <span class="fragment highlight-green">**klasą abstrakcyjną**</span> i służy tylko do ujednolicania interfejsu, a nie tworzenia obiektów.

Dopiero obiekt klasy pochodnej, która zaimplementuje wszystkie brakujące metody, może zostać utworzona.

___

## Słowo `virtual` i `override`

Co to za słowa? Co one robią? O tym w kolejnej lekcji ;)

Zostawiamy was z tym niedopowiedzeniem, abyście sami zechcieli poszukać o tym informacji lub przejrzeli wideo pana Zelenta. `virtual` tam znajdziecie, ale `override` nie, bo to zbyt nowa rzecz, bo weszła 9 lat temu ;)

___

## Q&A
