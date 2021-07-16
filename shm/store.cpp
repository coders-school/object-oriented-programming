#include "store.hpp"
#include "player.hpp"
#include "cargo.hpp"
#include "ship.hpp"

Store::Response Store::buy(Cargo *cargo, size_t amount, Player *player){
    // free space on Player ship_
    size_t getPlayerShipAmount = player->getAvailableSpace();
    if (getPlayerShipAmount <= amount)
    {
        return Response::lack_of_space;
    }
    auto addCargoSize = cargo->getAmount() + amount;
    if (getPlayerShipAmount <= addCargoSize)
    {
        return Response::lack_of_space;
    }

    auto ship = player->getShip();
    ship->getCargo();

    Response::lack_of_cargo; //// ????
    Response::lack_of_money;
    Response::done;
}
Store::Response Store::sell(Cargo *, size_t amount, Player *)
{

    return Response::done;
}