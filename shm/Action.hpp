#ifndef ACTION_HPP
#define ACTION_HPP
#include <iostream>

enum class Action {
    buy,
    sell,
    travel
};

void operator>>(std::istream& is, Action& action){
            int tmp;
            if (is >> tmp)
                action = static_cast<Action>(tmp);
            return;}
#endif