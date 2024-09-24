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

    // float mag() const
    class Vec2f_MagnitudeF : public Vec2f_VecVecScaFixture {};
    TEST_P(Vec2f_MagnitudeF, Vec2f_Magnitude)
    {
        float output = vectorOne.mag();
        ASSERT_FLOAT_EQ(expected, output);
    }

    INSTANTIATE_TEST_SUITE_P(Vec2f_Magnitude, Vec2f_MagnitudeF, testing::Values(
        std::make_tuple(Vec2f(5.f, 4.f), Vec2f(0.f, 0.f), 6.40312423f),
        std::make_tuple(Vec2f(-8.2f, 0.6f), Vec2f(0.f, 0.f), 8.221922f),
        std::make_tuple(Vec2f(-8.2f, -0.6f), Vec2f(0.f, 0.f), 8.221922f)
    ));

    // float mag(const Vec2f& vector) const
    class Vec2f_MagnitudeVectorF : public Vec2f_VecVecScaFixture {};
    TEST_P(Vec2f_MagnitudeVectorF, Vec2f_MagnitudeVector)
    {
        float output = vectorOne.mag(vectorTwo);
        ASSERT_FLOAT_EQ(expected, output);
    }

    INSTANTIATE_TEST_SUITE_P(Vec2f_MagnitudeVector, Vec2f_MagnitudeVectorF, testing::Values(
        std::make_tuple(Vec2f(5.f, 4.f), Vec2f(0.f, 0.f), 6.40312423f),
        std::make_tuple(Vec2f(0.f, 0.f), Vec2f(5.f, 4.f), 6.40312423f),
        std::make_tuple(Vec2f(-8.2f, 0.6f), Vec2f(5.9f, 4.6f), 14.656398f),
        std::make_tuple(Vec2f(-8.2f, -0.6f), Vec2f(-5.9f, -4.6f), 4.61410880f)
    ));

    // Vec2f rotate(float scalar) const
    class Vec2f_RotateF : public Vec2f_VecScaVecFixture {};
    TEST_P(Vec2f_RotateF, Vec2f_Rotate)
    {
        Vec2f output = vector.rotate(scalar);
        ASSERT_NEAR(expected.x, output.x, 1E-06);
        ASSERT_NEAR(expected.y, output.y, 1E-06);
    } 

    INSTANTIATE_TEST_SUITE_P(Vec2f_Rotate, Vec2f_RotateF, testing::Values(
        std::make_tuple(Vec2f(5.f, 5.f), 0.f, Vec2f(5.f, 5.f)),
        std::make_tuple(Vec2f(5.f, 0.f), 90.f, Vec2f(0.f, 5.f)),
        std::make_tuple(Vec2f(5.f, 0.f), 270.f, Vec2f(0.f, -5.f)),
        std::make_tuple(Vec2f(5.f, 0.f), 180.f, Vec2f(-5.f, 0.f))
    ));

    // Vec2f floor() const
    class Vec2f_FloorF : public Vec2f_VecScaVecFixture {};
    TEST_P(Vec2f_FloorF, Vec2f_Floor)
    {
        Vec2f output = vector.floor();
        ASSERT_NEAR(expected.x, output.x, 1E-06);
        ASSERT_NEAR(expected.y, output.y, 1E-06);
    }

    INSTANTIATE_TEST_SUITE_P(Vec2f_Floor, Vec2f_FloorF, testing::Values(
        std::make_tuple(Vec2f(5.45f, 4.667f), 0.f, Vec2f(5.f, 4.f)),
        std::make_tuple(Vec2f(-0.24f, 0.998f), 0.f, Vec2f(-1.f, 0.f)),
        std::make_tuple(Vec2f(-4.998f, 12.35345f), 0.f, Vec2f(-5.f, 12.f)),
        std::make_tuple(Vec2f( -5.677f, -2.001f), 0.f, Vec2f(-6.f, -3.f))
    ));

    // Vec2f floorAbs() const
    class Vec2f_FloorAbsF : public Vec2f_VecScaVecFixture {};
    TEST_P(Vec2f_FloorAbsF, Vec2f_FloorAbs)
    {
        Vec2f output = vector.floorAbs();
        ASSERT_NEAR(expected.x, output.x, 1E-06);
        ASSERT_NEAR(expected.y, output.y, 1E-06);
    }

    INSTANTIATE_TEST_SUITE_P(Vec2f_FloorAbs, Vec2f_FloorAbsF, testing::Values(
        std::make_tuple(Vec2f(5.45f, 4.667f), 0.f, Vec2f(5.f, 4.f)),
        std::make_tuple(Vec2f(-0.24f, 0.998f), 0.f, Vec2f(0.f, 0.f)),
        std::make_tuple(Vec2f(-4.998f, 12.3535f), 0.f, Vec2f(-4.f, 12.f)),
        std::make_tuple(Vec2f(-5.677f, -2.001f), 0.f, Vec2f(-5.f, -2.f)) 
    ));

  // Vec2f ceil() const
    class Vec2f_CeilF : public Vec2f_VecScaVecFixture {};
    TEST_P(Vec2f_CeilF, Vec2f_Ceil)
    {
        Vec2f output = vector.ceil();
        ASSERT_NEAR(expected.x, output.x, 1E-06);
        ASSERT_NEAR(expected.y, output.y, 1E-06);
    }

    INSTANTIATE_TEST_SUITE_P(Vec2f_Ceil, Vec2f_CeilF, testing::Values(
        std::make_tuple(Vec2f(5.45f, 4.667f), 0.f, Vec2f(6.f, 5.f)),
        std::make_tuple(Vec2f(-0.24f, 0.998f), 0.f, Vec2f(0.f, 1.f)),
        std::make_tuple(Vec2f(-4.998f, 12.3535f), 0.f, Vec2f(-4.f, 13.f)),
        std::make_tuple(Vec2f( -5.677f, -2.001f), 0.f, Vec2f(-5.f, -2.f))
    ));

    // Vec2f ceilAbs() const
    class Vec2f_CeilAbsF : public Vec2f_VecScaVecFixture {};
    TEST_P(Vec2f_CeilAbsF, Vec2f_CeilAbs)
    {
        Vec2f output = vector.ceilAbs();
        ASSERT_NEAR(expected.x, output.x, 1E-06);
        ASSERT_NEAR(expected.y, output.y, 1E-06);
    }

    INSTANTIATE_TEST_SUITE_P(Vec2f_CeilAbs, Vec2f_CeilAbsF, testing::Values(
        std::make_tuple(Vec2f(5.45f, 4.667f), 0.f, Vec2f(6.f, 5.f)),
        std::make_tuple(Vec2f(-0.24f, 0.998f), 0.f, Vec2f(-1.f, 1.f)),
        std::make_tuple(Vec2f(-4.998f, 12.3535f), 0.f, Vec2f(-5.f, 13.f)),
        std::make_tuple(Vec2f(-5.677f, -2.001f), 0.f, Vec2f(-6.f, -3.f)) 
    ));


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


    // float Vec2f::dot(float scalar) const
    class Vec2f_DotScalarF : public Vec2f_VecVecScaFixture {};
    TEST_P(Vec2f_DotScalarF, Vec2f_DotScalar)
    {
        float output = vectorOne.dot(vectorTwo.x);
        ASSERT_NEAR(expected, output, 1E-05);
    }

    INSTANTIATE_TEST_SUITE_P(Vec2f_DotScalar, Vec2f_DotScalarF, testing::Values(
        std::make_tuple(Vec2f(5.f, 4.f), Vec2f(6.2f, 0.f), 55.8f),
        std::make_tuple(Vec2f(-5.f, -4.f), Vec2f(-6.2f, 0.f), 55.8f),
        std::make_tuple(Vec2f(-5.f, 4.f), Vec2f(6.2f, 0.f),  -6.2f),
        std::make_tuple(Vec2f(5.f, -4.f), Vec2f(6.2f, 0.f),  6.2f)
    ));

    // float Vec2f::dot(float xTwo, float yTwo) const
    class Vec2f_DotScalarScalarF : public Vec2f_VecVecScaFixture {};
    TEST_P(Vec2f_DotScalarScalarF, Vec2f_DotScalarScalar)
    {
        float output = vectorOne.dot(vectorTwo.x, vectorTwo.y);
        ASSERT_NEAR(expected, output, 1E-05);
    }

    INSTANTIATE_TEST_SUITE_P(Vec2f_DotScalarScalar, Vec2f_DotScalarScalarF, testing::Values(
        std::make_tuple(Vec2f(5.f, 0.f), Vec2f(0.f, 4.f), 0.f),
        std::make_tuple(Vec2f(5.f, 4.f), Vec2f(6.2f, 10.2f), 71.8f),
        std::make_tuple(Vec2f(-5.f, 4.f), Vec2f(-6.2f, -10.2f), -9.8f),
        std::make_tuple(Vec2f(-5.f, 0.f), Vec2f(-10.2f, 4.f), 51.f)
    ));

    // Vec2f Vec2f::normalise() const
    class Vec2f_NormaliseF : public Vec2f_VecVecVecFixture {};
    TEST_P(Vec2f_NormaliseF, Vec2f_Normalise)
    {
        Vec2f output = vectorOne.normalise();
        ASSERT_NEAR(expected.x, output.x, 1E-05);
        ASSERT_NEAR(expected.y, output.y, 1E-05);
    }

    INSTANTIATE_TEST_SUITE_P(Vec2f_Normalise, Vec2f_NormaliseF, testing::Values(
        std::make_tuple(Vec2f(5.f, 5.f), Vec2f(0.f, 0.f), Vec2f(0.707107f, 0.707107f)),
        std::make_tuple(Vec2f(-5.f, -5.f), Vec2f(0.f, 0.f), Vec2f(-0.707107f, -0.707107f)),
        std::make_tuple(Vec2f(-6.f, 8.f), Vec2f(0.f, 0.f), Vec2f(-0.6f, 0.8f))
    ));

    class Vec2f_VecFloatFloatFixture : public testing::TestWithParam<std::tuple<Vec2f, float, float>>
    {
        protected:
            void SetUp() override
            {
                vector = std::get<0>(GetParam());
                expectedX = std::get<1>(GetParam());
                expectedY = std::get<2>(GetParam());
            }
            Vec2f vector;
            float expectedX, expectedY;
    };

    // Vec2f Vec2f::toFloat() const
    class Vec2f_ConvertToFloatF : public Vec2f_VecFloatFloatFixture {};
    TEST_P(Vec2f_ConvertToFloatF, Vec2f_ConvertToFloat)
    { 
        ASSERT_EQ(typeid(float), typeid(vector.toFloat().x));
        ASSERT_EQ(typeid(float), typeid(vector.toFloat().y));   
        ASSERT_EQ(expectedX, vector.toFloat().x);
        ASSERT_EQ(expectedY, vector.toFloat().y);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec2f_ConvertToFloat, Vec2f_ConvertToFloatF, testing::Values(
        std::make_tuple(Vec2f(0.f, 0.f), 0.f, 0.f),
        std::make_tuple(Vec2f(5.2f, 5.2f), 5.2f, 5.2f),
        std::make_tuple(Vec2f(-5.2f, -5.2f), -5.2f, -5.2f),
        std::make_tuple(Vec2f(10.09f, -10.09f), 10.09f, -10.09f)
    ));

    // Vec2d Vec2f::toDouble() const
    class Vec2f_ConvertToDoubleF : public Vec2f_VecFloatFloatFixture {};
    TEST_P(Vec2f_ConvertToDoubleF, Vec2f_ConvertToDouble)
    { 
        double expectX = (double)expectedX;
        double expectY = (double)expectedY;
        ASSERT_EQ(typeid(double), typeid(vector.toDouble().x));
        ASSERT_EQ(typeid(double), typeid(vector.toDouble().y));   
        ASSERT_NEAR(expectX, vector.toDouble().x, 1E-05);
        ASSERT_NEAR(expectY, vector.toDouble().y, 1E-05);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec2f_ConvertToDouble, Vec2f_ConvertToDoubleF, testing::Values(
        std::make_tuple(Vec2f(0.f, 0.f), 0.f, 0.f),
        std::make_tuple(Vec2f(5.2f, 5.2f), 5.2f, 5.2f),
        std::make_tuple(Vec2f(-5.2f, -5.2f), -5.2f, -5.2f),
        std::make_tuple(Vec2f(10.09f, -10.09f), 10.09f, -10.09f)
    ));

}