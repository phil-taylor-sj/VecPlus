#include "pch.h"
#include <VecPlus/Vec2.h>
#include <iostream>

using namespace vecp;

namespace Vec2i_Tests
{
    TEST(Vec2i_TestConstructorDefault, SetDefaultValues)
    {   
        Vec2i vector = Vec2i();
        ASSERT_EQ(vector.x, 0);
        ASSERT_EQ(vector.y, 0);
    }

    TEST(Vec2i_TestConstructorValues, SetSpecifiedValues)
    {
        Vec2i vector = Vec2i(-3, 4);
        ASSERT_EQ(vector.x, -3);
        ASSERT_EQ(vector.y, 4);
    }

    class Vec2i_VecScaVecFixture : public testing::TestWithParam<std::tuple<Vec2i, int, Vec2i>>
    {
        protected:
            void SetUp() override
            {
                vector = std::get<0>(GetParam());
                scalar = std::get<1>(GetParam());
                expected = std::get<2>(GetParam());
            }
            Vec2i vector, expected;
            int scalar;
    };

    class Vec2i_VecVecVecFixture : public testing::TestWithParam<std::tuple<Vec2i, Vec2i, Vec2i>>
    {
        protected:
            void SetUp() override
            {
                vectorOne = std::get<0>(GetParam());
                vectorTwo = std::get<1>(GetParam());
                expected = std::get<2>(GetParam());
            }
            Vec2i vectorOne, vectorTwo, expected;
    };

    // Vec2i operator + (const Vec2i& vector) const
    class Vec2i_AddVectorF : public Vec2i_VecVecVecFixture {};
    TEST_P(Vec2i_AddVectorF, Vec2i_AddVector)
    {
        Vec2i output = vectorOne + vectorTwo;
        ASSERT_EQ(expected.x, output.x);
        ASSERT_EQ(expected.y, output.y);
    }

    INSTANTIATE_TEST_SUITE_P(Vec2i_AddVector, Vec2i_AddVectorF, testing::Values(
        std::make_tuple(Vec2i(1, 2), Vec2i(3, 4), Vec2i(4, 6)),
        std::make_tuple(Vec2i(-2, 5), Vec2i(7, -3), Vec2i(5, 2)),
        std::make_tuple(Vec2i(0, -8), Vec2i(-4, 6), Vec2i(-4, -2)),
        std::make_tuple(Vec2i(10, -10), Vec2i(-10, 10), Vec2i(0, 0)) 
    ));


    // void operator += (const Vec2i& vector)
    class Vec2i_AddEqualsVectorF : public Vec2i_VecVecVecFixture {};
    TEST_P(Vec2i_AddEqualsVectorF, Vec2i_AddEqualsVector)
    {
        vectorOne += vectorTwo;
        ASSERT_EQ(expected.x, vectorOne.x);
        ASSERT_EQ(expected.y, vectorOne.y);
    }

    INSTANTIATE_TEST_SUITE_P(Vec2i_AddEqualsVector, Vec2i_AddEqualsVectorF, testing::Values(
        std::make_tuple(Vec2i(1, 2), Vec2i(3, 4), Vec2i(4, 6)),
        std::make_tuple(Vec2i(-2, 5), Vec2i(7, -3), Vec2i(5, 2)),
        std::make_tuple(Vec2i(0, -8), Vec2i(-4, 6), Vec2i(-4, -2)),
        std::make_tuple(Vec2i(10, -10), Vec2i(-10, 10), Vec2i(0, 0)) 
    ));

    // Vec2i operator - (const Vec2i& vector) const
    class Vec2i_SubtractVectorF : public Vec2i_VecVecVecFixture {};
    TEST_P(Vec2i_SubtractVectorF, Vec2i_SubtractVector)
    {
        Vec2i output = vectorOne - vectorTwo;
        ASSERT_EQ(expected.x, output.x);
        ASSERT_EQ(expected.y, output.y);
    }

    INSTANTIATE_TEST_SUITE_P(Vec2i_SubtractVector, Vec2i_SubtractVectorF, testing::Values(
        std::make_tuple(Vec2i(5, 7), Vec2i(3, 2), Vec2i(2, 5)),
        std::make_tuple(Vec2i(10, 10), Vec2i(4, 6), Vec2i(6, 4)),
        std::make_tuple(Vec2i(-3, 8), Vec2i(2, -5), Vec2i(-5, 13)),
        std::make_tuple(Vec2i(0, 0), Vec2i(-7, 9), Vec2i(7, -9))
    ));

    // void operator -= (const Vec2i& vector)
    class Vec2i_SubtractEqualsVectorF : public Vec2i_VecVecVecFixture {};
    TEST_P(Vec2i_SubtractEqualsVectorF, Vec2i_SubtractEqualsVector)
    {
        vectorOne -= vectorTwo;
        ASSERT_EQ(expected.x, vectorOne.x);
        ASSERT_EQ(expected.y, vectorOne.y);
    }

    INSTANTIATE_TEST_SUITE_P(Vec2i_SubtractEqualsVector, Vec2i_SubtractEqualsVectorF, testing::Values(
        std::make_tuple(Vec2i(5, 7), Vec2i(3, 2), Vec2i(2, 5)),
        std::make_tuple(Vec2i(10, 10), Vec2i(4, 6), Vec2i(6, 4)),
        std::make_tuple(Vec2i(-3, 8), Vec2i(2, -5), Vec2i(-5, 13)),
        std::make_tuple(Vec2i(0, 0), Vec2i(-7, 9), Vec2i(7, -9))
    ));

    // Vec2i operator * (int scalar) const
    class Vec2i_MultiplyByScalarF : public Vec2i_VecScaVecFixture {};
    TEST_P(Vec2i_MultiplyByScalarF, Vec2i_MultiplyByScalar)
    {
        Vec2i output = vector * scalar;
        ASSERT_EQ(expected.x, output.x);
        ASSERT_EQ(expected.y, output.y);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec2i_MultiplyByScalar, Vec2i_MultiplyByScalarF, testing::Values(
        std::make_tuple(Vec2i(0, 0), 10, Vec2i(0, 0)),
        std::make_tuple(Vec2i(3, 4), 10, Vec2i(30, 40)),
        std::make_tuple(Vec2i(-6, 4), 5, Vec2i(-30, 20)),
        std::make_tuple(Vec2i(8, -7), -5, Vec2i(-40, 35))
    ));

    // Vec2i operator * (const Vec2i& vector) const
    class Vec2i_MultiplyByVectorF : public Vec2i_VecVecVecFixture {};
    TEST_P(Vec2i_MultiplyByVectorF, Vec2i_MultiplyByVector)
    {
        Vec2i output = vectorOne * vectorTwo;
        ASSERT_EQ(expected.x, output.x);
        ASSERT_EQ(expected.y, output.y);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec2i_MultiplyByVector, Vec2i_MultiplyByVectorF, testing::Values(
        std::make_tuple(Vec2i(0, 0), Vec2i(10, 10), Vec2i(0, 0)),
        std::make_tuple(Vec2i(3, 4), Vec2i(5, 10), Vec2i(15, 40)),
        std::make_tuple(Vec2i(-6, 4), Vec2i(5, -5), Vec2i(-30, -20)),
        std::make_tuple(Vec2i(8, -7), Vec2i(-5, -5), Vec2i(-40, 35))
    ));

    // void operator *= (int scalar)
    class Vec2i_MultiplyEqualsByScalarF : public Vec2i_VecScaVecFixture {};
    TEST_P(Vec2i_MultiplyEqualsByScalarF, Vec2i_MultiplyEqualsByScalar)
    {
        vector *= scalar;
        ASSERT_EQ(expected.x, vector.x);
        ASSERT_EQ(expected.y, vector.y);   
    }
    
    INSTANTIATE_TEST_SUITE_P(Vec2i_MultiplyEqualsByScalar, Vec2i_MultiplyEqualsByScalarF, testing::Values(
        std::make_tuple(Vec2i(0, 0), 10, Vec2i(0, 0)),
        std::make_tuple(Vec2i(3, 4), 10, Vec2i(30, 40)),
        std::make_tuple(Vec2i(-6, 4), 5, Vec2i(-30, 20)),
        std::make_tuple(Vec2i(8, -7), -5, Vec2i(-40, 35))
    ));

    // void operator *= (const Vec2i& vector)
    class Vec2i_MultiplyEqualsByVectorF : public Vec2i_VecVecVecFixture {};
    TEST_P(Vec2i_MultiplyEqualsByVectorF, Vec2i_MultiplyEqualsByVector)
    {
        vectorOne *= vectorTwo;
        ASSERT_EQ(expected.x, vectorOne.x);
        ASSERT_EQ(expected.y, vectorOne.y);   
    }
    
    INSTANTIATE_TEST_SUITE_P(Vec2i_MultiplyEqualsByVector, Vec2i_MultiplyEqualsByVectorF, testing::Values(
        std::make_tuple(Vec2i(0, 0), Vec2i(10, 10), Vec2i(0, 0)),
        std::make_tuple(Vec2i(3, 4), Vec2i(5, 10), Vec2i(15, 40)),
        std::make_tuple(Vec2i(-6, 4), Vec2i(5, -5), Vec2i(-30, -20)),
        std::make_tuple(Vec2i(8, -7), Vec2i(-5, -5), Vec2i(-40, 35))
    ));

    class Vec2i_VecVecBoolFixture : public testing::TestWithParam<std::tuple<Vec2i, Vec2i, bool>>
    {
        protected:
            void SetUp() override
            {
                vectorOne = std::get<0>(GetParam());
                vectorTwo = std::get<1>(GetParam());
                expected = std::get<2>(GetParam());
            }
            Vec2i vectorOne, vectorTwo;
            bool expected;
    };

    // bool operator == (const Vec2i& vector) const
    class Vec2i_CompareVectorsF : public Vec2i_VecVecBoolFixture {};
    TEST_P(Vec2i_CompareVectorsF, Vec2i_CompareVectors)
    {
        bool output = vectorOne == vectorTwo;
        ASSERT_EQ(expected, output);
        ASSERT_EQ(expected, output);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec2i_CompareVectors, Vec2i_CompareVectorsF, testing::Values(
        std::make_tuple(Vec2i(-5, 5), Vec2i(-5, 5), true),
        std::make_tuple(Vec2i(0, 0), Vec2i(0, 0), true),
        std::make_tuple(Vec2i(-5, 5), Vec2i(5, -5), false),
        std::make_tuple(Vec2i(6, 0), Vec2i(7, 0), false)
    ));


    class Vec2i_VecFloatFloatFixture : public testing::TestWithParam<std::tuple<Vec2i, float, float>>
    {
        protected:
            void SetUp() override
            {
                vector = std::get<0>(GetParam());
                expectedX = std::get<1>(GetParam());
                expectedY = std::get<2>(GetParam());
            }
            Vec2i vector;
            float expectedX, expectedY;
    };

    // Vec2f toFloat() const
    class Vec2i_ConvertToFloatF : public Vec2i_VecFloatFloatFixture {};
    TEST_P(Vec2i_ConvertToFloatF, Vec2i_ConvertToFloat)
    { 
        ASSERT_EQ(typeid(float), typeid(vector.toFloat().x));
        ASSERT_EQ(typeid(float), typeid(vector.toFloat().y));   
        ASSERT_EQ(expectedX, vector.toFloat().x);
        ASSERT_EQ(expectedY, vector.toFloat().y);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec2i_ConvertToFloat, Vec2i_ConvertToFloatF, testing::Values(
        std::make_tuple(Vec2i(0, 0), 0.f, 0.f),
        std::make_tuple(Vec2i(5, 5), 5.f, 5.f),
        std::make_tuple(Vec2i(-5, -5), -5.f, -5.f),
        std::make_tuple(Vec2i(10, -10), 10.f, -10.f)
    ));

    // Vec2d toDouble() const
    class Vec2i_ConvertToDoubleF : public Vec2i_VecFloatFloatFixture {};
    TEST_P(Vec2i_ConvertToDoubleF, Vec2i_ConvertToDouble)
    { 
        double expectX = (double)expectedX;
        double expectY = (double)expectedY;
        ASSERT_EQ(typeid(double), typeid(vector.toDouble().x));
        ASSERT_EQ(typeid(double), typeid(vector.toDouble().y));   
        ASSERT_EQ(expectX, vector.toDouble().x);
        ASSERT_EQ(expectY, vector.toDouble().y);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec2i_ConvertToDouble, Vec2i_ConvertToDoubleF, testing::Values(
        std::make_tuple(Vec2i(0, 0), 0., 0.),
        std::make_tuple(Vec2i(5, 5), 5., 5.),
        std::make_tuple(Vec2i(-5, -5), -5., -5.),
        std::make_tuple(Vec2i(10, -10), 10., -10.)
    ));

}