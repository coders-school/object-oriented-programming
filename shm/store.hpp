#include <iostream>

class Player;
class Cargo;

class Store {
public:
    enum class Response { done,
                          lack_of_money,
                          lack_of_cargo,
                          lack_of_space };
                          
    Response buy(Cargo*, size_t amount, Player*);
    Response sell(Cargo*, size_t amount, Player*);
};