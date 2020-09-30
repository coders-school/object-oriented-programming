<!-- .slide: data-background="#111111" -->

# Object oriented programming

## Summary

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## What do you remember from today?

### Write as many keywords as possible in the chat
<!-- .element: class="fragment fade-in" -->

1. <!-- .element: class="fragment fade-in" --> Inheritance
2. <!-- .element: class="fragment fade-in" --> multi-inheritance
3. <!-- .element: class="fragment fade-in" --> virtual functions
4. <!-- .element: class="fragment fade-in" --> pure virtual functions
5. <!-- .element: class="fragment fade-in" --> abstract classes
6. <!-- .element: class="fragment fade-in" --> interfaces
7. <!-- .element: class="fragment fade-in" --> polymorphism
8. <!-- .element: class="fragment fade-in" --> static fields and methods

___

### Pre-work

* Find out what the diamond problem is
* Read about SOLID rules for writing good object-oriented code
* Reading about design patterns with examples in C++ - [refactoring.guru](https://refactoring.guru/design-patterns)
* Try Copy & Paste to add the cmake build system to your project. For this, have a look at the homework so far and the CMakeLists.txt file.

___

## Group project

Use the code written during the class. You can also use the code in the [solutions](solutions) directory

Group project - continuation. You can change the group if you want 🙂

___

## Organization of work

* How was your daily?
* Is Code Review neglected?
* Is the collaboration going smoothly?
* Do yourself a retrospective 🙂

___

### Punctation

* The first 3 tasks - 5 points
* tasks 4, 5, 6 - 8 points
* 20 points for all 6 items delivered before 05/07/2020 (Sunday) by 23:59
* no bonus points for delivering only some of the tasks before 05.07
* 6 points for group work for each person in the group.

___

## Task 1

Write a class `Store` that will allow you to make purchases. Use the enum and functions below.

```cpp
enum class Response {done, lack_of_money, lack_of_cargo, lack_of_space};

Response buy(Cargo* cargo, size_t amount, Player* player);
Response sell(Cargo* cargo, size_t amount, Player* player);
```

___

## Exercise 2

In classes `Alcohol`, `Fruit`, `Item` add the missing methods and their implementations.

```cpp
// override from Cargo
size_t getPrice() const override;
std::string getName() const override { return name_; }
size_t getAmount() const override { return amount_; }
size_t getBasePrice() const override { return base_price_; }
Cargo& operator+=(size_t amount) override;
Cargo& operator-=(size_t amount) override;
bool operator==(Cargo& cargo) const override;
```

___

## Exercise 3

Add to the class `Ship`, `Cargo` and `Store` method `nextDay()`

* Class `Ship`: The method should subtract 1 coin for each crew member.
* Class `Cargo`: The method should spoil the goods.
* Class `Store`: The method should change the quantity of goods in stores.

___

## Task 4 (for the ambitious)

Try to write a class `Time` which will be responsible for time management in the game.

This class should inform other classes, such as `Cargo`, `Ship`, `Store` about the expiry of each day.

Read about [`Observer`](https://refactoring.guru/design-patterns/observer) design pattern.

___

## Task 5 (for the ambitious)

Write a friend operator that writes out to stream

```cpp
friend std::ostream& operator<<(std::ostream& out, const Store& store);
```

It should write out the goods that are in a given store in an accessible way.

___

## Task 6 (for the ambitious)

Write a class `Game` that will manage the entire game.

Add to it public method `startGame()`.

Finally, the main file should look like this:

```cpp
#include "Game.hpp"

constexpr size_t start_money = 1'000;
constexpr size_t game_days = 100;
constexpr size_t final_goal = 2'000;

int main() {
    Game game(start_money, game_days, final_goal);
    game.startGame();

    return 0;
}
```
