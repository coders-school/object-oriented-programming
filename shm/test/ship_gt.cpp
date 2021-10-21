#include "../ship.hpp"
#include "../time.hpp"
#include "../cargo.hpp"
#include "../alcohol.hpp"

#include "gtest/gtest.h"

#include <memory>
#include <vector>

struct ShipTest : public ::testing::Test
{
    size_t capacity{1000};
    size_t maxCrew{50};
    size_t crew{20};
    size_t speed{15};
    std::string name{"LoveShip"};
    size_t id{1};
    Time time;

    Ship ship = Ship(capacity, maxCrew, crew, speed, name, id, std::make_shared<Time>(time));
};

TEST_F(ShipTest, ShoulReturnCapacity)
{
    EXPECT_EQ(ship.getCapacity(), capacity);
}

TEST_F(ShipTest, ShouldChangeName)
{
    std::string newName = "Labamba";
    ship.setName(newName);
    EXPECT_EQ(ship.getName(), newName);
}

TEST_F(ShipTest, ShouldLoad)
{

    const size_t alcoholAmount = 50;
    std::shared_ptr<Alcohol> alcohol = std::make_shared<Alcohol>();
    auto cargos = ship.getCargosVector();

    EXPECT_FALSE(cargos.size() != 0);

    std::shared_ptr<Cargo> cargo = alcohol;
    ship.load(alcohol, alcoholAmount);

    EXPECT_EQ(ship.getCargo(0)->getAmount(), alcoholAmount);
}

TEST_F(ShipTest, ShouldUnload)
{
    const size_t alcoholAmount = 50;
    std::shared_ptr<Alcohol> alcohol = std::make_shared<Alcohol>();
    auto cargos = ship.getCargosVector();
    std::shared_ptr<Cargo> cargo = alcohol;
    ship.load(alcohol, alcoholAmount);
    
    EXPECT_FALSE(ship.getCargo(0)->getAmount() != alcoholAmount);

    ship.unload(alcohol, alcoholAmount);
    EXPECT_FALSE(cargos.size() != 0);
}