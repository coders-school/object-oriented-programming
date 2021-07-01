#pragma once

class Store {
public:
    Store();

    enum class Response {
        done, 
        lack_of_money, 
        lack_of_cargo, 
        lack_of_space
    };

private:

};