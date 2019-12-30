#pragma once

#include <Source/Engine/Math/Matrix.h>
#include <gtest/gtest.h>

namespace {

    TEST(Matrix, Row_and_Col_length)
    {
        Hx::Math::Matrix<int, 2, 3> mat;
        EXPECT_EQ(mat.LengthRow(), 2);
        EXPECT_EQ(mat.LengthCol(), 3);
    }

    TEST(Matrix, Indexing_and_default_value_is_0)
    {
        Hx::Math::Matrix<int, 2, 3> mat;
        EXPECT_EQ(mat.Get(1, 1), 0);
    }

    TEST(Matrix, From_array)
    {
        int array[2][3] = {{1, 2, 3}, {4, 5, 6}};
        Hx::Math::Matrix<int, 2, 3> mat(array);
        EXPECT_EQ(mat.Get(1, 2), 6);
    }

}