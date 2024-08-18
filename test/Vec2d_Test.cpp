#include "pch.h"
#include <VecPlus/Vec2.h>
#include <iostream>

using namespace vecp;

namespace Vec2d_Tests
{
    TEST(TestConstructorDefault, SetDefaultValues)
    {   
        Vec2d vector = Vec2d();
        ASSERT_DOUBLE_EQ(vector.x, 0.0);
        ASSERT_DOUBLE_EQ(vector.y, 0.0);
    }

    // Constructor with specified values test
    TEST(TestConstructorValues, SetSpecifiedValues)
    {
        Vec2d vector = Vec2d(-3.5, 4.2);
        ASSERT_DOUBLE_EQ(vector.x, -3.5);
        ASSERT_DOUBLE_EQ(vector.y, 4.2);
    }

    class Vec2d_VecScaVecFixture : public testing::TestWithParam<std::tuple<Vec2d, double, Vec2d>>
    {
    protected:
        void SetUp() override
        {
            vector = std::get<0>(GetParam());
            scalar = std::get<1>(GetParam());
            expected = std::get<2>(GetParam());
        }
        Vec2d vector, expected;
        double scalar;
    };

    class Vec2d_VecVecVecFixture : public testing::TestWithParam<std::tuple<Vec2d, Vec2d, Vec2d>>
    {
    protected:
        void SetUp() override
        {
            vectorOne = std::get<0>(GetParam());
            vectorTwo = std::get<1>(GetParam());
            expected = std::get<2>(GetParam());
        }
        Vec2d vectorOne, vectorTwo, expected;
    };

    // Vec2d operator + (const Vec2d& vector) const
    class Vec2d_AddVectorF : public Vec2d_VecVecVecFixture {};
    TEST_P(Vec2d_AddVectorF, Vec2d_AddVector)
    {
        Vec2d output = vectorOne + vectorTwo;
        ASSERT_DOUBLE_EQ(expected.x, output.x);
        ASSERT_DOUBLE_EQ(expected.y, output.y);
    }

    INSTANTIATE_TEST_SUITE_P(Vec2d_AddVector, Vec2d_AddVectorF, testing::Values(
        std::make_tuple(Vec2d(1.1, 2.2), Vec2d(3.3, 4.4), Vec2d(4.4, 6.6)),
        std::make_tuple(Vec2d(-2.5, 5.1), Vec2d(7.2, -3.3), Vec2d(4.7, 1.8)),
        std::make_tuple(Vec2d(0.0, -8.4), Vec2d(-4.4, 6.6), Vec2d(-4.4, -1.8)),
        std::make_tuple(Vec2d(10.0, -10.0), Vec2d(-10.0, 10.0), Vec2d(0.0, 0.0))
    ));

    // void operator += (const Vec2d& vector)
    class Vec2d_AddEqualsVectorF : public Vec2d_VecVecVecFixture {};
    TEST_P(Vec2d_AddEqualsVectorF, Vec2d_AddEqualsVector)
    {
        vectorOne += vectorTwo;
        ASSERT_DOUBLE_EQ(expected.x, vectorOne.x);
        ASSERT_DOUBLE_EQ(expected.y, vectorOne.y);
    }

    INSTANTIATE_TEST_SUITE_P(Vec2d_AddEqualsVector, Vec2d_AddEqualsVectorF, testing::Values(
        std::make_tuple(Vec2d(1.1, 2.2), Vec2d(3.3, 4.4), Vec2d(4.4, 6.6)),
        std::make_tuple(Vec2d(-2.5, 5.1), Vec2d(7.2, -3.3), Vec2d(4.7, 1.8)),
        std::make_tuple(Vec2d(0.0, -8.4), Vec2d(-4.4, 6.6), Vec2d(-4.4, -1.8)),
        std::make_tuple(Vec2d(10.0, -10.0), Vec2d(-10.0, 10.0), Vec2d(0.0, 0.0))
    ));

    // Vec2d operator - (const Vec2d& vector) const
    class Vec2d_SubtractVectorF : public Vec2d_VecVecVecFixture {};
    TEST_P(Vec2d_SubtractVectorF, SubtractVector)
    {
        Vec2d output = vectorOne - vectorTwo;
        ASSERT_DOUBLE_EQ(expected.x, output.x);
        ASSERT_DOUBLE_EQ(expected.y, output.y);
    }

    INSTANTIATE_TEST_SUITE_P(Vec2d_SubtractVector, Vec2d_SubtractVectorF, testing::Values(
        std::make_tuple(Vec2d(5.5, 7.7), Vec2d(3.3, 2.2), Vec2d(2.2, 5.5)),
        std::make_tuple(Vec2d(10.0, 10.0), Vec2d(4.5, 6.5), Vec2d(5.5, 3.5)),
        std::make_tuple(Vec2d(-3.3, 8.8), Vec2d(2.2, -5.5), Vec2d(-5.5, 14.3)),
        std::make_tuple(Vec2d(0.0, 0.0), Vec2d(-7.7, 9.9), Vec2d(7.7, -9.9))
    ));

    // void operator -= (const Vec2d& vector)
    class Vec2d_SubtractEqualsVectorF : public Vec2d_VecVecVecFixture {};
    TEST_P(Vec2d_SubtractEqualsVectorF, Vec2d_SubtractEqualsVector)
    {
        vectorOne -= vectorTwo;
        ASSERT_DOUBLE_EQ(expected.x, vectorOne.x);
        ASSERT_DOUBLE_EQ(expected.y, vectorOne.y);
    }

    INSTANTIATE_TEST_SUITE_P(Vec2d_SubtractEqualsVector, Vec2d_SubtractEqualsVectorF, testing::Values(
        std::make_tuple(Vec2d(5.5, 7.7), Vec2d(3.3, 2.2), Vec2d(2.2, 5.5)),
        std::make_tuple(Vec2d(10.0, 10.0), Vec2d(4.5, 6.5), Vec2d(5.5, 3.5)),
        std::make_tuple(Vec2d(-3.3, 8.8), Vec2d(2.2, -5.5), Vec2d(-5.5, 14.3)),
        std::make_tuple(Vec2d(0.0, 0.0), Vec2d(-7.7, 9.9), Vec2d(7.7, -9.9))
    ));

    // Vec2d operator * (double scalar) const
    class Vec2d_MultiplyByScalarF : public Vec2d_VecScaVecFixture {};
    TEST_P(Vec2d_MultiplyByScalarF, Vec2d_MultiplyByScalar)
    {
        Vec2d output = vector * scalar;
        ASSERT_DOUBLE_EQ(expected.x, output.x);
        ASSERT_DOUBLE_EQ(expected.y, output.y);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec2d_MultiplyByScalar, Vec2d_MultiplyByScalarF, testing::Values(
        std::make_tuple(Vec2d(0.0, 0.0), 10.0, Vec2d(0.0, 0.0)),
        std::make_tuple(Vec2d(3.3, 4.4), 10.0, Vec2d(33.0, 44.0)),
        std::make_tuple(Vec2d(-6.6, 4.4), 5.0, Vec2d(-33.0, 22.0)),
        std::make_tuple(Vec2d(8.8, -7.7), -5.0, Vec2d(-44.0, 38.5))
    ));

    // Vec2d operator * (const Vec2d& vector) const
    class Vec2d_MultiplyByVectorF : public Vec2d_VecVecVecFixture {};
    TEST_P(Vec2d_MultiplyByVectorF, Vec2d_MultiplyByVector)
    {
        Vec2d output = vectorOne * vectorTwo;
        ASSERT_DOUBLE_EQ(expected.x, output.x);
        ASSERT_DOUBLE_EQ(expected.y, output.y);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec2d_MultiplyByVector, Vec2d_MultiplyByVectorF, testing::Values(
        std::make_tuple(Vec2d(0.0, 0.0), Vec2d(10.0, 10.0), Vec2d(0.0, 0.0)),
        std::make_tuple(Vec2d(3.3, 4.4), Vec2d(5.5, 10.0), Vec2d(18.15, 44.0)),
        std::make_tuple(Vec2d(-6.6, 4.4), Vec2d(5.5, -5.0), Vec2d(-36.3, -22.0)),
        std::make_tuple(Vec2d(8.8, -7.7), Vec2d(-5.5, -5.5), Vec2d(-48.4, 42.35))
    ));

    // void operator *= (double scalar)
    class Vec2d_MultiplyEqualsByScalarF : public Vec2d_VecScaVecFixture {};
    TEST_P(Vec2d_MultiplyEqualsByScalarF, Vec2d_MultiplyEqualsByScalar)
    {
        vector *= scalar;
        ASSERT_DOUBLE_EQ(expected.x, vector.x);
        ASSERT_DOUBLE_EQ(expected.y, vector.y);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec2d_MultiplyEqualsByScalar, Vec2d_MultiplyEqualsByScalarF, testing::Values(
        std::make_tuple(Vec2d(0.0, 0.0), 10.0, Vec2d(0.0, 0.0)),
        std::make_tuple(Vec2d(3.3, 4.4), 10.0, Vec2d(33.0, 44.0)),
        std::make_tuple(Vec2d(-6.6, 4.4), 5.0, Vec2d(-33.0, 22.0)),
        std::make_tuple(Vec2d(8.8, -7.7), -5.0, Vec2d(-44.0, 38.5))
    ));

    // void operator *= (const Vec2d& vector)
    class Vec2d_MultiplyEqualsByVectorF : public Vec2d_VecVecVecFixture {};
    TEST_P(Vec2d_MultiplyEqualsByVectorF, Vec2d_MultiplyEqualsByVector)
    {
        vectorOne *= vectorTwo;
        ASSERT_DOUBLE_EQ(expected.x, vectorOne.x);
        ASSERT_DOUBLE_EQ(expected.y, vectorOne.y);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec2d_MultiplyEqualsByVector, Vec2d_MultiplyEqualsByVectorF, testing::Values(
        std::make_tuple(Vec2d(0.0, 0.0), Vec2d(10.0, 10.0), Vec2d(0.0, 0.0)),
        std::make_tuple(Vec2d(3.3, 4.4), Vec2d(5.5, 10.0), Vec2d(18.15, 44.0)),
        std::make_tuple(Vec2d(-6.6, 4.4), Vec2d(5.5, -5.0), Vec2d(-36.3, -22.0)),
        std::make_tuple(Vec2d(8.8, -7.7), Vec2d(-5.5, -5.5), Vec2d(-48.4, 42.35))
    ));

    class Vec2d_VecVecBoolFixture : public testing::TestWithParam<std::tuple<Vec2d, Vec2d, bool>>
    {
    protected:
        void SetUp() override
        {
            vectorOne = std::get<0>(GetParam());
            vectorTwo = std::get<1>(GetParam());
            expected = std::get<2>(GetParam());
        }
        Vec2d vectorOne, vectorTwo;
        bool expected;
    };

    // bool operator == (const Vec2d& vector) const
    class Vec2d_CompareVectorsF : public Vec2d_VecVecBoolFixture {};
    TEST_P(Vec2d_CompareVectorsF, Vec2d_CompareVectors)
    {
        bool output = vectorOne == vectorTwo;
        ASSERT_DOUBLE_EQ(expected, output);
        ASSERT_DOUBLE_EQ(expected, output);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec2d_CompareVectors, Vec2d_CompareVectorsF, testing::Values(
        std::make_tuple(Vec2d(-5.5, 5.5), Vec2d(-5.5, 5.5), true),
        std::make_tuple(Vec2d(0.0, 0.0), Vec2d(0.0, 0.0), true),
        std::make_tuple(Vec2d(-5.5, 5.5), Vec2d(5.5, -5.5), false),
        std::make_tuple(Vec2d(6.1, 0.0), Vec2d(7.1, 0.0), false)
    ));

    class Vec2d_VecVecScaFixture : public testing::TestWithParam<std::tuple<Vec2d, Vec2d, double>>
    {
    protected:
        void SetUp() override
        {
            vectorOne = std::get<0>(GetParam());
            vectorTwo = std::get<1>(GetParam());
            expected = std::get<2>(GetParam());
        }
        Vec2d vectorOne, vectorTwo;
        double expected;
    };

    // Vec2d operator / (double scalar) const
    class Vec2d_DivideByScalarF : public Vec2d_VecScaVecFixture {};
    TEST_P(Vec2d_DivideByScalarF, Vec2d_DivideByScalar)
    {
        Vec2d output = vector / scalar;
        ASSERT_DOUBLE_EQ(expected.x, output.x);
        ASSERT_DOUBLE_EQ(expected.y, output.y);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec2d_DivideByScalar, Vec2d_DivideByScalarF, testing::Values(
        std::make_tuple(Vec2d(10.0, 20.0), 2.0, Vec2d(5.0, 10.0)),
        std::make_tuple(Vec2d(-6.6, 4.4), -2.2, Vec2d(3.0, -2.0)),
        std::make_tuple(Vec2d(10.0, -5.0), 2.0, Vec2d(5.0, -2.5)),
        std::make_tuple(Vec2d(8.8, -7.7), 4.4, Vec2d(2.0, -1.75)),
        std::make_tuple(Vec2d(9.0, 12.0), 3.0, Vec2d(3.0, 4.0))  // Additional test case
    ));

    // Vec2d operator / (const Vec2d& vector) const
    class Vec2d_DivideByVectorF : public Vec2d_VecVecVecFixture {};
    TEST_P(Vec2d_DivideByVectorF, Vec2d_DivideByVector)
    {
        Vec2d output = vectorOne / vectorTwo;
        ASSERT_DOUBLE_EQ(expected.x, output.x);
        ASSERT_DOUBLE_EQ(expected.y, output.y);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec2d_DivideByVector, Vec2d_DivideByVectorF, testing::Values(
        std::make_tuple(Vec2d(10.0, 20.0), Vec2d(2.0, 4.0), Vec2d(5.0, 5.0)),
        std::make_tuple(Vec2d(-6.6, 4.4), Vec2d(-2.2, 2.2), Vec2d(3.0, 2.0)),
        std::make_tuple(Vec2d(10.0, -5.0), Vec2d(2.0, -5.0), Vec2d(5.0, 1.0)),
        std::make_tuple(Vec2d(8.8, -7.7), Vec2d(4.4, -7.7), Vec2d(2.0, 1.0))
    ));

    // void operator /= (double scalar)
    class Vec2d_DivideEqualsByScalarF : public Vec2d_VecScaVecFixture {};
    TEST_P(Vec2d_DivideEqualsByScalarF, Vec2d_DivideEqualsByScalar)
    {
        vector /= scalar;
        ASSERT_DOUBLE_EQ(expected.x, vector.x);
        ASSERT_DOUBLE_EQ(expected.y, vector.y);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec2d_DivideEqualsByScalar, Vec2d_DivideEqualsByScalarF, testing::Values(
        std::make_tuple(Vec2d(10.0, 20.0), 2.0, Vec2d(5.0, 10.0)),
        std::make_tuple(Vec2d(-6.6, 4.4), -2.2, Vec2d(3.0, -2.0)),
        std::make_tuple(Vec2d(10.0, -5.0), 2.0, Vec2d(5.0, -2.5)),
        std::make_tuple(Vec2d(8.8, -7.7), 4.4, Vec2d(2.0, -1.75)),
        std::make_tuple(Vec2d(9.0, 12.0), 3.0, Vec2d(3.0, 4.0))  // Additional test case
    ));

    // void operator /= (const Vec2d& vector)
    class Vec2d_DivideEqualsByVectorF : public Vec2d_VecVecVecFixture {};
    TEST_P(Vec2d_DivideEqualsByVectorF, Vec2d_DivideEqualsByVector)
    {
        vectorOne /= vectorTwo;
        ASSERT_DOUBLE_EQ(expected.x, vectorOne.x);
        ASSERT_DOUBLE_EQ(expected.y, vectorOne.y);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec2d_DivideEqualsByVector, Vec2d_DivideEqualsByVectorF, testing::Values(
        std::make_tuple(Vec2d(10.0, 20.0), Vec2d(2.0, 4.0), Vec2d(5.0, 5.0)),
        std::make_tuple(Vec2d(-6.6, 4.4), Vec2d(-2.2, 2.2), Vec2d(3.0, 2.0)),
        std::make_tuple(Vec2d(10.0, -5.0), Vec2d(2.0, -5.0), Vec2d(5.0, 1.0)),
        std::make_tuple(Vec2d(8.8, -7.7), Vec2d(4.4, -7.7), Vec2d(2.0, 1.0))
    ));
}