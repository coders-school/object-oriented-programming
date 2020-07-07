#include "coordinates.hpp"

#include <string>
#include <typeinfo>

#include "gtest/gtest.h"

namespace {

class SHM_TestFixtureCoordinates : public ::testing::Test {
public:
    SHM_TestFixtureCoordinates() : coord_1(100, 100) {
        // initialization code here
    }

    void SetUp() {
        // code here will execute just before the test ensues
    }

    void TearDown() {
        // code here will be called just after the test completes
        // ok to through exceptions from here if need be
    }

    ~SHM_TestFixtureCoordinates() {
        // cleanup any pending stuff, but no exceptions allowed
    }

    // put in any custom data members that you need
    Coordinates coord_1;
};

TEST_F(SHM_TestFixtureCoordinates, TestOperatorEqual) {
    Coordinates coord_2(100, 100);
    Coordinates coord_3(0, 0);

    if (coord_1 == coord_2) {
        EXPECT_EQ(true, true);
    }
    if (coord_1 == coord_3) {
        EXPECT_EQ(false, true);
    }
}

}  // namespace
