#include "pch.h"
#include <VecPlus/Vec2.h>
#include <iostream>

using namespace vecp;

namespace Vec2d_Tests
{
    TEST(Vec2f_TestConstructorDefault, SetDefaultValues)
    {   
        Vec2f vector = Vec2f();
        ASSERT_FLOAT_EQ(vector.x, 0.0f);
        ASSERT_FLOAT_EQ(vector.y, 0.0f);
    }

    // Constructor with specified values test
    TEST(Vec2f_TestConstructorValues, SetSpecifiedValues)
    {
        Vec2f vector = Vec2f(-3.5f, 4.2f);
        ASSERT_FLOAT_EQ(vector.x, -3.5f);
        ASSERT_FLOAT_EQ(vector.y, 4.2f);
    }

    class Vec2f_VecScaVecFixture : public testing::TestWithParam<std::tuple<Vec2f, float, Vec2f>>
    {
    protected:
        void SetUp() override
        {
            vector = std::get<0>(GetParam());
            scalar = std::get<1>(GetParam());
            expected = std::get<2>(GetParam());
        }
        Vec2f vector, expected;
        float scalar;
    };

    class Vec2f_VecVecVecFixture : public testing::TestWithParam<std::tuple<Vec2f, Vec2f, Vec2f>>
    {
    protected:
        void SetUp() override
        {
            vectorOne = std::get<0>(GetParam());
            vectorTwo = std::get<1>(GetParam());
            expected = std::get<2>(GetParam());
        }
        Vec2f vectorOne, vectorTwo, expected;
    };

    // Vec2f operator + (const Vec2f& vector) const
    class Vec2f_AddVectorF : public Vec2f_VecVecVecFixture {};
    TEST_P(Vec2f_AddVectorF, Vec2f_AddVector)
    {
        Vec2f output = vectorOne + vectorTwo;
        ASSERT_FLOAT_EQ(expected.x, output.x);
        ASSERT_FLOAT_EQ(expected.y, output.y);
    }

    INSTANTIATE_TEST_SUITE_P(Vec2f_AddVector, Vec2f_AddVectorF, testing::Values(
        std::make_tuple(Vec2f(1.1f, 2.2f), Vec2f(3.3f, 4.4f), Vec2f(4.4f, 6.6f)),
        std::make_tuple(Vec2f(-2.5f, 5.1f), Vec2f(7.2f, -3.3f), Vec2f(4.7f, 1.8f)),
        std::make_tuple(Vec2f(0.0f, -8.4f), Vec2f(-4.4f, 6.6f), Vec2f(-4.4f, -1.8f)),
        std::make_tuple(Vec2f(10.0f, -10.0f), Vec2f(-10.0f, 10.0f), Vec2f(0.0f, 0.0f))
    ));

    // void operator += (const Vec2f& vector)
    class Vec2f_AddEqualsVectorF : public Vec2f_VecVecVecFixture {};
    TEST_P(Vec2f_AddEqualsVectorF, Vec2f_AddEqualsVector)
    {
        vectorOne += vectorTwo;
        ASSERT_FLOAT_EQ(expected.x, vectorOne.x);
        ASSERT_FLOAT_EQ(expected.y, vectorOne.y);
    }

    INSTANTIATE_TEST_SUITE_P(Vec2f_AddEqualsVector, Vec2f_AddEqualsVectorF, testing::Values(
        std::make_tuple(Vec2f(1.1f, 2.2f), Vec2f(3.3f, 4.4f), Vec2f(4.4f, 6.6f)),
        std::make_tuple(Vec2f(-2.5f, 5.1f), Vec2f(7.2f, -3.3f), Vec2f(4.7f, 1.8f)),
        std::make_tuple(Vec2f(0.0f, -8.4f), Vec2f(-4.4f, 6.6f), Vec2f(-4.4f, -1.8f)),
        std::make_tuple(Vec2f(10.0f, -10.0f), Vec2f(-10.0f, 10.0f), Vec2f(0.0f, 0.0f))
    ));

    // Vec2f operator - (const Vec2f& vector) const
    class Vec2f_SubtractVectorF : public Vec2f_VecVecVecFixture {};
    TEST_P(Vec2f_SubtractVectorF, Vec2f_SubtractVector)
    {
        Vec2f output = vectorOne - vectorTwo;
        ASSERT_EQ(expected.x, output.x);
        ASSERT_EQ(expected.y, output.y);
    }

    INSTANTIATE_TEST_SUITE_P(Vec2f_SubtractVector, Vec2f_SubtractVectorF, testing::Values(
        std::make_tuple(Vec2f(5.5f, 7.7f), Vec2f(3.3f, 2.2f), Vec2f(2.2f, 5.5f)),
        std::make_tuple(Vec2f(10.0f, 10.0f), Vec2f(4.5f, 6.5f), Vec2f(5.5f, 3.5f)),
        std::make_tuple(Vec2f(-3.3f, 8.8f), Vec2f(2.2f, -5.5f), Vec2f(-5.5f, 14.3f)),
        std::make_tuple(Vec2f(0.0f, 0.0f), Vec2f(-7.7f, 9.9f), Vec2f(7.7f, -9.9f))
    ));

    // void operator -= (const Vec2f& vector)
    class Vec2f_SubtractEqualsVectorF : public Vec2f_VecVecVecFixture {};
    TEST_P(Vec2f_SubtractEqualsVectorF, Vec2f_SubtractEqualsVector)
    {
        vectorOne -= vectorTwo;
        ASSERT_FLOAT_EQ(expected.x, vectorOne.x);
        ASSERT_FLOAT_EQ(expected.y, vectorOne.y);
    }

    INSTANTIATE_TEST_SUITE_P(Vec2f_SubtractEqualsVector, Vec2f_SubtractEqualsVectorF, testing::Values(
        std::make_tuple(Vec2f(5.5f, 7.7f), Vec2f(3.3f, 2.2f), Vec2f(2.2f, 5.5f)),
        std::make_tuple(Vec2f(10.0f, 10.0f), Vec2f(4.5f, 6.5f), Vec2f(5.5f, 3.5f)),
        std::make_tuple(Vec2f(-3.3f, 8.8f), Vec2f(2.2f, -5.5f), Vec2f(-5.5f, 14.3f)),
        std::make_tuple(Vec2f(0.0f, 0.0f), Vec2f(-7.7f, 9.9f), Vec2f(7.7f, -9.9f))
    ));

    // Vec2f operator * (float scalar) const
    class Vec2f_MultiplyByScalarF : public Vec2f_VecScaVecFixture {};
    TEST_P(Vec2f_MultiplyByScalarF, Vec2f_MultiplyByScalar)
    {
        Vec2f output = vector * scalar;
        ASSERT_FLOAT_EQ(expected.x, output.x);
        ASSERT_FLOAT_EQ(expected.y, output.y);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec2f_MultiplyByScalar, Vec2f_MultiplyByScalarF, testing::Values(
        std::make_tuple(Vec2f(0.0f, 0.0f), 10.0f, Vec2f(0.0f, 0.0f)),
        std::make_tuple(Vec2f(3.3f, 4.4f), 10.0f, Vec2f(33.0f, 44.0f)),
        std::make_tuple(Vec2f(-6.6f, 4.4f), 5.0f, Vec2f(-33.0f, 22.0f)),
        std::make_tuple(Vec2f(8.8f, -7.7f), -5.0f, Vec2f(-44.0f, 38.5f))
    ));

    // Vec2f operator * (const Vec2f& vector) const
    class Vec2f_MultiplyByVectorF : public Vec2f_VecVecVecFixture {};
    TEST_P(Vec2f_MultiplyByVectorF, Vec2f_MultiplyByVector)
    {
        Vec2f output = vectorOne * vectorTwo;
        ASSERT_FLOAT_EQ(expected.x, output.x);
        ASSERT_FLOAT_EQ(expected.y, output.y);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec2f_MultiplyByVector, Vec2f_MultiplyByVectorF, testing::Values(
        std::make_tuple(Vec2f(0.0f, 0.0f), Vec2f(10.0f, 10.0f), Vec2f(0.0f, 0.0f)),
        std::make_tuple(Vec2f(3.3f, 4.4f), Vec2f(5.5f, 10.0f), Vec2f(18.15f, 44.0f)),
        std::make_tuple(Vec2f(-6.6f, 4.4f), Vec2f(5.5f, -5.0f), Vec2f(-36.3f, -22.0f)),
        std::make_tuple(Vec2f(8.8f, -7.7f), Vec2f(-5.5f, -5.5f), Vec2f(-48.4f, 42.35f))
    ));

    // void operator *= (float scalar)
    class Vec2f_MultiplyEqualsByScalarF : public Vec2f_VecScaVecFixture {};
    TEST_P(Vec2f_MultiplyEqualsByScalarF, Vec2f_MultiplyEqualsByScalar)
    {
        vector *= scalar;
        ASSERT_FLOAT_EQ(expected.x, vector.x);
        ASSERT_FLOAT_EQ(expected.y, vector.y);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec2f_MultiplyEqualsByScalar,Vec2f_MultiplyEqualsByScalarF, testing::Values(
        std::make_tuple(Vec2f(0.0f, 0.0f), 10.0f, Vec2f(0.0f, 0.0f)),
        std::make_tuple(Vec2f(3.3f, 4.4f), 10.0f, Vec2f(33.0f, 44.0f)),
        std::make_tuple(Vec2f(-6.6f, 4.4f), 5.0f, Vec2f(-33.0f, 22.0f)),
        std::make_tuple(Vec2f(8.8f, -7.7f), -5.0f, Vec2f(-44.0f, 38.5f))
    ));

    // void operator *= (const Vec2f& vector)
    class Vec2f_MultiplyEqualsByVectorF : public Vec2f_VecVecVecFixture {};
    TEST_P(Vec2f_MultiplyEqualsByVectorF, MultiplyEqualsByVector)
    {
        vectorOne *= vectorTwo;
        ASSERT_FLOAT_EQ(expected.x, vectorOne.x);
        ASSERT_FLOAT_EQ(expected.y, vectorOne.y);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec2f_MultiplyEqualsByVector, Vec2f_MultiplyEqualsByVectorF, testing::Values(
        std::make_tuple(Vec2f(0.0f, 0.0f), Vec2f(10.0f, 10.0f), Vec2f(0.0f, 0.0f)),
        std::make_tuple(Vec2f(3.3f, 4.4f), Vec2f(5.5f, 10.0f), Vec2f(18.15f, 44.0f)),
        std::make_tuple(Vec2f(-6.6f, 4.4f), Vec2f(5.5f, -5.0f), Vec2f(-36.3f, -22.0f)),
        std::make_tuple(Vec2f(8.8f, -7.7f), Vec2f(-5.5f, -5.5f), Vec2f(-48.4f, 42.35f))
    ));

    class Vec2f_VecVecBoolFixture : public testing::TestWithParam<std::tuple<Vec2f, Vec2f, bool>>
    {
    protected:
        void SetUp() override
        {
            vectorOne = std::get<0>(GetParam());
            vectorTwo = std::get<1>(GetParam());
            expected = std::get<2>(GetParam());
        }
        Vec2f vectorOne, vectorTwo;
        bool expected;
    };

    // bool operator == (const Vec2f& vector) const
    class Vec2f_CompareVectorsF : public Vec2f_VecVecBoolFixture {};
    TEST_P(Vec2f_CompareVectorsF, CompareVectors)
    {
        bool output = vectorOne == vectorTwo;
        ASSERT_FLOAT_EQ(expected, output);
        ASSERT_FLOAT_EQ(expected, output);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec2f_CompareVectors, Vec2f_CompareVectorsF, testing::Values(
        std::make_tuple(Vec2f(-5.5f, 5.5f), Vec2f(-5.5f, 5.5f), true),
        std::make_tuple(Vec2f(0.0f, 0.0f), Vec2f(0.0f, 0.0f), true),
        std::make_tuple(Vec2f(-5.5f, 5.5f), Vec2f(5.5f, -5.5f), false),
        std::make_tuple(Vec2f(6.1f, 0.0f), Vec2f(7.1f, 0.0f), false)
    ));

    class Vec2f_VecVecScaFixture : public testing::TestWithParam<std::tuple<Vec2f, Vec2f, float>>
    {
    protected:
        void SetUp() override
        {
            vectorOne = std::get<0>(GetParam());
            vectorTwo = std::get<1>(GetParam());
            expected = std::get<2>(GetParam());
        }
        Vec2f vectorOne, vectorTwo;
        float expected;
    };

    // Vec2f operator / (float scalar) const
    class Vec2f_DivideByScalarF : public Vec2f_VecScaVecFixture {};
    TEST_P(Vec2f_DivideByScalarF, Vec2f_DivideByScalar)
    {
        Vec2f output = vector / scalar;
        ASSERT_FLOAT_EQ(expected.x, output.x);
        ASSERT_FLOAT_EQ(expected.y, output.y);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec2f_DivideByScalar, Vec2f_DivideByScalarF, testing::Values(
        std::make_tuple(Vec2f(10.0f, 20.0f), 2.0f, Vec2f(5.0f, 10.0f)),
        std::make_tuple(Vec2f(-6.6f, 4.4f), -2.2f, Vec2f(3.0f, -2.0f)),
        std::make_tuple(Vec2f(10.0f, -5.0f), 2.0f, Vec2f(5.0f, -2.5f)),
        std::make_tuple(Vec2f(8.8f, -7.7f), 4.4f, Vec2f(2.0f, -1.75f)),
        std::make_tuple(Vec2f(9.0f, 12.0f), 3.0f, Vec2f(3.0f, 4.0f))  
    ));

    // Vec2f operator / (const Vec2f& vector) const
    class Vec2f_DivideByVectorF : public Vec2f_VecVecVecFixture {};
    TEST_P(Vec2f_DivideByVectorF, Vec2f_DivideByVector)
    {
        Vec2f output = vectorOne / vectorTwo;
        ASSERT_FLOAT_EQ(expected.x, output.x);
        ASSERT_FLOAT_EQ(expected.y, output.y);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec2f_DivideByVector, Vec2f_DivideByVectorF, testing::Values(
        std::make_tuple(Vec2f(10.0f, 20.0f), Vec2f(2.0f, 4.0f), Vec2f(5.0f, 5.0f)),
        std::make_tuple(Vec2f(-6.6f, 4.4f), Vec2f(-2.2f, 2.2f), Vec2f(3.0f, 2.0f)),
        std::make_tuple(Vec2f(10.0f, -5.0f), Vec2f(2.0f, -5.0f), Vec2f(5.0f, 1.0f)),
        std::make_tuple(Vec2f(8.8f, -7.7f), Vec2f(4.4f, -7.7f), Vec2f(2.0f, 1.0f))
    ));

    // void operator /= (float scalar)
    class Vec2f_DivideEqualsByScalarF : public Vec2f_VecScaVecFixture {};
    TEST_P(Vec2f_DivideEqualsByScalarF, Vec2f_DivideEqualsByScalar)
    {
        vector /= scalar;
        ASSERT_FLOAT_EQ(expected.x, vector.x);
        ASSERT_FLOAT_EQ(expected.y, vector.y);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec2f_DivideEqualsByScalar, Vec2f_DivideEqualsByScalarF, testing::Values(
        std::make_tuple(Vec2f(10.0f, 20.0f), 2.0f, Vec2f(5.0f, 10.0f)),
        std::make_tuple(Vec2f(-6.6f, 4.4f), -2.2f, Vec2f(3.0f, -2.0f)),
        std::make_tuple(Vec2f(10.0f, -5.0f), 2.0f, Vec2f(5.0f, -2.5f)),
        std::make_tuple(Vec2f(8.8f, -7.7f), 4.4f, Vec2f(2.0f, -1.75f))
    ));

    // void operator /= (const Vec2f& vector)
    class Vec2f_DivideEqualsByVectorF : public Vec2f_VecVecVecFixture {};
    TEST_P(Vec2f_DivideEqualsByVectorF, Vec2f_DivideEqualsByVector)
    {
        vectorOne /= vectorTwo;
        ASSERT_FLOAT_EQ(expected.x, vectorOne.x);
        ASSERT_FLOAT_EQ(expected.y, vectorOne.y);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec2f_DivideEqualsByVector, Vec2f_DivideEqualsByVectorF, testing::Values(
        std::make_tuple(Vec2f(10.0f, 20.0f), Vec2f(2.0f, 4.0f), Vec2f(5.0f, 5.0f)),
        std::make_tuple(Vec2f(-6.6f, 4.4f), Vec2f(-2.2f, 2.2f), Vec2f(3.0f, 2.0f)),
        std::make_tuple(Vec2f(10.0f, -5.0f), Vec2f(2.0f, -5.0f), Vec2f(5.0f, 1.0f)),
        std::make_tuple(Vec2f(8.8f, -7.7f), Vec2f(4.4f, -7.7f), Vec2f(2.0f, 1.0f))
    ));



}