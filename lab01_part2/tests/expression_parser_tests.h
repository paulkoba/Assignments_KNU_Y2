//
// Created by fail on 9/30/21.
//

#ifndef LAB01_PART2_EXPRESSION_PARSER_TESTS_H
#define LAB01_PART2_EXPRESSION_PARSER_TESTS_H

#include "gtest/gtest.h"
#include "../expression_parser.h"

TEST(expression_parser, test_arithmetics) {
    auto r1 = expression_parser::infix_to_rpn("x^2 + x");
    ASSERT_NEAR(expression_parser::calculate(5, r1), 30, 1E-6);
    ASSERT_NEAR(expression_parser::calculate(0.5, r1), 0.75, 1E-6);

    auto r2 = expression_parser::infix_to_rpn("x^3");
    ASSERT_NEAR(expression_parser::calculate(0, r2), 0, 1E-6);
    ASSERT_NEAR(expression_parser::calculate(0.5, r2), 0.125, 1E-6);
}

#endif //LAB01_PART2_EXPRESSION_PARSER_TESTS_H
