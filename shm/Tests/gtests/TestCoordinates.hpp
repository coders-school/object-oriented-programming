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

TEST(Coordinates, Compare_equal_positions) {
    for (size_t i = 0; i < position.size(); ++i) {
        EXPECT_TRUE((position[i] == position2[i]));
    }
}

TEST(Coordinates, Compare_diffrent_positions) {
    for (size_t i = 0; i < position.size(); ++i) {
        for (size_t j = 0; j < position2.size(); ++j) {
            if (i == j) {
                continue;
            }
            EXPECT_TRUE(!(position[i] == position2[j]));
        }
    }
}

TEST(Coordinates, Distance_between_same_positions) {
    for (size_t i = 0; i < position.size(); ++i) {
        EXPECT_TRUE(Island::Position::distance(position[i], position2[i]) == 0);
    }
}

TEST(Coordinates, Distance_between_different_positions) {
    //horizontal
    EXPECT_TRUE(Island::Position::distance(position[0], position2[2]) == 10);
    EXPECT_TRUE(Island::Position::distance(position[1], position2[3]) == 10);
    EXPECT_TRUE(Island::Position::distance(position[4], position2[5]) == 5);
    //vertical
    EXPECT_TRUE(Island::Position::distance(position[0], position2[1]) == 10);
    EXPECT_TRUE(Island::Position::distance(position[2], position2[3]) == 10);
    //acros
    EXPECT_TRUE(Island::Position::distance(position[0], position2[6]) == 5);
}
