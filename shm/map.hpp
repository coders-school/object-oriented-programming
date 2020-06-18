#pragma once

/*Napisz klasę Map, która będzie posiadała std::vector<Island>
przechowujący wszystkie wyspy na mapie, oraz zmienną
Island* currentPosition_ określającą aktualną pozycję gracza na mapie.

W klasie Map utwórz konstruktor bezargumentowy, a w jego ciele utwórz 10 wysp, które przechowasz w std::vector<Island>.
Do wygenerowania losowych wartości pozycji wysp na mapie skorzystaj z przykładu na cppreference.
Wymyśl sposób, aby pozycje wysp się nie powielały.

*/


class Map {

    public:

    Map();

    private:

    std::vector<Island> allIslands;
    Island* currentPosition_;



};
