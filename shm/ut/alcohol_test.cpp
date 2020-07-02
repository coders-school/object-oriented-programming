#include "alcohol.hpp"

#include <string>
#include <typeinfo>
#include "gtest/gtest.h"

namespace 
{
    
    const uint32_t AMOUNT_1 = 100;
    const uint32_t BASEPRICE_1 = 100;
    const uint32_t POWER_1 = 50;
    const std::string NAME_1 = "booze_1";
    

class SHM_TestFixtureAlco: public ::testing::Test {
public:
    SHM_TestFixtureAlco( ): alko_1(AMOUNT_1, NAME_1, BASEPRICE_1, POWER_1) {
        // initialization code here

    }

    void SetUp( ) {
        // code here will execute just before the test ensues
    }

    void TearDown( ) {
        // code here will be called just after the test completes
        // ok to through exceptions from here if need be
    }

    ~SHM_TestFixtureAlco( )  {
        // cleanup any pending stuff, but no exceptions allowed
    }

    // put in any custom data members that you need
    Alcohol alko_1;    
};


TEST_F(SHM_TestFixtureAlco, ShouldReturnInitializedName) {

    EXPECT_EQ("Alcohol " + NAME_1, alko_1.getName());
}

TEST_F(SHM_TestFixtureAlco, ShouldReturnInitializedAmount) {

    EXPECT_EQ(AMOUNT_1, alko_1.getAmount());
}

TEST_F(SHM_TestFixtureAlco, ShouldReturnInitializedBasePrice) {

    EXPECT_EQ(BASEPRICE_1, alko_1.getBasePrice());
}


TEST_F(SHM_TestFixtureAlco, CalcPriceNotGreaterThanBase) {

    EXPECT_GE(BASEPRICE_1, alko_1.getPrice());
}

TEST_F(SHM_TestFixtureAlco, ShouldReturnInitializedPower) {

    EXPECT_EQ(POWER_1, alko_1.getPower());
}

TEST_F(SHM_TestFixtureAlco, TestOperatorAddEqual) {

    alko_1 += 100;
    EXPECT_EQ(AMOUNT_1 + 100, alko_1.getAmount());
    alko_1 += 100;
    EXPECT_EQ(AMOUNT_1 + 200, alko_1.getAmount());
}

TEST_F(SHM_TestFixtureAlco, TestOperatorMinusEqual) {

    alko_1 -= 200;
    EXPECT_EQ(AMOUNT_1, alko_1.getAmount());
}

TEST_F(SHM_TestFixtureAlco, CannotGiveMoreThanHave) {

    alko_1 -= 20000;
    EXPECT_EQ(AMOUNT_1, alko_1.getAmount());
}

TEST_F(SHM_TestFixtureAlco, TestOperatorEqual) {

    Alcohol alko_2(AMOUNT_1, NAME_1, BASEPRICE_1, POWER_1) ;
    Alcohol alko_3(0, "wtf", 0, 0) ;

    if(alko_1 == alko_2){
        EXPECT_EQ(true, true);   
    }
    if(alko_1 == alko_3){
        EXPECT_EQ(false, true);
    }
}


} // namespace 
