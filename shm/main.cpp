#include "cargo.hpp"
//#include "fruit.hpp"
#include "player.hpp"
#include "item.hpp"
#include "map.hpp"
#include "ship.hpp"
#include "store.hpp"
#include "time.hpp"

#include <iostream>
#include <memory>
#include <string>

int main() {

    Time gameTime;

    Ship blackPearl(200, 50, 180, "black pearl", 1, &gameTime);
    std::shared_ptr<Ship> ptr = std::make_shared<Ship>(200, 50, 180, "black pearl", 1, &gameTime);

    Player pawellos(ptr, 300, 70);

    Map gameMap(&gameTime);


    Store biedronka(&gameTime);
    std::cout << "\n\nFIRST CARGO\n\n";

    biedronka.generateCargo();
    biedronka.printCargo();


    std::cout << "\n\nSECOND CARGO\n\n";

    biedronka.generateCargo();
    biedronka.printCargo();

    std::cout << "\n\nTHIRD CARGO\n\n";

    biedronka.generateCargo();
    biedronka.printCargo();

    std::cout << "\n\nWITHOUT GENERATE CARGO\n\n";

    biedronka.printCargo();

    std::cout << "\n\nGAMETIME++ CARGO\n\n";

    ++gameTime;
    biedronka.printCargo();



    /*
    std::cout << "---------Before sell------ \n\n";
    pawellos.getShip()->printCargo();
    std::cout << "Money of player: " << pawellos.getMoney() << '\n';
    std::cout << "Available place on ship: " << pawellos.getAvailableSpace() << '\n';
    biedronka.printCargo();
    biedronka.sell(pawellos.getCargo(1), 3, &pawellos);
    biedronka.sell(pawellos.getCargo(2), 2, &pawellos);
    std::cout << "---------After sell------ \n\n";
    pawellos.getShip()->printCargo();
    std::cout << "Money of player: " << pawellos.getMoney() << '\n';
    std::cout << "Available place on ship: " << pawellos.getAvailableSpace() << '\n';
    biedronka.printCargo(); */

    std::cout << "\n**************\n";


}
