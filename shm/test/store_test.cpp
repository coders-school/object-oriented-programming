#include "../inc/store.hpp"
#include "../inc/cargo.hpp"
#include "../inc/fruit.hpp"
#include "../inc/player.hpp"
#include "../inc/ship.hpp"

#include <iostream>

int main(void) {
  Cargo* ptr = nullptr;

  Fruit banan{"Banan", 20, 20, 2};
  Fruit gruszka{"Gruszka", 10, 10, 1};
  Fruit malina{"Malina", 50, 20, 5};
  Fruit melon{"Melon", 30, 30, 2};

  Fruit gruszka2{"Gruszka", 10, 10, 1};
  Fruit melon2{"Melon", 30, 30, 2};

  Ship Statek{500, 200, 20, "luizianna", 0};
  Player* Pionek = new Player{Statek, 15500, 900};
  Store sklep;
  std::cout << "PRINT STATEK: " << Statek.getAvailableSpace() << std::endl;

  sklep.addCargo(&banan);
  Pionek->addCargo(&gruszka);

  Store::Response response;

  //------------testing addCargo----------------//
  std::cout << "\nSklep Store: \n";
  std::cout << "Ilosc wonego miejsca (AvaiableSpace): "
            << sklep.getAvaiableSpace() << std::endl;
  sklep.printCargo();
  std::cout << "\n";

  std::cout << "\nShip Luizijana: \n";
  std::cout << "Ilosc wonego miejsca (AvaiableSpace): "
            << Pionek->getAvailableSpace() << std::endl;
  Pionek->printShipCargo();
  std::cout << "\n";

  std::cout << "----------Adding 50 malina to sklep------------" << std::endl;
  sklep.addCargo(&malina);
  sklep.addCargo(&gruszka2);
  sklep.addCargo(&melon2);
  std::cout << "----------Adding 30 melon to Luizijana------------"
            << std::endl;
  Pionek->addCargo(&melon);

  std::cout << "\nSklep Store: \n";
  std::cout << "Ilosc wonego miejsca (AvaiableSpace): "
            << sklep.getAvaiableSpace() << std::endl;
  sklep.printCargo();
  std::cout << "\n";

  std::cout << "\nShip Luizijana: \n";
  std::cout << "Ilosc wonego miejsca (AvaiableSpace): "
            << Pionek->getAvailableSpace() << std::endl;
  Pionek->printShipCargo();
  std::cout << "\n";
  //------------testing addCargo----------------//

  //------------testing Store.buy----------------//

  std::cout << "\n------------------STORE BUY--------------------------\n";
  std::cout << "\nSklep Store: \n";
  std::cout << "Ilosc wonego miejsca (AvaiableSpace): "
            << sklep.getAvaiableSpace() << "/1000" << std::endl;
  sklep.printCargo();
  std::cout << "\n";

  std::cout << "\nShip Luizijana: \n";
  std::cout << "Ilosc wonego miejsca (AvaiableSpace): "
            << Pionek->getAvailableSpace() << "/500" << std::endl;
  Pionek->printShipCargo();
  std::cout << "\n";

  std::cout << "----------Player buying 20 Malina------------" << std::endl;
  response = sklep.buy(sklep.getCargo("Malina"), 20, Pionek);
  sklep.printResponseMessage(response);
  std::cout << "----------Player buying 15 Melon------------" << std::endl;
  response = sklep.buy(sklep.getCargo("Melon"), 15, Pionek);
  sklep.printResponseMessage(response);

  std::cout << "\nSklep Store: \n";
  std::cout << "Ilosc wonego miejsca (AvaiableSpace): "
            << sklep.getAvaiableSpace() << "/1000" << std::endl;
  sklep.printCargo();
  std::cout << "\n";

  std::cout << "\nShip Luizijana: \n";
  std::cout << "Ilosc wonego miejsca (AvaiableSpace): "
            << Pionek->getAvailableSpace() << "/500" << std::endl;
  Pionek->printShipCargo();
  std::cout << "\n";
  std::cout << "\n------------------STORE BUY--------------------------\n";
  //------------testing Store.buy----------------//

  //------------testing Store.sell----------------//

  std::cout << "\n------------------STORE SELL--------------------------\n";
  std::cout << "\nSklep Store: \n";
  std::cout << "Ilosc wonego miejsca (AvaiableSpace): "
            << sklep.getAvaiableSpace() << "/1000" << std::endl;
  sklep.printCargo();
  std::cout << "\n";

  std::cout << "\nShip Luizijana: \n";
  std::cout << "Ilosc wonego miejsca (AvaiableSpace): "
            << Pionek->getAvailableSpace() << "/500" << std::endl;
  Pionek->printShipCargo();
  std::cout << "\n";

  std::cout << "----------Player selling 5 Gruszka------------" << std::endl;
  response = sklep.sell(Pionek->getCargo("Gruszka"), 5, Pionek);
  sklep.printResponseMessage(response);
  std::cout << "----------Player selling 20 Mellons------------" << std::endl;
  response = sklep.sell(Pionek->getCargo("Melon"), 20, Pionek);
  sklep.printResponseMessage(response);

  std::cout << "\nSklep Store: \n";
  std::cout << "Ilosc wonego miejsca (AvaiableSpace): "
            << sklep.getAvaiableSpace() << "/1000" << std::endl;
  sklep.printCargo();
  std::cout << "\n";

  std::cout << "\nShip Luizijana: \n";
  std::cout << "Ilosc wonego miejsca (AvaiableSpace): "
            << Pionek->getAvailableSpace() << "/500" << std::endl;
  Pionek->printShipCargo();
  std::cout << "\n";
  std::cout << "\n------------------STORE SELL--------------------------\n";
  //------------testing Store.sell----------------//

  return 0;
}
