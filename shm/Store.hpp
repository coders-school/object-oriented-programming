#include "Cargo.hpp"
#include "Player.hpp"

enum class Response {
    done,
    lack_of_money,
    lack_of_cargo,
    lack_of_space
};

class Store{
public:
    Response buy(std::shared_ptr<Cargo> cargo, size_t amount, Player* player);
    Response sell(std::shared_ptr<Cargo> cargo, size_t amount, Player* player);
};
