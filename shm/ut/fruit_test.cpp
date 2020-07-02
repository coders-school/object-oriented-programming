#include "fruit.hpp"

#include <string>
#include <typeinfo>
#include "gtest/gtest.h"

namespace 
{
    
const uint32_t AMOUNT_1 = 100;
const uint32_t BASEPRICE_1 = 100;
const uint32_t EXPIRY_1 = 50;
const std::string NAME_1 = "fruit_1";
    

class SHM_TestFixtureFruit: public ::testing::Test {
public:
    SHM_TestFixtureFruit( ): fruit_1(AMOUNT_1, NAME_1, BASEPRICE_1, EXPIRY_1)
    {
        // initialization code here

    }

    void SetUp( ) {
        // code here will execute just before the test ensues
    }

    void TearDown( ) {
        // code here will be called just after the test completes
        // ok to through exceptions from here if need be
    }

    ~SHM_TestFixtureFruit( )  {
        // cleanup any pending stuff, but no exceptions allowed
    }

    // put in any custom data members that you need
    Fruit fruit_1;    
};


TEST_F(SHM_TestFixtureFruit, ShouldReturnInitializedName) {

    EXPECT_EQ("Fruit " + NAME_1, fruit_1.getName());
}

TEST_F(SHM_TestFixtureFruit, ShouldReturnInitializedAmount) {

    EXPECT_EQ(AMOUNT_1, fruit_1.getAmount());
}

TEST_F(SHM_TestFixtureFruit, ShouldReturnInitializedBasePrice) {

    EXPECT_EQ(BASEPRICE_1, fruit_1.getBasePrice());
}


TEST_F(SHM_TestFixtureFruit, CalcPriceNotGreaterThanBase) {

    EXPECT_GE(BASEPRICE_1, fruit_1.getPrice());
}

TEST_F(SHM_TestFixtureFruit, ShouldReturnInitializedExpiryDate) {

    EXPECT_EQ(EXPIRY_1, fruit_1.getExpiryDate());
}

TEST_F(SHM_TestFixtureFruit, TestOperatorFrontMinusMinus) {

    --fruit_1;
    EXPECT_EQ(EXPIRY_1-1, fruit_1.getExpiryDate());
}

TEST_F(SHM_TestFixtureFruit, TestOperatorAddEqual) {

    fruit_1 += 100;
    EXPECT_EQ(AMOUNT_1 + 100, fruit_1.getAmount());
}


TEST_F(SHM_TestFixtureFruit, TestOperatorMinusEqual) {

    fruit_1 -= 10;
    EXPECT_EQ(AMOUNT_1-10, fruit_1.getAmount());
}

TEST_F(SHM_TestFixtureFruit, CannotGiveMoreThanHave) {

    fruit_1 -= 20000;
    EXPECT_EQ(AMOUNT_1, fruit_1.getAmount());
}

TEST_F(SHM_TestFixtureFruit, TestOperatorEqual) {

    Fruit fruit_2(AMOUNT_1, NAME_1, BASEPRICE_1, EXPIRY_1);
    Fruit fruit_3(0, "wtf", 0, 0);
    

    if(fruit_1 == fruit_2){
        EXPECT_EQ(true, true);   
    }
    if(fruit_1 == fruit_3){
        EXPECT_EQ(false, true);
    }
}


} // namespace 
