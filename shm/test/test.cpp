#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch_amalgamated.hpp"
#include "../fruit.hpp"
#include "../item.hpp"
#include "../alcohol.hpp"
#include "../player.hpp"
#include "../Store.hpp"

SCENARIO("Checking cargo abilities")
{
    GIVEN("Cargos: alcohol, fruit and item")
    {
        std::vector<Cargo *> stodola;
        stodola.reserve(3);
        Time *time = new Time();
        Alcohol *alco = new Alcohol("VODKA", 1, 54, time, 69);
        Fruit *fruitzz = new Fruit("Mango", 10, 25, time, 17, 2);
        Item *itemix = new Item("FriiAjtem", 36, 69, time, Rarity::epic);

        stodola.push_back(alco);
        stodola.push_back(fruitzz);
        stodola.push_back(itemix);
        REQUIRE(stodola.size() == 3);
        WHEN("Checking getters from alcohol")
        {
            THEN("Percentage of alcohol should be 69")
            {
                auto percents = alco->getPercentage();
                CHECK(percents == 69);
            }
            THEN("Name of alcohol should be Vodka")
            {
                auto name = alco->getName();
                CHECK(name == "VODKA");
            }
        }
        WHEN("Checking getters from fruit")
        {
            THEN("Expiry_date from fruit should be equal to 17")
            {
                auto expiryTime = fruitzz->getExpiryDate();
                CHECK(expiryTime == 17);
            }
            THEN("TimeElapsed from fruit should be equal to 2")
            {
                auto timeEl = fruitzz->getTimeElapsed();
                CHECK(timeEl == 2);
            }
            THEN("Amount of fruit shoul be equal to 10")
            {
                auto amount = fruitzz->getAmount();
                CHECK(amount == 10);
            }
        }
        WHEN("Checking getters from item")
        {
            THEN("Baseprice for item should be 69")
            {
                auto basePrice = itemix->getBasePrice();
                CHECK(basePrice == 69);
            }
            THEN("Rarity for item should be EPIC!")
            {
                auto rarity = itemix->getRarity();
                CHECK(rarity == Rarity::epic);
            }
        }
    }
}
SCENARIO("Checking player and ship abilities")
{
    GIVEN("Player with ship")
    {
        Time *time_ = new Time;
        Player *playerOne_ = (new Player(std::make_unique<Ship>(20, 30, 10, "Dar Pomorza", 3, time_), 1000, 1000));
        WHEN("Name is set")
        {
            playerOne_->setName("kwik");
            THEN("Name of the player should be kwik")
            {
                auto name = playerOne_->getName();
                CHECK(name == "kwik");
            }
        }
        WHEN("Crew is set")
        {
            playerOne_->getShip()->setCrew(15);
            THEN("Cargo is added")
            {
                auto crew1 = playerOne_->getShip()->getCrew();
                CHECK(crew1 == 15);
            }
        }
    }
}
SCENARIO("Store!")
{
    GIVEN("Store and cargo")
    {
        Time *time_ = new Time;
        Store *sklep = new Store(100, 100, time_);
        Alcohol *alco = new Alcohol("VODKA", 1, 54, time_, 69);
        sklep->addStoreCargo(alco);
        WHEN("Adding new cargo")
        {
            sklep->addStoreCargo(alco);
            REQUIRE(sklep->storeCargo.size());
            THEN("Cargo should be alco")
            {
                auto voda = sklep->storeCargo[3];
                CHECK(voda->getName() == alco->getName());
            }
        }
    }
}

SCENARIO("Ship!")
{
    GIVEN("Ship with crew")
    {
        Time *time_ = new Time;
        Ship *ship = new Ship(10, 15, 5, "Pomorzanien", 4, time_);
        WHEN("Checking ship getters")
        {
            THEN("Capacity should be 10")
            {
                CHECK(ship->getCapacity() == 10);
            }
            THEN("Speed should be 5")
            {
                CHECK(ship->getSpeed() == 5);
            }
            THEN("Crew should be 15")
            {
                CHECK(ship->getCrew() == 15);
            }
            THEN("Name should be Pomorzanien")
            {
                CHECK(ship->getName() == "Pomorzanien");
            }
            THEN("Id should be 4")
            {
                CHECK(ship->getId() == 4);
            }
        }
        WHEN("Ship load Alcohol")
        {
            Alcohol *alco = new Alcohol("VODKA", 1, 54, time_, 69);
            ship->load(alco, 1);
            THEN("Should find alcohol")
            {
                CHECK(ship->findMatchCargo(alco));
            }
        }
    }
}