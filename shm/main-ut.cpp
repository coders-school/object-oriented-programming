#include<iostream>
#include "Alcohol.hpp"
#include <gtest/gtest.h>

TEST(TestCountPositives, BasicTest)
{
    //Arrange
    Alcohol vodka("vodka",100, 20, 96);

    //Act
    vodka+=100;

    //Assert
    ASSERT_EQ(200, vodka.getAmount());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}