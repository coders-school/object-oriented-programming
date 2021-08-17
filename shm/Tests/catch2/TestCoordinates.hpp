#pragma once

#include "Island.hpp"
#include <array>

constexpr std::array position{
    Island::Position{0, 0},
    Island::Position{10, 0},
    Island::Position{0, 10},
    Island::Position{10, 10},
    Island::Position{5, 0},
    Island::Position{5, 5},
    Island::Position{3, 4}};

constexpr std::array position2{
    Island::Position{0, 0},
    Island::Position{10, 0},
    Island::Position{0, 10},
    Island::Position{10, 10},
    Island::Position{5, 0},
    Island::Position{5, 5},
    Island::Position{3, 4}};

//Island::Position tests

TEST_CASE("Compare equal positions", "[Position]") {
    for (size_t i = 0; i < position.size(); ++i) {
        REQUIRE((position[i] == position2[i]));
    }
}

TEST_CASE("Compare diffrent positions", "[Position]") {
    for (size_t i = 0; i < position.size(); ++i) {
        for (size_t j = 0; j < position2.size(); ++j) {
            if (i == j) {
                continue;
            }
            REQUIRE(!(position[i] == position2[j]));
        }
    }
}

TEST_CASE("Distance between same positions", "[Position]") {
    for (size_t i = 0; i < position.size(); ++i) {
        REQUIRE(Island::Position::distance(position[i], position2[i]) == 0);
    }
}

TEST_CASE("Distance between different positions", "[Position]") {
    //horizontal
    REQUIRE(Island::Position::distance(position[0], position2[2]) == 10);
    REQUIRE(Island::Position::distance(position[1], position2[3]) == 10);
    REQUIRE(Island::Position::distance(position[4], position2[5]) == 5);
    //vertical
    REQUIRE(Island::Position::distance(position[0], position2[1]) == 10);
    REQUIRE(Island::Position::distance(position[2], position2[3]) == 10);
    //acros
    REQUIRE(Island::Position::distance(position[0], position2[6]) == 5);
}
