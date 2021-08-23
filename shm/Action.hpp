#ifndef ACTION_HPP
#define ACTION_HPP
#include <iostream>

enum class Action {
    buy = 1,
    sell = 2,
    travel = 3,
    options = 9,
    exit = 10
};

/* void operator>>(std::istream& is, Action& action){
            int tmp;
            if (is >> tmp)
                action = static_cast<Action>(tmp);
            return;} */
#endif