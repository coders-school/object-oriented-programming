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

1. <!-- .element: class="fragment fade-in" --> class
2. <!-- .element: class="fragment fade-in" --> objects
3. <!-- .element: class="fragment fade-in" --> fields, properties
4. <!-- .element: class="fragment fade-in" --> methods, functions of the class
5. <!-- .element: class="fragment fade-in" --> access modifiers - <code>public</code>, <code>private</code>
6. <!-- .element: class="fragment fade-in" --> constructors
7. <!-- .element: class="fragment fade-in" --> destructors
8. <!-- .element: class="fragment fade-in" --> hermetization
9. <!-- .element: class="fragment fade-in" --> getters
10. <!-- .element: class="fragment fade-in" --> setters

___

### Pre-work

* Read and watch videos on inheritance and polymorphism

___

## Group project

Use the code written during the class. You can also use the code in the [solutions](solutions) directory

Group project. Recommended groups of 5 (4-6 are also ok).

Make a Fork of this repo and the whole project is going to be in the [shm](../shm) directory

Collaborate on one fork with a branch or Pull Requests from your own forks.

___

## Organization of work

To divide tasks and track your status, you can use the [Projects on GitHub](https://github.com/coders-school/object-oriented-programming/projects) tab. You can configure it from the Automated kanban with reviews template.

### Planning

Begin with planning where you create cards for each task in the To Do column. It's best to convert them to Issues. Thanks to this, you can assign to tasks and write comments in them. Also write for each task how many days of work you estimate it for. After finishing planning, please send a link to the `#planning` channel to your project board on GitHub.

### Daily

Update your tasks as you work. Synchronize at the same time every day and talk about the problems.

___

### Code Review

Each task delivery must be preceded by a Code Review by another person from the team (or preferably several) to maintain consistency and cooperation.

### Completion

This project will be developed even further. We expect that, regardless of the number of completed tasks, you will do a Pull Request before June 28 (in Scrum, the team decides how many tasks they can do for a specific date).

___

### Punctation

* Each delivered task is worth 5 points
* 20 points for all 8 tasks delivered before 6/28/2020 (Sunday) by 11:59 PM
* no bonus points for delivering only part of tasks before 28/06.
* 6 points for group work for each person in the group.

___

## Task 1

In class `Cargo` write the comparison operator (`operator==`), which will check if the goods are the same.

___

## Exercise 2

Add getters to the class `Cargo` and an appropriate constructor that will fill all the fields of this class.

___

## Exercise 3

Write a class `Island` which will hold the variable `Coordinates position_` and the appropriate getter.

`Coordinates` class has to determine the coordinates on the map. Write it as well. It should take 2 parameters in the constructor `positionX`, `positionY` and the comparison operator.
<!-- Klasa `Island` powinna posiadać także sklep. -->

___

## Task 4

Write a class `Map` that will have `std::vector<Island>` which stores all the islands on the map, and a variable `Island* currentPosition_` determining the current position of the player on the map.

___

## Task 5

In class `Map` create an argumentless constructor and create 10 islands in its body that you store in `std::vector<Island>`.
To generate random values ​​for the position of the islands on the map use this [example on cppreference](https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution).
Find a way to prevent the positions of the islands from duplicating.

___

## Task 6

In class `Map` write function

`Island* getIsland(const Island::Coordinates& coordinate)`

It should search `std::vector<Island>` and return the island you are looking for.

___

## Task 7

Write a class `Player` which will have 3 fields:

* `std::shared_ptr<Ship> ship_` (for those willing, try to use `std::unique_ptr<>`)
* `money_`
* `availableSpace_`

Also add the appropriate getters and constructor.

Also add 2 functions that should return ship data:

* `size_t getSpeed() const`
* `Cargo* getCargo(size_t index) const`

___

## Task 8

In class `Player` write a private function that will calculate `availableSpace_` based on the current quantity of goods on board.
