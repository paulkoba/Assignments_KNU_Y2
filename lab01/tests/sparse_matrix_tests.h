//
// Created by fail on 9/27/21.
//

#ifndef LAB01_SPARSE_MATRIX_TESTS_H
#define LAB01_SPARSE_MATRIX_TESTS_H

#include "gtest/gtest.h"
#include "../include/sparse_matrix.h"

TEST(sparse_matrix_tests, access_test) {
    sparse_matrix<double> sparse(3, 2);
    sparse[{2,1}] = 5;

    ASSERT_EQ((sparse[{2,1}]), 5);
    ASSERT_EQ((sparse[{2,0}]), 0);

    ASSERT_EQ(sparse.get_element(1,1), 0);
    sparse.set_element(1, 1, 3);
    ASSERT_EQ(sparse.get_element(1,1), 3);
}

TEST(sparse_matrix_tests, ops_test) {
    sparse_matrix<double> sparse(3, 2);
    ASSERT_EQ(sparse.get_height(), 3);
    ASSERT_EQ(sparse.get_width(), 2);

    sparse[{2,1}] = 5;

    sparse.transpose();
    ASSERT_EQ(sparse.get_height(), 2);
    ASSERT_EQ(sparse.get_width(), 3);

    ASSERT_EQ(sparse.get_element(1, 2), 5);
    ASSERT_EQ(sparse.get_element(2, 1), 0);

    sparse_matrix<int> a(2, 3);
    sparse_matrix<int> b(3, 1);

    a[{0, 0}] = 5;
    a[{0, 1}] = 6;
    a[{0, 2}] = 10;
    a[{1, 0}] = 5;
    a[{1, 1}] = 9;
    a[{1, 2}] = 11;

    b[{0, 0}] = 1;
    b[{1, 0}] = 2;
    b[{2, 0}] = 3;

    sparse_matrix c = a * b;

    ASSERT_EQ(c.get_width(), 1);
    ASSERT_EQ(c.get_height(), 2);

    ASSERT_EQ((c[{0, 0}]), 47);
    ASSERT_EQ((c[{1, 0}]), 56);

    sparse_matrix<int> d(2, 1);
    d[{0,0}] = 3;
    d[{1, 0}] = 4;

    c += d;
    ASSERT_EQ((c[{0, 0}]), 50);
    ASSERT_EQ((c[{1, 0}]), 60);

    d -= c;
    ASSERT_EQ((d[{0, 0}]), -47);
    ASSERT_EQ((d[{1, 0}]), -56);
}

#endif //LAB01_SPARSE_MATRIX_TESTS_H
