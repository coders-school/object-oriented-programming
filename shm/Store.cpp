#include "Store.hpp"

#include "Cargo.hpp"
#include "Player.hpp"

Store::Response Store::Buy(Cargo* cargo, size_t amount, Player* player) {
    if (player->getAvailableSpace() < amount)
        return Response::lack_of_space;
    return Response::done;
};
