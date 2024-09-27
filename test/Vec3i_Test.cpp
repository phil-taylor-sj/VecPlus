#include "pch.h"
#include <VecPlus/Vec3.h>
#include <iostream>

using namespace vecp;

namespace Vec3i_Tests
{
    TEST(Vec3i_TestConstructorDefault, SetDefaultValues)
    {   
        Vec3i vector = Vec3i();
        ASSERT_EQ(vector.x, 0);
        ASSERT_EQ(vector.y, 0);
        ASSERT_EQ(vector.z, 0);
    }

    TEST(Vec3i_TestConstructorValues, SetSpecifiedValues)
    {
        Vec3i vector = Vec3i(-3, 4, 5);
        ASSERT_EQ(vector.x, -3);
        ASSERT_EQ(vector.y, 4);
        ASSERT_EQ(vector.z, 5);
    }

    class Vec3i_VecScaVecFixture : public testing::TestWithParam<std::tuple<Vec3i, int, Vec3i>>
    {
        protected:
            void SetUp() override
            {
                vector = std::get<0>(GetParam());
                scalar = std::get<1>(GetParam());
                expected = std::get<2>(GetParam());
            }
            Vec3i vector, expected;
            int scalar;
    };

    class Vec3i_VecVecVecFixture : public testing::TestWithParam<std::tuple<Vec3i, Vec3i, Vec3i>>
    {
        protected:
            void SetUp() override
            {
                vectorOne = std::get<0>(GetParam());
                vectorTwo = std::get<1>(GetParam());
                expected = std::get<2>(GetParam());
            }
            Vec3i vectorOne, vectorTwo, expected;
    };

   class Vec3i_VecScaScaFixture : public testing::TestWithParam<std::tuple<Vec3i, int, int>>
    {
        protected:
            void SetUp() override
            {
                vector = std::get<0>(GetParam());
                scalar = std::get<1>(GetParam());
                expected = std::get<2>(GetParam());
            }
            Vec3i vector;
            int scalar, expected;
    };

    // Vec3i abs() const
    class Vec3i_AbsF : public Vec3i_VecScaVecFixture {};
    TEST_P(Vec3i_AbsF, Vec3i_Abs)
    {
        Vec3i output = vector.abs();
        ASSERT_EQ(expected.x, output.x);
        ASSERT_EQ(expected.y, output.y);
    }

    INSTANTIATE_TEST_SUITE_P(Vec3i_Abs, Vec3i_AbsF, testing::Values(
        std::make_tuple(Vec3i(0, 0, 0), 0, Vec3i(0, 0, 0)),
        std::make_tuple(Vec3i(-2, 5, -8), 0, Vec3i(2, 5, 8)),
        std::make_tuple(Vec3i(-16, -8, -10), 0, Vec3i(16, 8, 10))
    ));

    // int max() const
    class Vec3i_MaxF : public Vec3i_VecScaScaFixture {};
    TEST_P(Vec3i_MaxF, Vec3i_Max)
    {
        int output = vector.max();
        ASSERT_EQ(expected, output);
    }

    INSTANTIATE_TEST_SUITE_P(Vec3i_Max, Vec3i_MaxF, testing::Values(
        std::make_tuple(Vec3i(0, 0, 0), 0, 0),
        std::make_tuple(Vec3i(-2, 5, 5), 0, 5),
        std::make_tuple(Vec3i(0, -16, -8), 0, 0),
        std::make_tuple(Vec3i(8, -8, -10), 0, 8) 
    ));

    // int min() const
    class Vec3i_MinF : public Vec3i_VecScaScaFixture {};
    TEST_P(Vec3i_MinF, Vec3i_Min)
    {
        int output = vector.min();
        ASSERT_EQ(expected, output);
    }

    INSTANTIATE_TEST_SUITE_P(Vec3i_Min, Vec3i_MinF, testing::Values(
        std::make_tuple(Vec3i(0, 0, 0), 0, 0),
        std::make_tuple(Vec3i(2, 5, 2), 0, 2),
        std::make_tuple(Vec3i(0, -16, -8), 0, -16),
        std::make_tuple(Vec3i(8, 10, -10), 0, -10) 
    ));

    // Vec3i operator + (const Vec3i& vector) const
    class Vec3i_AddVectorF : public Vec3i_VecVecVecFixture {};
    TEST_P(Vec3i_AddVectorF, Vec3i_AddVector)
    {
        Vec3i output = vectorOne + vectorTwo;
        ASSERT_EQ(expected.x, output.x);
        ASSERT_EQ(expected.y, output.y);
        ASSERT_EQ(expected.z, output.z);
    }

    INSTANTIATE_TEST_SUITE_P(Vec3i_AddVector, Vec3i_AddVectorF, testing::Values(
        std::make_tuple(Vec3i(1, 2, 3), Vec3i(3, 4, 5), Vec3i(4, 6, 8)),
        std::make_tuple(Vec3i(-2, 5, 7), Vec3i(7, -3, 2), Vec3i(5, 2, 9)),
        std::make_tuple(Vec3i(0, -8, 10), Vec3i(-4, 6, -10), Vec3i(-4, -2, 0)),
        std::make_tuple(Vec3i(10, -10, 0), Vec3i(-10, 10, 5), Vec3i(0, 0, 5))
    ));


    // void operator += (const Vec3i& vector)
    class Vec3i_AddEqualsVectorF : public Vec3i_VecVecVecFixture {};
    TEST_P(Vec3i_AddEqualsVectorF, Vec3i_AddEqualsVector)
    {
        vectorOne += vectorTwo;
        ASSERT_EQ(expected.x, vectorOne.x);
        ASSERT_EQ(expected.y, vectorOne.y);
        ASSERT_EQ(expected.z, vectorOne.z);
    }

    INSTANTIATE_TEST_SUITE_P(Vec3i_AddEqualsVector, Vec3i_AddEqualsVectorF, testing::Values(
        std::make_tuple(Vec3i(1, 2, 3), Vec3i(3, 4, 5), Vec3i(4, 6, 8)),
        std::make_tuple(Vec3i(-2, 5, 7), Vec3i(7, -3, 2), Vec3i(5, 2, 9)),
        std::make_tuple(Vec3i(0, -8, 10), Vec3i(-4, 6, -10), Vec3i(-4, -2, 0)),
        std::make_tuple(Vec3i(10, -10, 0), Vec3i(-10, 10, 5), Vec3i(0, 0, 5))
    ));

    // Vec3i operator - (const Vec3i& vector) const
    class Vec3i_SubtractVectorF : public Vec3i_VecVecVecFixture {};
    TEST_P(Vec3i_SubtractVectorF, Vec3i_SubtractVector)
    {
        Vec3i output = vectorOne - vectorTwo;
        ASSERT_EQ(expected.x, output.x);
        ASSERT_EQ(expected.y, output.y);
        ASSERT_EQ(expected.z, output.z);
    }

    INSTANTIATE_TEST_SUITE_P(Vec3i_SubtractVector, Vec3i_SubtractVectorF, testing::Values(
        std::make_tuple(Vec3i(5, 7, 10), Vec3i(3, 2, 4), Vec3i(2, 5, 6)),
        std::make_tuple(Vec3i(10, 10, 10), Vec3i(4, 6, 7), Vec3i(6, 4, 3)),
        std::make_tuple(Vec3i(-3, 8, -9), Vec3i(2, -5, 1), Vec3i(-5, 13, -10)),
        std::make_tuple(Vec3i(0, 0, 0), Vec3i(-7, 9, 8), Vec3i(7, -9, -8))
    ));

    // void operator -= (const Vec3i& vector)
    class Vec3i_SubtractEqualsVectorF : public Vec3i_VecVecVecFixture {};
    TEST_P(Vec3i_SubtractEqualsVectorF, Vec3i_SubtractEqualsVector)
    {
        vectorOne -= vectorTwo;
        ASSERT_EQ(expected.x, vectorOne.x);
        ASSERT_EQ(expected.y, vectorOne.y);
        ASSERT_EQ(expected.z, vectorOne.z);
    }

    INSTANTIATE_TEST_SUITE_P(Vec3i_SubtractEqualsVector, Vec3i_SubtractEqualsVectorF, testing::Values(
        std::make_tuple(Vec3i(5, 7, 10), Vec3i(3, 2, 4), Vec3i(2, 5, 6)),
        std::make_tuple(Vec3i(10, 10, 10), Vec3i(4, 6, 7), Vec3i(6, 4, 3)),
        std::make_tuple(Vec3i(-3, 8, -9), Vec3i(2, -5, 1), Vec3i(-5, 13, -10)),
        std::make_tuple(Vec3i(0, 0, 0), Vec3i(-7, 9, 8), Vec3i(7, -9, -8))
    ));

    // Vec3i operator * (int scalar) const
    class Vec3i_MultiplyByScalarF : public Vec3i_VecScaVecFixture {};
    TEST_P(Vec3i_MultiplyByScalarF, Vec3i_MultiplyByScalar)
    {
        Vec3i output = vector * scalar;
        ASSERT_EQ(expected.x, output.x);
        ASSERT_EQ(expected.y, output.y);   
        ASSERT_EQ(expected.z, output.z);
    }

    INSTANTIATE_TEST_SUITE_P(Vec3i_MultiplyByScalar, Vec3i_MultiplyByScalarF, testing::Values(
        std::make_tuple(Vec3i(0, 0, 0), 10, Vec3i(0, 0, 0)),
        std::make_tuple(Vec3i(3, 4, 5), 10, Vec3i(30, 40, 50)),
        std::make_tuple(Vec3i(-6, 4, -2), 5, Vec3i(-30, 20, -10)),
        std::make_tuple(Vec3i(8, -7, 6), -5, Vec3i(-40, 35, -30))
    ));

    // Vec3i operator * (const Vec3i& vector) const
    class Vec3i_MultiplyByVectorF : public Vec3i_VecVecVecFixture {};
    TEST_P(Vec3i_MultiplyByVectorF, Vec3i_MultiplyByVector)
    {
        Vec3i output = vectorOne * vectorTwo;
        ASSERT_EQ(expected.x, output.x);
        ASSERT_EQ(expected.y, output.y);   
        ASSERT_EQ(expected.z, output.z);
    }

    INSTANTIATE_TEST_SUITE_P(Vec3i_MultiplyByVector, Vec3i_MultiplyByVectorF, testing::Values(
        std::make_tuple(Vec3i(0, 0, 0), Vec3i(10, 10, 10), Vec3i(0, 0, 0)),
        std::make_tuple(Vec3i(3, 4, 5), Vec3i(5, 10, 2), Vec3i(15, 40, 10)),
        std::make_tuple(Vec3i(-6, 4, 3), Vec3i(5, -5, 7), Vec3i(-30, -20, 21)),
        std::make_tuple(Vec3i(8, -7, 6), Vec3i(-5, -5, 3), Vec3i(-40, 35, 18))
    ));

    // void operator *= (int scalar)
    class Vec3i_MultiplyEqualsByScalarF : public Vec3i_VecScaVecFixture {};
    TEST_P(Vec3i_MultiplyEqualsByScalarF, Vec3i_MultiplyEqualsByScalar)
    {
        vector *= scalar;
        ASSERT_EQ(expected.x, vector.x);
        ASSERT_EQ(expected.y, vector.y);   
        ASSERT_EQ(expected.z, vector.z);
    }
    
    INSTANTIATE_TEST_SUITE_P(Vec3i_MultiplyEqualsByScalar, Vec3i_MultiplyEqualsByScalarF, testing::Values(
        std::make_tuple(Vec3i(0, 0, 0), 10, Vec3i(0, 0, 0)),
        std::make_tuple(Vec3i(3, 4, 5), 10, Vec3i(30, 40, 50)),
        std::make_tuple(Vec3i(-6, 4, -2), 5, Vec3i(-30, 20, -10)),
        std::make_tuple(Vec3i(8, -7, 6), -5, Vec3i(-40, 35, -30))
    ));

    // void operator *= (const Vec3i& vector)
    class Vec3i_MultiplyEqualsByVectorF : public Vec3i_VecVecVecFixture {};
    TEST_P(Vec3i_MultiplyEqualsByVectorF, Vec3i_MultiplyEqualsByVector)
    {
        vectorOne *= vectorTwo;
        ASSERT_EQ(expected.x, vectorOne.x);
        ASSERT_EQ(expected.y, vectorOne.y);   
        ASSERT_EQ(expected.z, vectorOne.z);
    }
    
    INSTANTIATE_TEST_SUITE_P(Vec3i_MultiplyEqualsByVector, Vec3i_MultiplyEqualsByVectorF, testing::Values(
        std::make_tuple(Vec3i(0, 0, 0), Vec3i(10, 10, 10), Vec3i(0, 0, 0)),
        std::make_tuple(Vec3i(3, 4, 5), Vec3i(5, 10, 2), Vec3i(15, 40, 10)),
        std::make_tuple(Vec3i(-6, 4, 3), Vec3i(5, -5, 7), Vec3i(-30, -20, 21)),
        std::make_tuple(Vec3i(8, -7, 6), Vec3i(-5, -5, 3), Vec3i(-40, 35, 18))
    ));

    class Vec3i_VecVecBoolFixture : public testing::TestWithParam<std::tuple<Vec3i, Vec3i, bool>>
    {
        protected:
            void SetUp() override
            {
                vectorOne = std::get<0>(GetParam());
                vectorTwo = std::get<1>(GetParam());
                expected = std::get<2>(GetParam());
            }
            Vec3i vectorOne, vectorTwo;
            bool expected;
    };

    // bool operator == (const Vec3i& vector) const
    class Vec3i_CompareVectorsF : public Vec3i_VecVecBoolFixture {};
    TEST_P(Vec3i_CompareVectorsF, Vec3i_CompareVectors)
    {
        bool output = vectorOne == vectorTwo;
        ASSERT_EQ(expected, output);
        ASSERT_EQ(expected, output);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec3i_CompareVectors, Vec3i_CompareVectorsF, testing::Values(
        std::make_tuple(Vec3i(-5, 5, 0), Vec3i(-5, 5, 0), true),
        std::make_tuple(Vec3i(0, 0, 0), Vec3i(0, 0, 0), true),
        std::make_tuple(Vec3i(-5, 5, 5), Vec3i(5, -5, 5), false),
        std::make_tuple(Vec3i(6, 0, 7), Vec3i(7, 0, 6), false)
    ));


    class Vec3i_VecFloatFloatFixture : public testing::TestWithParam<std::tuple<Vec3i, float, float, float>>
    {
        protected:
            void SetUp() override
            {
                vector = std::get<0>(GetParam());
                expectedX = std::get<1>(GetParam());
                expectedY = std::get<2>(GetParam());
                expectedZ = std::get<3>(GetParam());
            }
            Vec3i vector;
            float expectedX, expectedY, expectedZ;
    };

    // Vec3f toFloat() const
    class Vec3i_ConvertToFloatF : public Vec3i_VecFloatFloatFixture {};
    TEST_P(Vec3i_ConvertToFloatF, Vec3i_ConvertToFloat)
    { 
        ASSERT_EQ(typeid(float), typeid(vector.toFloat().x));
        ASSERT_EQ(typeid(float), typeid(vector.toFloat().y));   
        ASSERT_EQ(typeid(float), typeid(vector.toFloat().z));   
        ASSERT_EQ(expectedX, vector.toFloat().x);
        ASSERT_EQ(expectedY, vector.toFloat().y);   
        ASSERT_EQ(expectedZ, vector.toFloat().z);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec3i_ConvertToFloat, Vec3i_ConvertToFloatF, testing::Values(
        std::make_tuple(Vec3i(0, 0, 0), 0.f, 0.f, 0.f),
        std::make_tuple(Vec3i(5, 5, 5), 5.f, 5.f, 5.f),
        std::make_tuple(Vec3i(-5, -5, -5), -5.f, -5.f, -5.f),
        std::make_tuple(Vec3i(10, -10, 20), 10.f, -10.f, 20.f)
    ));

    // Vec3d toDouble() const
    class Vec3i_ConvertToDoubleF : public Vec3i_VecFloatFloatFixture {};
    TEST_P(Vec3i_ConvertToDoubleF, Vec3i_ConvertToDouble)
    { 
        double expectX = (double)expectedX;
        double expectY = (double)expectedY;
        double expectZ = (double)expectedZ;
        ASSERT_EQ(typeid(double), typeid(vector.toDouble().x));
        ASSERT_EQ(typeid(double), typeid(vector.toDouble().y));   
        ASSERT_EQ(typeid(double), typeid(vector.toDouble().z));   
        ASSERT_EQ(expectX, vector.toDouble().x);
        ASSERT_EQ(expectY, vector.toDouble().y);   
        ASSERT_EQ(expectZ, vector.toDouble().z);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec3i_ConvertToDouble, Vec3i_ConvertToDoubleF, testing::Values(
        std::make_tuple(Vec3i(0, 0, 0), 0., 0., 0.),
        std::make_tuple(Vec3i(5, 5, 5), 5., 5., 5.),
        std::make_tuple(Vec3i(-5, -5, -5), -5., -5., -5.),
        std::make_tuple(Vec3i(10, -10, 20), 10., -10., 20.)
    ));
}