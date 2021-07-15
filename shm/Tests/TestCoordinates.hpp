#pragma once

#include "../Island.hpp"
#include <array>

constexpr std::array coords{
    Island::Coordinates{0, 0},
    Island::Coordinates{10, 0},
    Island::Coordinates{0, 10},
    Island::Coordinates{10, 10},
    Island::Coordinates{5, 0},
    Island::Coordinates{5, 5},
    Island::Coordinates{3, 4}};

constexpr std::array coords2{
    Island::Coordinates{0, 0},
    Island::Coordinates{10, 0},
    Island::Coordinates{0, 10},
    Island::Coordinates{10, 10},
    Island::Coordinates{5, 0},
    Island::Coordinates{5, 5},
    Island::Coordinates{3, 4}};

//Island::Coordinates tests

TEST_CASE("Compare equal coordinates", "[Coordinates]") {
    for (size_t i = 0; i < coords.size(); ++i) {
        REQUIRE((coords[i] == coords2[i]));
    }
}

TEST_CASE("Compare diffrent coordinates", "[Coordinates]") {
    for (size_t i = 0; i < coords.size(); ++i) {
        for (size_t j = 0; j < coords2.size(); ++j) {
            if (i == j) {
                continue;
            }
            REQUIRE(!(coords[i] == coords2[j]));
        }
    }
}

TEST_CASE("equal coordinates distance", "[Coordinates]") {
    for (size_t i = 0; i < coords.size(); ++i) {
        REQUIRE(Island::Coordinates::distance(coords[i], coords2[i]) == 0);
    }
}

TEST_CASE("diffrent coordinates distance", "[Coordinates]") {
    //horizontal
    REQUIRE(Island::Coordinates::distance(coords[0], coords2[2]) == 10);
    REQUIRE(Island::Coordinates::distance(coords[1], coords2[3]) == 10);
    REQUIRE(Island::Coordinates::distance(coords[4], coords2[5]) == 5);
    //vertical
    REQUIRE(Island::Coordinates::distance(coords[0], coords2[1]) == 10);
    REQUIRE(Island::Coordinates::distance(coords[2], coords2[3]) == 10);
    //acros
    REQUIRE(Island::Coordinates::distance(coords[0], coords2[6]) == 5);
}
