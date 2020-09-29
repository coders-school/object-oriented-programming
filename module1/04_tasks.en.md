<!-- .slide: data-background="#111111" -->

# Object oriented programming

## Exercises

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Exercise 1

Write a class `Ship` which will store the ship's data:

* `id_`
* `name_`
* `speed_`
* `maxCrew_`
* `capacity_`

The data should be private, and access to it should be through getters.

___

## Exercise 2

Add to class `Ship` constructors that will accept the appropriate data. There should be 3 constructors:

* The first one takes no arguments -> `id_` for such an object should be `-1`
* The second accepting all data
* Third takes `id`, `speed` and `maxCrew` (try to use the second constructor when writing the third one)

Additionally, add a method `void set_name(const std::string&)`.

___

## Exercise 3

Add to class `Ship`:

* variable `size_t crew_` specifying the current number of the ship's crew
* `Ship& operator+=(const int)` that will add the crew to the ship
* `Ship& operator-=(const int)` that will subtract it.

___

## Exercise 4

Create a class `Cargo`. It is supposed to represent 1 type of good on the ship. It will have 3 fields:

* `name_` - product name
* `amount_` - amount of stock
* `basePrice_` - the base price of the good

Then write in class `Cargo`:

* `Cargo& operator+=(const size_t)` that will add the specified quantity of the goods
* `Cargo& operator-=(const size_t)` which will subtract the given quantity of goods

Also consider how you will store goods on board.

___

## Q&A
