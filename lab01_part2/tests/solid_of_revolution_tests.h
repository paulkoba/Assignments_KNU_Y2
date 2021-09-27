//
// Created by fail on 9/28/21.
//

#ifndef LAB01_PART2_SOLID_OF_REVOLUTION_TESTS_H
#define LAB01_PART2_SOLID_OF_REVOLUTION_TESTS_H

#include "gtest/gtest.h"
#include "../solid_of_revolution.h"

double fun(double a) {
    return std::pow(a, 3);
}

TEST(solid_of_revolution, create_from_function) {
    solid_of_revolution solid(0, 3, 100, fun);

    ASSERT_NEAR(solid.get_volume(), 981.5, 15.);
    ASSERT_NEAR(solid.get_surface(), 4585., 15.);
}

TEST(solid_of_revolution, create_from_data) {
    solid_of_revolution solid({{0, 0}, {0.5, 0.125}, {1, 1}, {1.5, 3.375}, {2, 8}, {2.5, 15.625}, {3, 27}});

    ASSERT_NEAR(solid.get_volume(), 981.5, 15.);
    ASSERT_NEAR(solid.get_surface(), 4585., 15.);
}

TEST(solid_of_revolution, collision_check) {
    solid_of_revolution solid(0, 3, 100, fun);

    ASSERT_FALSE(solid.is_inside(1, 1, 1));
    ASSERT_TRUE(solid.is_inside(2, 1, 1));
}

#endif //LAB01_PART2_SOLID_OF_REVOLUTION_TESTS_H
