#include "cargo.hpp"
//#include "fruit.hpp"
#include "player.hpp"
#include "ship.hpp"
#include "store.hpp"

int main() {
	Ship blackPearl(200, 50, 180, "black pearl", 1);
	std::shared_ptr<Ship> ptr = std::make_shared<Ship>(200, 50, 180, "black pearl", 1);

	Player pawellos(ptr, 300, 70);
	std::cout << pawellos.getMoney() << "\n";
	std::cout << pawellos.getAvailableSpace() << "\n";
	std::cout << pawellos.getSpeed() << "\n";
	std::cout << pawellos.getShip()->getName() << "\n";
	/* std::cout << blackPearl.getName() << "\n";
	std::cout << blackPearl.getId() << "\n";
	std::cout << blackPearl.getMaxCrew() << "\n";
	std::cout << blackPearl.getCapacity() << "\n \n";

	std::cout << blackPearl.getCrew() << "\n";
	blackPearl += 6;
	std::cout << blackPearl.getCrew() << "\n";
	blackPearl -= 3;
	std::cout << blackPearl.getCrew() << "\n";
	blackPearl -= 8;
	std::cout << blackPearl.getCrew() << "\n";
	*/

	Cargo Chocolate(5, "milka", 3);
	Cargo IceCream(6, "scholler", 8);

	std::shared_ptr<Cargo> ptrCargo1 = std::make_shared<Cargo>(Chocolate);
	std::shared_ptr<Cargo> ptrCargo2 = std::make_shared<Cargo>(IceCream);
	
	pawellos.getShip()->load(ptrCargo1);
	pawellos.getShip()->load(ptrCargo2);
	std::cout << "---------Before buy------ \n\n";
	pawellos.getShip()->printCargo();
	std::cout << "Money of player: " << pawellos.getMoney() << '\n';
	std::cout << "Available place on ship: " << pawellos.getAvailableSpace() << '\n';
	Store biedronka;
	biedronka.generateCargo();
	biedronka.printCargo();
	std::cout << "---------After buy------ \n\n";
	Player* ptrPlayer = &pawellos;
	biedronka.buy(biedronka.getCargo(0), 2, ptrPlayer);
	biedronka.buy(biedronka.getCargo(2), 8, ptrPlayer);
	biedronka.buy(biedronka.getCargo(1), 19, ptrPlayer);
	biedronka.buy(biedronka.getCargo(1), 190, ptrPlayer);
	pawellos.getShip()->printCargo();
	std::cout << "Money of player: " << pawellos.getMoney() << '\n';;
	std::cout << "Available place on ship: " << pawellos.getAvailableSpace() << '\n';
	biedronka.printCargo();
	
    return 0;
}
