#include "pch.h"
#include <VecPlus/Vec3.h>
#include <iostream>

// TODO: Add tests for Vec2f::rotation(char axis, float angle);

using namespace vecp;

namespace Vec3f_Tests
{
    TEST(Vec3f_TestConstructorDefault, SetDefaultValues)
    {   
        Vec3f vector = Vec3f();
        ASSERT_FLOAT_EQ(vector.x, 0.0f);
        ASSERT_FLOAT_EQ(vector.y, 0.0f);
        ASSERT_FLOAT_EQ(vector.z, 0.0f);
    }

    // Constructor with specified values test
    TEST(Vec3f_TestConstructorValues, SetSpecifiedValues)
    {
        Vec3f vector = Vec3f(-3.5f, 4.2f, 1.5f);
        ASSERT_FLOAT_EQ(vector.x, -3.5f);
        ASSERT_FLOAT_EQ(vector.y, 4.2f);
        ASSERT_FLOAT_EQ(vector.z, 1.5f);
    }

    class Vec3f_VecScaVecFixture : public testing::TestWithParam<std::tuple<Vec3f, float, Vec3f>>
    {
    protected:
        void SetUp() override
        {
            vector = std::get<0>(GetParam());
            scalar = std::get<1>(GetParam());
            expected = std::get<2>(GetParam());
        }
        Vec3f vector, expected;
        float scalar;
    };

    class Vec3f_VecVecVecFixture : public testing::TestWithParam<std::tuple<Vec3f, Vec3f, Vec3f>>
    {
    protected:
        void SetUp() override
        {
            vectorOne = std::get<0>(GetParam());
            vectorTwo = std::get<1>(GetParam());
            expected = std::get<2>(GetParam());
        }
        Vec3f vectorOne, vectorTwo, expected;
    };

    // Vec3f operator + (const Vec3f& vector) const
    class Vec3f_AddVectorF : public Vec3f_VecVecVecFixture {};
    TEST_P(Vec3f_AddVectorF, Vec3f_AddVector)
    {
        Vec3f output = vectorOne + vectorTwo;
        ASSERT_FLOAT_EQ(expected.x, output.x);
        ASSERT_FLOAT_EQ(expected.y, output.y);
        ASSERT_FLOAT_EQ(expected.z, output.z);
    }

    INSTANTIATE_TEST_SUITE_P(Vec3f_AddVector, Vec3f_AddVectorF, testing::Values(
        std::make_tuple(Vec3f(1.1f, 2.2f, 3.3f), Vec3f(3.3f, 4.4f, 5.5f), Vec3f(4.4f, 6.6f, 8.8f)),
        std::make_tuple(Vec3f(-2.5f, 5.1f, -1.1f), Vec3f(7.2f, -3.3f, 2.2f), Vec3f(4.7f, 1.8f, 1.1f)),
        std::make_tuple(Vec3f(0.0f, -8.4f, 7.7f), Vec3f(-4.4f, 6.6f, -3.3f), Vec3f(-4.4f, -1.8f, 4.4f)),
        std::make_tuple(Vec3f(10.0f, -10.0f, 5.0f), Vec3f(-10.0f, 10.0f, -5.0f), Vec3f(0.0f, 0.0f, 0.0f))
    ));

    // void operator += (const Vec3f& vector)
    class Vec3f_AddEqualsVectorF : public Vec3f_VecVecVecFixture {};
    TEST_P(Vec3f_AddEqualsVectorF, Vec3f_AddEqualsVector)
    {
        vectorOne += vectorTwo;
        ASSERT_FLOAT_EQ(expected.x, vectorOne.x);
        ASSERT_FLOAT_EQ(expected.y, vectorOne.y);
        ASSERT_FLOAT_EQ(expected.z, vectorOne.z);
    }

    INSTANTIATE_TEST_SUITE_P(Vec3f_AddEqualsVector, Vec3f_AddEqualsVectorF, testing::Values(
        std::make_tuple(Vec3f(1.1f, 2.2f, 3.3f), Vec3f(3.3f, 4.4f, 5.5f), Vec3f(4.4f, 6.6f, 8.8f)),
        std::make_tuple(Vec3f(-2.5f, 5.1f, -1.1f), Vec3f(7.2f, -3.3f, 2.2f), Vec3f(4.7f, 1.8f, 1.1f)),
        std::make_tuple(Vec3f(0.0f, -8.4f, 7.7f), Vec3f(-4.4f, 6.6f, -3.3f), Vec3f(-4.4f, -1.8f, 4.4f)),
        std::make_tuple(Vec3f(10.0f, -10.0f, 5.0f), Vec3f(-10.0f, 10.0f, -5.0f), Vec3f(0.0f, 0.0f, 0.0f))
    ));

    // Vec3f operator - (const Vec3f& vector) const
    class Vec3f_SubtractVectorF : public Vec3f_VecVecVecFixture {};
    TEST_P(Vec3f_SubtractVectorF, Vec3f_SubtractVector)
    {
        Vec3f output = vectorOne - vectorTwo;
        ASSERT_FLOAT_EQ(expected.x, output.x);
        ASSERT_FLOAT_EQ(expected.y, output.y);
        ASSERT_FLOAT_EQ(expected.z, output.z);
    }

    INSTANTIATE_TEST_SUITE_P(Vec3f_SubtractVector, Vec3f_SubtractVectorF, testing::Values(
        std::make_tuple(Vec3f(5.5f, 7.7f, 2.2f), Vec3f(3.3f, 2.2f, 1.1f), Vec3f(2.2f, 5.5f, 1.1f)),
        std::make_tuple(Vec3f(10.0f, 10.0f, 5.5f), Vec3f(4.5f, 6.5f, 2.5f), Vec3f(5.5f, 3.5f, 3.0f)),
        std::make_tuple(Vec3f(-3.3f, 8.8f, -4.4f), Vec3f(2.2f, -5.5f, 1.1f), Vec3f(-5.5f, 14.3f, -5.5f)),
        std::make_tuple(Vec3f(0.0f, 0.0f, 0.0f), Vec3f(-7.7f, 9.9f, -1.1f), Vec3f(7.7f, -9.9f, 1.1f))
    ));

    // void operator -= (const Vec3f& vector)
    class Vec3f_SubtractEqualsVectorF : public Vec3f_VecVecVecFixture {};
    TEST_P(Vec3f_SubtractEqualsVectorF, Vec3f_SubtractEqualsVector)
    {
        vectorOne -= vectorTwo;
        ASSERT_FLOAT_EQ(expected.x, vectorOne.x);
        ASSERT_FLOAT_EQ(expected.y, vectorOne.y);
        ASSERT_FLOAT_EQ(expected.z, vectorOne.z);
    }

    INSTANTIATE_TEST_SUITE_P(Vec3f_SubtractEqualsVector, Vec3f_SubtractEqualsVectorF, testing::Values(
        std::make_tuple(Vec3f(5.5f, 7.7f, 2.2f), Vec3f(3.3f, 2.2f, 1.1f), Vec3f(2.2f, 5.5f, 1.1f)),
        std::make_tuple(Vec3f(10.0f, 10.0f, 5.5f), Vec3f(4.5f, 6.5f, 2.5f), Vec3f(5.5f, 3.5f, 3.0f)),
        std::make_tuple(Vec3f(-3.3f, 8.8f, -4.4f), Vec3f(2.2f, -5.5f, 1.1f), Vec3f(-5.5f, 14.3f, -5.5f)),
        std::make_tuple(Vec3f(0.0f, 0.0f, 0.0f), Vec3f(-7.7f, 9.9f, -1.1f), Vec3f(7.7f, -9.9f, 1.1f))
    ));

    // Vec3f operator * (float scalar) const
    class Vec3f_MultiplyByScalarF : public Vec3f_VecScaVecFixture {};
    TEST_P(Vec3f_MultiplyByScalarF, Vec3f_MultiplyByScalar)
    {
        Vec3f output = vector * scalar;
        ASSERT_FLOAT_EQ(expected.x, output.x);
        ASSERT_FLOAT_EQ(expected.y, output.y);   
        ASSERT_FLOAT_EQ(expected.z, output.z);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec3f_MultiplyByScalar, Vec3f_MultiplyByScalarF, testing::Values(
        std::make_tuple(Vec3f(0.0f, 0.0f, 0.0f), 10.0f, Vec3f(0.0f, 0.0f, 0.0f)),
        std::make_tuple(Vec3f(3.3f, 4.4f, 5.5f), 10.0f, Vec3f(33.0f, 44.0f, 55.0f)),
        std::make_tuple(Vec3f(-6.6f, 4.4f, -5.5f), 5.0f, Vec3f(-33.0f, 22.0f, -27.5f)),
        std::make_tuple(Vec3f(8.8f, -7.7f, 6.6f), -5.0f, Vec3f(-44.0f, 38.5f, -33.0f))
    ));

    // Vec3f operator * (const Vec3f& vector) const
    class Vec3f_MultiplyByVectorF : public Vec3f_VecVecVecFixture {};
    TEST_P(Vec3f_MultiplyByVectorF, Vec3f_MultiplyByVector)
    {
        Vec3f output = vectorOne * vectorTwo;
        ASSERT_FLOAT_EQ(expected.x, output.x);
        ASSERT_FLOAT_EQ(expected.y, output.y);   
        ASSERT_FLOAT_EQ(expected.z, output.z);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec3f_MultiplyByVector, Vec3f_MultiplyByVectorF, testing::Values(
        std::make_tuple(Vec3f(0.0f, 0.0f, 0.0f), Vec3f(10.0f, 10.0f, 10.0f), Vec3f(0.0f, 0.0f, 0.0f)),
        std::make_tuple(Vec3f(3.3f, 4.4f, 5.5f), Vec3f(5.5f, 10.0f, 2.0f), Vec3f(18.15f, 44.0f, 11.0f)),
        std::make_tuple(Vec3f(-6.6f, 4.4f, -3.3f), Vec3f(5.5f, -5.0f, 7.0f), Vec3f(-36.3f, -22.0f, -23.1f)),
        std::make_tuple(Vec3f(8.8f, -7.7f, 6.6f), Vec3f(-5.5f, -5.5f, 3.3f), Vec3f(-48.4f, 42.35f, 21.78f))
    ));

    // void operator *= (float scalar)
    class Vec3f_MultiplyEqualsByScalarF : public Vec3f_VecScaVecFixture {};
    TEST_P(Vec3f_MultiplyEqualsByScalarF, Vec3f_MultiplyEqualsByScalar)
    {
        vector *= scalar;
        ASSERT_FLOAT_EQ(expected.x, vector.x);
        ASSERT_FLOAT_EQ(expected.y, vector.y);   
        ASSERT_FLOAT_EQ(expected.z, vector.z);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec3f_MultiplyEqualsByScalar,Vec3f_MultiplyEqualsByScalarF, testing::Values(
        std::make_tuple(Vec3f(0.0f, 0.0f, 0.0f), 10.0f, Vec3f(0.0f, 0.0f, 0.0f)),
        std::make_tuple(Vec3f(3.3f, 4.4f, 5.5f), 10.0f, Vec3f(33.0f, 44.0f, 55.0f)),
        std::make_tuple(Vec3f(-6.6f, 4.4f, -5.5f), 5.0f, Vec3f(-33.0f, 22.0f, -27.5f)),
        std::make_tuple(Vec3f(8.8f, -7.7f, 6.6f), -5.0f, Vec3f(-44.0f, 38.5f, -33.0f))
    ));

    // void operator *= (const Vec3f& vector)
    class Vec3f_MultiplyEqualsByVectorF : public Vec3f_VecVecVecFixture {};
    TEST_P(Vec3f_MultiplyEqualsByVectorF, MultiplyEqualsByVector)
    {
        vectorOne *= vectorTwo;
        ASSERT_FLOAT_EQ(expected.x, vectorOne.x);
        ASSERT_FLOAT_EQ(expected.y, vectorOne.y);   
        ASSERT_FLOAT_EQ(expected.z, vectorOne.z);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec3f_MultiplyEqualsByVector, Vec3f_MultiplyEqualsByVectorF, testing::Values(
        std::make_tuple(Vec3f(0.0f, 0.0f, 0.0f), Vec3f(10.0f, 10.0f, 10.0f), Vec3f(0.0f, 0.0f, 0.0f)),
        std::make_tuple(Vec3f(3.3f, 4.4f, 5.5f), Vec3f(5.5f, 10.0f, 2.0f), Vec3f(18.15f, 44.0f, 11.0f)),
        std::make_tuple(Vec3f(-6.6f, 4.4f, -3.3f), Vec3f(5.5f, -5.0f, 7.0f), Vec3f(-36.3f, -22.0f, -23.1f)),
        std::make_tuple(Vec3f(8.8f, -7.7f, 6.6f), Vec3f(-5.5f, -5.5f, 3.3f), Vec3f(-48.4f, 42.35f, 21.78f))
    ));

    class Vec3f_VecVecBoolFixture : public testing::TestWithParam<std::tuple<Vec3f, Vec3f, bool>>
    {
    protected:
        void SetUp() override
        {
            vectorOne = std::get<0>(GetParam());
            vectorTwo = std::get<1>(GetParam());
            expected = std::get<2>(GetParam());
        }
        Vec3f vectorOne, vectorTwo;
        bool expected;
    };

    // bool operator == (const Vec3f& vector) const
    class Vec3f_CompareVectorsF : public Vec3f_VecVecBoolFixture {};
    TEST_P(Vec3f_CompareVectorsF, CompareVectors)
    {
        bool output = vectorOne == vectorTwo;
        ASSERT_EQ(expected, output);
    }

    INSTANTIATE_TEST_SUITE_P(Vec3f_CompareVectors, Vec3f_CompareVectorsF, testing::Values(
        std::make_tuple(Vec3f(-5.5f, 5.5f, 0.0f), Vec3f(-5.5f, 5.5f, 0.0f), true),
        std::make_tuple(Vec3f(0.0f, 0.0f, 0.0f), Vec3f(0.0f, 0.0f, 0.0f), true),
        std::make_tuple(Vec3f(-5.5f, 5.5f, 5.5f), Vec3f(5.5f, -5.5f, 5.5f), false),
        std::make_tuple(Vec3f(6.1f, 0.0f, 7.1f), Vec3f(7.1f, 0.0f, 6.1f), false)
    ));

    class Vec3f_VecVecScaFixture : public testing::TestWithParam<std::tuple<Vec3f, Vec3f, float>>
    {
    protected:
        void SetUp() override
        {
            vectorOne = std::get<0>(GetParam());
            vectorTwo = std::get<1>(GetParam());
            expected = std::get<2>(GetParam());
        }
        Vec3f vectorOne, vectorTwo;
        float expected;
    };

    // float mag() const
    class Vec3f_MagnitudeF : public Vec3f_VecVecScaFixture {};
    TEST_P(Vec3f_MagnitudeF, Vec3f_Magnitude)
    {
        float output = vectorOne.mag();
        ASSERT_FLOAT_EQ(expected, output);
    }

    INSTANTIATE_TEST_SUITE_P(Vec3f_Magnitude, Vec3f_MagnitudeF, testing::Values(
        std::make_tuple(Vec3f(5.f, 4.f, 3.f), Vec3f(0.f, 0.f, 0.f), 7.07106781f),
        std::make_tuple(Vec3f(-8.2f, 0.6f, -2.5f), Vec3f(0.f, 0.f, 0.f), 8.593602271f),
        std::make_tuple(Vec3f(-8.2f, -0.6f, 2.5f), Vec3f(0.f, 0.f, 0.f), 8.593602271f)
    ));

    // float mag(const Vec3f& vector) const
    class Vec3f_MagnitudeVectorF : public Vec3f_VecVecScaFixture {};
    TEST_P(Vec3f_MagnitudeVectorF, Vec3f_MagnitudeVector)
    {
        float output = vectorOne.mag(vectorTwo);
        ASSERT_NEAR(expected, output, 1E-05);
    }

    INSTANTIATE_TEST_SUITE_P(Vec3f_MagnitudeVector, Vec3f_MagnitudeVectorF, testing::Values(
        std::make_tuple(Vec3f(5.f, 4.f, 3.f), Vec3f(0.f, 0.f, 0.f), 7.07106781f),
        std::make_tuple(Vec3f(0.f, 0.f, 0.0f), Vec3f(5.f, 4.f, 3.f), 7.07106781f),
        std::make_tuple(Vec3f(-8.2f, 0.6f, -2.5f), Vec3f(5.9f, 4.6f, 1.3f), 15.14100393f),
        std::make_tuple(Vec3f(-8.2f, -0.6f, 2.5f), Vec3f(-5.9f, -4.6f, 1.3f), 4.767598976f)
    ));

    // Vec3f floor() const
    class Vec3f_FloorF : public Vec3f_VecScaVecFixture {};
    TEST_P(Vec3f_FloorF, Vec3f_Floor)
    {
        Vec3f output = vector.floor();
        ASSERT_NEAR(expected.x, output.x, 1E-06);
        ASSERT_NEAR(expected.y, output.y, 1E-06);
        ASSERT_NEAR(expected.z, output.z, 1E-06);
    }

    INSTANTIATE_TEST_SUITE_P(Vec3f_Floor, Vec3f_FloorF, testing::Values(
        std::make_tuple(Vec3f(5.45f, 4.667f, 3.1345f), 0.f, Vec3f(5.f, 4.f, 3.f)),
        std::make_tuple(Vec3f(-0.24f, 0.998f, -5.677f), 0.f, Vec3f(-1.f, 0.f, -6.f)),
        std::make_tuple(Vec3f(-4.998f, 12.3535f, -2.001f), 0.f, Vec3f(-5.f, 12.f, -3.f))
    ));

    // Vec3f floorAbs() const
    class Vec3f_FloorAbsF : public Vec3f_VecScaVecFixture {};
    TEST_P(Vec3f_FloorAbsF, Vec3f_FloorAbs)
    {
        Vec3f output = vector.floorAbs();
        ASSERT_NEAR(expected.x, output.x, 1E-06);
        ASSERT_NEAR(expected.y, output.y, 1E-06);
        ASSERT_NEAR(expected.z, output.z, 1E-06);
    }

    INSTANTIATE_TEST_SUITE_P(Vec3f_FloorAbs, Vec3f_FloorAbsF, testing::Values(
        std::make_tuple(Vec3f(5.45f, 4.667f, 3.1345f), 0.f, Vec3f(5.f, 4.f, 3.f)),
        std::make_tuple(Vec3f(-0.24f, 0.998f, -5.677f), 0.f, Vec3f(0.f, 0.f, -5.f)),
        std::make_tuple(Vec3f(-4.998f, 12.3535f, -2.001f), 0.f, Vec3f(-4.f, 12.f, -2.f))
    ));


   // Vec3d ceil() const
    class Vec3f_CeilF : public Vec3f_VecScaVecFixture {};
    TEST_P(Vec3f_CeilF, Vec3d_Ceil)
    {
        Vec3f output = vector.ceil();
        ASSERT_NEAR(expected.x, output.x, 1E-06);
        ASSERT_NEAR(expected.y, output.y, 1E-06);
        ASSERT_NEAR(expected.z, output.z, 1E-06);
    }

    INSTANTIATE_TEST_SUITE_P(Vec3f_Ceil, Vec3f_CeilF, testing::Values(
        std::make_tuple(Vec3f(5.45f, 4.667f, 3.1345f), 0.f, Vec3f(6.f, 5.f, 4.f)),
        std::make_tuple(Vec3f(-0.24f, 0.998f, -5.677f), 0.f, Vec3f(0.f, 1.f, -5.f)),
        std::make_tuple(Vec3f(-4.998f, 12.3535f, -2.001f), 0.f, Vec3f(-4.f, 13.f, -2.f))
    ));

    // Vec3f ceilAbs() const
    class Vec3f_CeilAbsF : public Vec3f_VecScaVecFixture {};
    TEST_P(Vec3f_CeilAbsF, Vec3f_CeilAbs)
    {
        Vec3f output = vector.ceilAbs();
        ASSERT_NEAR(expected.x, output.x, 1E-06);
        ASSERT_NEAR(expected.y, output.y, 1E-06);
        ASSERT_NEAR(expected.z, output.z, 1E-06);
    }

    INSTANTIATE_TEST_SUITE_P(Vec3f_CeilAbs, Vec3f_CeilAbsF, testing::Values(
        std::make_tuple(Vec3f(5.45f, 4.667f, 3.1345f), 0.f, Vec3f(6.f, 5.f, 4.f)),
        std::make_tuple(Vec3f(-0.24f, 0.998f, -5.677f), 0.f, Vec3f(-1.f, 1.f, -6.f)),
        std::make_tuple(Vec3f(-4.998f, 12.3535f, -2.001f), 0.f, Vec3f(-5.f, 13.f, -3.f))
    ));


    // Vec3f operator / (float scalar) const
    class Vec3f_DivideByScalarF : public Vec3f_VecScaVecFixture {};
    TEST_P(Vec3f_DivideByScalarF, Vec3f_DivideByScalar)
    {
        Vec3f output = vector / scalar;
        ASSERT_FLOAT_EQ(expected.x, output.x);
        ASSERT_FLOAT_EQ(expected.y, output.y);   
        ASSERT_FLOAT_EQ(expected.z, output.z);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec3f_DivideByScalar, Vec3f_DivideByScalarF, testing::Values(
        std::make_tuple(Vec3f(10.0f, 20.0f, 30.0f), 2.0f, Vec3f(5.0f, 10.0f, 15.0f)),
        std::make_tuple(Vec3f(-6.6f, 4.4f, -2.2f), -2.2f, Vec3f(3.0f, -2.0f, 1.0f)),
        std::make_tuple(Vec3f(10.0f, -5.0f, 2.5f), 2.0f, Vec3f(5.0f, -2.5f, 1.25f)),
        std::make_tuple(Vec3f(8.8f, -7.7f, 6.6f), 4.4f, Vec3f(2.0f, -1.75f, 1.5f)),
        std::make_tuple(Vec3f(9.0f, 12.0f, 15.0f), 3.0f, Vec3f(3.0f, 4.0f, 5.0f))  
    ));

    // Vec3f operator / (const Vec3f& vector) const
    class Vec3f_DivideByVectorF : public Vec3f_VecVecVecFixture {};
    TEST_P(Vec3f_DivideByVectorF, Vec3f_DivideByVector)
    {
        Vec3f output = vectorOne / vectorTwo;
        ASSERT_FLOAT_EQ(expected.x, output.x);
        ASSERT_FLOAT_EQ(expected.y, output.y);   
        ASSERT_FLOAT_EQ(expected.z, output.z);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec3f_DivideByVector, Vec3f_DivideByVectorF, testing::Values(
        std::make_tuple(Vec3f(10.0f, 20.0f, 30.0f), Vec3f(2.0f, 4.0f, 6.0f), Vec3f(5.0f, 5.0f, 5.0f)),
        std::make_tuple(Vec3f(-6.6f, 4.4f, -2.2f), Vec3f(-2.2f, 2.2f, 1.1f), Vec3f(3.0f, 2.0f, -2.0f)),
        std::make_tuple(Vec3f(10.0f, -5.0f, 2.5f), Vec3f(2.0f, -5.0f, 0.5f), Vec3f(5.0f, 1.0f, 5.0f)),
        std::make_tuple(Vec3f(8.8f, -7.7f, 6.6f), Vec3f(4.4f, -7.7f, 3.3f), Vec3f(2.0f, 1.0f, 2.0f))
    ));

    // void operator /= (float scalar)
    class Vec3f_DivideEqualsByScalarF : public Vec3f_VecScaVecFixture {};
    TEST_P(Vec3f_DivideEqualsByScalarF, Vec3f_DivideEqualsByScalar)
    {
        vector /= scalar;
        ASSERT_FLOAT_EQ(expected.x, vector.x);
        ASSERT_FLOAT_EQ(expected.y, vector.y);   
        ASSERT_FLOAT_EQ(expected.z, vector.z);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec3f_DivideEqualsByScalar, Vec3f_DivideEqualsByScalarF, testing::Values(
        std::make_tuple(Vec3f(10.0f, 20.0f, 30.0f), 2.0f, Vec3f(5.0f, 10.0f, 15.0f)),
        std::make_tuple(Vec3f(-6.6f, 4.4f, -2.2f), -2.2f, Vec3f(3.0f, -2.0f, 1.0f)),
        std::make_tuple(Vec3f(10.0f, -5.0f, 2.5f), 2.0f, Vec3f(5.0f, -2.5f, 1.25f)),
        std::make_tuple(Vec3f(8.8f, -7.7f, 6.6f), 4.4f, Vec3f(2.0f, -1.75f, 1.5f))
    ));

    // void operator /= (const Vec3f& vector)
    class Vec3f_DivideEqualsByVectorF : public Vec3f_VecVecVecFixture {};
    TEST_P(Vec3f_DivideEqualsByVectorF, Vec3f_DivideEqualsByVector)
    {
        vectorOne /= vectorTwo;
        ASSERT_FLOAT_EQ(expected.x, vectorOne.x);
        ASSERT_FLOAT_EQ(expected.y, vectorOne.y);   
        ASSERT_FLOAT_EQ(expected.z, vectorOne.z);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec3f_DivideEqualsByVector, Vec3f_DivideEqualsByVectorF, testing::Values(
        std::make_tuple(Vec3f(10.0f, 20.0f, 30.0f), Vec3f(2.0f, 4.0f, 6.0f), Vec3f(5.0f, 5.0f, 5.0f)),
        std::make_tuple(Vec3f(-6.6f, 4.4f, -2.2f), Vec3f(-2.2f, 2.2f, 1.1f), Vec3f(3.0f, 2.0f, -2.0f)),
        std::make_tuple(Vec3f(10.0f, -5.0f, 2.5f), Vec3f(2.0f, -5.0f, 0.5f), Vec3f(5.0f, 1.0f, 5.0f)),
        std::make_tuple(Vec3f(8.8f, -7.7f, 6.6f), Vec3f(4.4f, -7.7f, 3.3f), Vec3f(2.0f, 1.0f, 2.0f))
    ));

    // float Vec3f::dot(const Vec3f& vector) const
    class Vec3f_DotVectorF : public Vec3f_VecVecScaFixture {};
    TEST_P(Vec3f_DotVectorF, Vec3f_DotVector)
    {
        float output = vectorOne.dot(vectorTwo);
        ASSERT_NEAR(expected, output, 1E-05);
    }

    INSTANTIATE_TEST_SUITE_P(Vec3f_DotVector, Vec3f_DotVectorF, testing::Values(
        std::make_tuple(Vec3f(5.f, 4.f, 3.f), Vec3f(6.2f, 2.f, 1.1f), 42.3f),
        std::make_tuple(Vec3f(-5.f, -4.f, -3.f), Vec3f(-6.2f, 3.f, 1.1f), 15.7f),
        std::make_tuple(Vec3f(-5.f, 4.f, 3.f), Vec3f(6.2f, 1.f, -1.1f), -30.3f),
        std::make_tuple(Vec3f(5.f, -4.f, 3.f), Vec3f(6.2f, -2.5f, 1.1f), 44.3f)
    ));

    // double Vec3d::dot(double scalar) const
    class Vec3f_DotScalarF : public Vec3f_VecVecScaFixture {};
    TEST_P(Vec3f_DotScalarF, Vec3f_DotScalar)
    {
        float output = vectorOne.dot(vectorTwo.x);
        ASSERT_NEAR(expected, output, 1E-06);
    }

    INSTANTIATE_TEST_SUITE_P(Vec3f_DotScalar, Vec3f_DotScalarF, testing::Values(
        std::make_tuple(Vec3f(5.f, 4.f, 3.f), Vec3f(6.2f, 0.f, 0.f), 74.4f),
        std::make_tuple(Vec3f(-5.f, -4.f, -3.f), Vec3f(-6.2f, 0.f, 0.f), 74.4f),
        std::make_tuple(Vec3f(-5.f, 4.f, 3.f), Vec3f(0.f, 0.f, 0.f), 0.f),
        std::make_tuple(Vec3f(5.f, -4.f, 3.f), Vec3f(-1.1f, 0.f, 0.f), -4.4f)
    ));


    // double Vec3d::dot(double xTwo, double yTwo, double zTwo) const
    class Vec3f_DotScalarScalarF : public Vec3f_VecVecScaFixture {};
    TEST_P(Vec3f_DotScalarScalarF, Vec3f_DotScalarScalar)
    {
        float output = vectorOne.dot(vectorTwo.x, vectorTwo.y, vectorTwo.z);
        ASSERT_NEAR(expected, output, 1E-06);
    }

    INSTANTIATE_TEST_SUITE_P(Vec3f_DotScalarScalar, Vec3f_DotScalarScalarF, testing::Values(
        std::make_tuple(Vec3f(5.f, 4.f, 3.f), Vec3f(6.2f, 2.f, 1.1f), 42.3f),
        std::make_tuple(Vec3f(-5.f, -4.f, -3.f), Vec3f(-6.2f, 3.f, 1.1f), 15.7f),
        std::make_tuple(Vec3f(-5.f, 4.f, 3.f), Vec3f(6.2f, 1.f, -1.1f), -30.3f),
        std::make_tuple(Vec3f(5.f, -4.f, 3.f), Vec3f(6.2f, -2.5f, 1.1f), 44.3f)
    ));


    // Vec3f Vec3f::normalize() const
    class Vec3f_NormaliseF : public Vec3f_VecVecVecFixture {};
    TEST_P(Vec3f_NormaliseF, Vec3f_Normalise)
    {
        Vec3f output = vectorOne.normalise();
        ASSERT_NEAR(expected.x, output.x, 1E-05);
        ASSERT_NEAR(expected.y, output.y, 1E-05);
        ASSERT_NEAR(expected.z, output.z, 1E-05);
    }

    INSTANTIATE_TEST_SUITE_P(Vec3f_Normalise, Vec3f_NormaliseF, testing::Values(
        std::make_tuple(Vec3f(5.f, 5.f, 5.f), Vec3f(0.f, 0.f, 0.f), Vec3f(0.57735f, 0.57735f, 0.57735f)),
        std::make_tuple(Vec3f(-5.f, -5.f, -5.f), Vec3f(0.f, 0.f, 0.f), Vec3f(-0.57735f, -0.57735f, -0.57735f)),
        std::make_tuple(Vec3f(-6.f, 8.f, -10.f), Vec3f(0.f, 0.f, 0.f), Vec3f(-0.42426f, 0.56569f, -0.70711f))
    ));

    class Vec3f_VecFloatFloatFixture : public testing::TestWithParam<std::tuple<Vec3f, float, float, float>>
    {
        protected:
            void SetUp() override
            {
                vector = std::get<0>(GetParam());
                expectedX = std::get<1>(GetParam());
                expectedY = std::get<2>(GetParam());
                expectedZ = std::get<3>(GetParam());
            }
            Vec3f vector;
            float expectedX, expectedY, expectedZ;
    };

    // Vec3f Vec3f::toFloat() const
    class Vec3f_ConvertToFloatF : public Vec3f_VecFloatFloatFixture {};
    TEST_P(Vec3f_ConvertToFloatF, Vec3f_ConvertToFloat)
    { 
        ASSERT_EQ(typeid(float), typeid(vector.toFloat().x));
        ASSERT_EQ(typeid(float), typeid(vector.toFloat().y));   
        ASSERT_EQ(typeid(float), typeid(vector.toFloat().z));   
        ASSERT_EQ(expectedX, vector.toFloat().x);
        ASSERT_EQ(expectedY, vector.toFloat().y);   
        ASSERT_EQ(expectedZ, vector.toFloat().z);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec3f_ConvertToFloat, Vec3f_ConvertToFloatF, testing::Values(
        std::make_tuple(Vec3f(0.f, 0.f, 0.f), 0.f, 0.f, 0.f),
        std::make_tuple(Vec3f(5.2f, 5.2f, 5.2f), 5.2f, 5.2f, 5.2f),
        std::make_tuple(Vec3f(-5.2f, -5.2f, -5.2f), -5.2f, -5.2f, -5.2f),
        std::make_tuple(Vec3f(10.09f, -10.09f, 20.18f), 10.09f, -10.09f, 20.18f)
    ));

    // Vec3d Vec3f::toDouble() const
    class Vec3f_ConvertToDoubleF : public Vec3f_VecFloatFloatFixture {};
    TEST_P(Vec3f_ConvertToDoubleF, Vec3f_ConvertToDouble)
    { 
        double expectX = (double)expectedX;
        double expectY = (double)expectedY;
        double expectZ = (double)expectedZ;
        ASSERT_EQ(typeid(double), typeid(vector.toDouble().x));
        ASSERT_EQ(typeid(double), typeid(vector.toDouble().y));   
        ASSERT_EQ(typeid(double), typeid(vector.toDouble().z));   
        ASSERT_NEAR(expectX, vector.toDouble().x, 1E-05);
        ASSERT_NEAR(expectY, vector.toDouble().y, 1E-05);   
        ASSERT_NEAR(expectZ, vector.toDouble().z, 1E-05);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec3f_ConvertToDouble, Vec3f_ConvertToDoubleF, testing::Values(
        std::make_tuple(Vec3f(0.f, 0.f, 0.f), 0.f, 0.f, 0.f),
        std::make_tuple(Vec3f(5.2f, 5.2f, 5.2f), 5.2f, 5.2f, 5.2f),
        std::make_tuple(Vec3f(-5.2f, -5.2f, -5.2f), -5.2f, -5.2f, -5.2f),
        std::make_tuple(Vec3f(10.09f, -10.09f, 20.18f), 10.09f, -10.09f, 20.18f)
    ));

}