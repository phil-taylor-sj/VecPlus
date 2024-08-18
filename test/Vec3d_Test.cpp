#include "pch.h"
#include <VecPlus/Vec3.h>
#include <iostream>

// TODO: Add tests for Vec2d::rotation(char axis, double angle);

using namespace vecp;

namespace Vec3d_Tests
{
    TEST(Vec3d_TestConstructorDefault, SetDefaultValues)
    {   
        Vec3d vector = Vec3d();
        ASSERT_DOUBLE_EQ(vector.x, 0.0);
        ASSERT_DOUBLE_EQ(vector.y, 0.0);
        ASSERT_DOUBLE_EQ(vector.z, 0.0);
    }

    // Constructor with specified values test
    TEST(Vec3d_TestConstructorValues, SetSpecifiedValues)
    {
        Vec3d vector = Vec3d(-3.5, 4.2, 1.5);
        ASSERT_DOUBLE_EQ(vector.x, -3.5);
        ASSERT_DOUBLE_EQ(vector.y, 4.2);
        ASSERT_DOUBLE_EQ(vector.z, 1.5);
    }

    class Vec3d_VecScaVecFixture : public testing::TestWithParam<std::tuple<Vec3d, double, Vec3d>>
    {
    protected:
        void SetUp() override
        {
            vector = std::get<0>(GetParam());
            scalar = std::get<1>(GetParam());
            expected = std::get<2>(GetParam());
        }
        Vec3d vector, expected;
        double scalar;
    };

    class Vec3d_VecVecVecFixture : public testing::TestWithParam<std::tuple<Vec3d, Vec3d, Vec3d>>
    {
    protected:
        void SetUp() override
        {
            vectorOne = std::get<0>(GetParam());
            vectorTwo = std::get<1>(GetParam());
            expected = std::get<2>(GetParam());
        }
        Vec3d vectorOne, vectorTwo, expected;
    };

    // Vec3d operator + (const Vec3d& vector) const
    class Vec3d_AddVectorF : public Vec3d_VecVecVecFixture {};
    TEST_P(Vec3d_AddVectorF, Vec3d_AddVector)
    {
        Vec3d output = vectorOne + vectorTwo;
        ASSERT_DOUBLE_EQ(expected.x, output.x);
        ASSERT_DOUBLE_EQ(expected.y, output.y);
        ASSERT_DOUBLE_EQ(expected.z, output.z);
    }

    INSTANTIATE_TEST_SUITE_P(Vec3d_AddVector, Vec3d_AddVectorF, testing::Values(
        std::make_tuple(Vec3d(1.1, 2.2, 3.3), Vec3d(3.3, 4.4, 5.5), Vec3d(4.4, 6.6, 8.8)),
        std::make_tuple(Vec3d(-2.5, 5.1, -1.1), Vec3d(7.2, -3.3, 2.2), Vec3d(4.7, 1.8, 1.1)),
        std::make_tuple(Vec3d(0.0, -8.4, 7.7), Vec3d(-4.4, 6.6, -3.3), Vec3d(-4.4, -1.8, 4.4)),
        std::make_tuple(Vec3d(10.0, -10.0, 5.0), Vec3d(-10.0, 10.0, -5.0), Vec3d(0.0, 0.0, 0.0))
    ));

    // void operator += (const Vec3d& vector)
    class Vec3d_AddEqualsVectorF : public Vec3d_VecVecVecFixture {};
    TEST_P(Vec3d_AddEqualsVectorF, Vec3d_AddEqualsVector)
    {
        vectorOne += vectorTwo;
        ASSERT_DOUBLE_EQ(expected.x, vectorOne.x);
        ASSERT_DOUBLE_EQ(expected.y, vectorOne.y);
        ASSERT_DOUBLE_EQ(expected.z, vectorOne.z);
    }

    INSTANTIATE_TEST_SUITE_P(Vec3d_AddEqualsVector, Vec3d_AddEqualsVectorF, testing::Values(
        std::make_tuple(Vec3d(1.1, 2.2, 3.3), Vec3d(3.3, 4.4, 5.5), Vec3d(4.4, 6.6, 8.8)),
        std::make_tuple(Vec3d(-2.5, 5.1, -1.1), Vec3d(7.2, -3.3, 2.2), Vec3d(4.7, 1.8, 1.1)),
        std::make_tuple(Vec3d(0.0, -8.4, 7.7), Vec3d(-4.4, 6.6, -3.3), Vec3d(-4.4, -1.8, 4.4)),
        std::make_tuple(Vec3d(10.0, -10.0, 5.0), Vec3d(-10.0, 10.0, -5.0), Vec3d(0.0, 0.0, 0.0))
    ));

    // Vec3d operator - (const Vec3d& vector) const
    class Vec3d_SubtractVectorF : public Vec3d_VecVecVecFixture {};
    TEST_P(Vec3d_SubtractVectorF, Vec3d_SubtractVector)
    {
        Vec3d output = vectorOne - vectorTwo;
        ASSERT_DOUBLE_EQ(expected.x, output.x);
        ASSERT_DOUBLE_EQ(expected.y, output.y);
        ASSERT_DOUBLE_EQ(expected.z, output.z);
    }

    INSTANTIATE_TEST_SUITE_P(Vec3d_SubtractVector, Vec3d_SubtractVectorF, testing::Values(
        std::make_tuple(Vec3d(5.5, 7.7, 2.2), Vec3d(3.3, 2.2, 1.1), Vec3d(2.2, 5.5, 1.1)),
        std::make_tuple(Vec3d(10.0, 10.0, 5.5), Vec3d(4.5, 6.5, 2.5), Vec3d(5.5, 3.5, 3.0)),
        std::make_tuple(Vec3d(-3.3, 8.8, -4.4), Vec3d(2.2, -5.5, 1.1), Vec3d(-5.5, 14.3, -5.5)),
        std::make_tuple(Vec3d(0.0, 0.0, 0.0), Vec3d(-7.7, 9.9, -1.1), Vec3d(7.7, -9.9, 1.1))
    ));

    // void operator -= (const Vec3d& vector)
    class Vec3d_SubtractEqualsVectorF : public Vec3d_VecVecVecFixture {};
    TEST_P(Vec3d_SubtractEqualsVectorF, Vec3d_SubtractEqualsVector)
    {
        vectorOne -= vectorTwo;
        ASSERT_DOUBLE_EQ(expected.x, vectorOne.x);
        ASSERT_DOUBLE_EQ(expected.y, vectorOne.y);
        ASSERT_DOUBLE_EQ(expected.z, vectorOne.z);
    }

    INSTANTIATE_TEST_SUITE_P(Vec3d_SubtractEqualsVector, Vec3d_SubtractEqualsVectorF, testing::Values(
        std::make_tuple(Vec3d(5.5, 7.7, 2.2), Vec3d(3.3, 2.2, 1.1), Vec3d(2.2, 5.5, 1.1)),
        std::make_tuple(Vec3d(10.0, 10.0, 5.5), Vec3d(4.5, 6.5, 2.5), Vec3d(5.5, 3.5, 3.0)),
        std::make_tuple(Vec3d(-3.3, 8.8, -4.4), Vec3d(2.2, -5.5, 1.1), Vec3d(-5.5, 14.3, -5.5)),
        std::make_tuple(Vec3d(0.0, 0.0, 0.0), Vec3d(-7.7, 9.9, -1.1), Vec3d(7.7, -9.9, 1.1))
    ));

    // Vec3d operator * (double scalar) const
    class Vec3d_MultiplyByScalarF : public Vec3d_VecScaVecFixture {};
    TEST_P(Vec3d_MultiplyByScalarF, Vec3d_MultiplyByScalar)
    {
        Vec3d output = vector * scalar;
        ASSERT_DOUBLE_EQ(expected.x, output.x);
        ASSERT_DOUBLE_EQ(expected.y, output.y);   
        ASSERT_DOUBLE_EQ(expected.z, output.z);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec3d_MultiplyByScalar, Vec3d_MultiplyByScalarF, testing::Values(
        std::make_tuple(Vec3d(0.0, 0.0, 0.0), 10.0, Vec3d(0.0, 0.0, 0.0)),
        std::make_tuple(Vec3d(3.3, 4.4, 5.5), 10.0, Vec3d(33.0, 44.0, 55.0)),
        std::make_tuple(Vec3d(-6.6, 4.4, -5.5), 5.0, Vec3d(-33.0, 22.0, -27.5)),
        std::make_tuple(Vec3d(8.8, -7.7, 6.6), -5.0, Vec3d(-44.0, 38.5, -33.0))
    ));

    // Vec3d operator * (const Vec3d& vector) const
    class Vec3d_MultiplyByVectorF : public Vec3d_VecVecVecFixture {};
    TEST_P(Vec3d_MultiplyByVectorF, Vec3d_MultiplyByVector)
    {
        Vec3d output = vectorOne * vectorTwo;
        ASSERT_DOUBLE_EQ(expected.x, output.x);
        ASSERT_DOUBLE_EQ(expected.y, output.y);   
        ASSERT_DOUBLE_EQ(expected.z, output.z);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec3d_MultiplyByVector, Vec3d_MultiplyByVectorF, testing::Values(
        std::make_tuple(Vec3d(0.0, 0.0, 0.0), Vec3d(10.0, 10.0, 10.0), Vec3d(0.0, 0.0, 0.0)),
        std::make_tuple(Vec3d(3.3, 4.4, 5.5), Vec3d(5.5, 10.0, 2.0), Vec3d(18.15, 44.0, 11.0)),
        std::make_tuple(Vec3d(-6.6, 4.4, -3.3), Vec3d(5.5, -5.0, 7.0), Vec3d(-36.3, -22.0, -23.1)),
        std::make_tuple(Vec3d(8.8, -7.7, 6.6), Vec3d(-5.5, -5.5, 3.3), Vec3d(-48.4, 42.35, 21.78))
    ));

    // void operator *= (double scalar)
    class Vec3d_MultiplyEqualsByScalarF : public Vec3d_VecScaVecFixture {};
    TEST_P(Vec3d_MultiplyEqualsByScalarF, Vec3d_MultiplyEqualsByScalar)
    {
        vector *= scalar;
        ASSERT_DOUBLE_EQ(expected.x, vector.x);
        ASSERT_DOUBLE_EQ(expected.y, vector.y);   
        ASSERT_DOUBLE_EQ(expected.z, vector.z);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec3d_MultiplyEqualsByScalar,Vec3d_MultiplyEqualsByScalarF, testing::Values(
        std::make_tuple(Vec3d(0.0, 0.0, 0.0), 10.0, Vec3d(0.0, 0.0, 0.0)),
        std::make_tuple(Vec3d(3.3, 4.4, 5.5), 10.0, Vec3d(33.0, 44.0, 55.0)),
        std::make_tuple(Vec3d(-6.6, 4.4, -5.5), 5.0, Vec3d(-33.0, 22.0, -27.5)),
        std::make_tuple(Vec3d(8.8, -7.7, 6.6), -5.0, Vec3d(-44.0, 38.5, -33.0))
    ));

    // void operator *= (const Vec3d& vector)
    class Vec3d_MultiplyEqualsByVectorF : public Vec3d_VecVecVecFixture {};
    TEST_P(Vec3d_MultiplyEqualsByVectorF, MultiplyEqualsByVector)
    {
        vectorOne *= vectorTwo;
        ASSERT_DOUBLE_EQ(expected.x, vectorOne.x);
        ASSERT_DOUBLE_EQ(expected.y, vectorOne.y);   
        ASSERT_DOUBLE_EQ(expected.z, vectorOne.z);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec3d_MultiplyEqualsByVector, Vec3d_MultiplyEqualsByVectorF, testing::Values(
        std::make_tuple(Vec3d(0.0, 0.0, 0.0), Vec3d(10.0, 10.0, 10.0), Vec3d(0.0, 0.0, 0.0)),
        std::make_tuple(Vec3d(3.3, 4.4, 5.5), Vec3d(5.5, 10.0, 2.0), Vec3d(18.15, 44.0, 11.0)),
        std::make_tuple(Vec3d(-6.6, 4.4, -3.3), Vec3d(5.5, -5.0, 7.0), Vec3d(-36.3, -22.0, -23.1)),
        std::make_tuple(Vec3d(8.8, -7.7, 6.6), Vec3d(-5.5, -5.5, 3.3), Vec3d(-48.4, 42.35, 21.78))
    ));

    class Vec3d_VecVecBoolFixture : public testing::TestWithParam<std::tuple<Vec3d, Vec3d, bool>>
    {
    protected:
        void SetUp() override
        {
            vectorOne = std::get<0>(GetParam());
            vectorTwo = std::get<1>(GetParam());
            expected = std::get<2>(GetParam());
        }
        Vec3d vectorOne, vectorTwo;
        bool expected;
    };

    // bool operator == (const Vec3d& vector) const
    class Vec3d_CompareVectorsF : public Vec3d_VecVecBoolFixture {};
    TEST_P(Vec3d_CompareVectorsF, CompareVectors)
    {
        bool output = vectorOne == vectorTwo;
        ASSERT_EQ(expected, output);
    }

    INSTANTIATE_TEST_SUITE_P(Vec3d_CompareVectors, Vec3d_CompareVectorsF, testing::Values(
        std::make_tuple(Vec3d(-5.5, 5.5, 0.0), Vec3d(-5.5, 5.5, 0.0), true),
        std::make_tuple(Vec3d(0.0, 0.0, 0.0), Vec3d(0.0, 0.0, 0.0), true),
        std::make_tuple(Vec3d(-5.5, 5.5, 5.5), Vec3d(5.5, -5.5, 5.5), false),
        std::make_tuple(Vec3d(6.1, 0.0, 7.1), Vec3d(7.1, 0.0, 6.1), false)
    ));

    class Vec3d_VecVecScaFixture : public testing::TestWithParam<std::tuple<Vec3d, Vec3d, double>>
    {
    protected:
        void SetUp() override
        {
            vectorOne = std::get<0>(GetParam());
            vectorTwo = std::get<1>(GetParam());
            expected = std::get<2>(GetParam());
        }
        Vec3d vectorOne, vectorTwo;
        double expected;
    };

    // double mag() const
    class Vec3d_MagnitudeF : public Vec3d_VecVecScaFixture {};
    TEST_P(Vec3d_MagnitudeF, Vec3d_Magnitude)
    {
        double output = vectorOne.mag();
        ASSERT_NEAR(expected, output, 1E-06);
    }

    INSTANTIATE_TEST_SUITE_P(Vec3d_Magnitude, Vec3d_MagnitudeF, testing::Values(
        std::make_tuple(Vec3d(5.0, 4.0, 3.0), Vec3d(0.0, 0.0, 0.0), 7.07106781),
        std::make_tuple(Vec3d(-8.2, 0.6, -2.5), Vec3d(0.0, 0.0, 0.0), 8.593602271),
        std::make_tuple(Vec3d(-8.2, -0.6, 2.5), Vec3d(0.0, 0.0, 0.0), 8.593602271)
    ));

    // double mag(const Vec3d& vector) const
    class Vec3d_MagnitudeVectorF : public Vec3d_VecVecScaFixture {};
    TEST_P(Vec3d_MagnitudeVectorF, Vec3d_MagnitudeVector)
    {
        double output = vectorOne.mag(vectorTwo);
        ASSERT_NEAR(expected, output, 1E-06);
    }

    INSTANTIATE_TEST_SUITE_P(Vec3d_MagnitudeVector, Vec3d_MagnitudeVectorF, testing::Values(
        std::make_tuple(Vec3d(5.0, 4.0, 3.0), Vec3d(0.0, 0.0, 0.0), 7.07106781),
        std::make_tuple(Vec3d(0.0, 0.0, 0.0), Vec3d(5.0, 4.0, 3.0), 7.07106781),
        std::make_tuple(Vec3d(-8.2, 0.6, -2.5), Vec3d(5.9, 4.6, 1.3), 15.14100393),
        std::make_tuple(Vec3d(-8.2, -0.6, 2.5), Vec3d(-5.9, -4.6, 1.3), 4.767598976)
    ));

    // Vec3d operator / (double scalar) const
    class Vec3d_DivideByScalarF : public Vec3d_VecScaVecFixture {};
    TEST_P(Vec3d_DivideByScalarF, Vec3d_DivideByScalar)
    {
        Vec3d output = vector / scalar;
        ASSERT_DOUBLE_EQ(expected.x, output.x);
        ASSERT_DOUBLE_EQ(expected.y, output.y);   
        ASSERT_DOUBLE_EQ(expected.z, output.z);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec3d_DivideByScalar, Vec3d_DivideByScalarF, testing::Values(
        std::make_tuple(Vec3d(10.0, 20.0, 30.0), 2.0, Vec3d(5.0, 10.0, 15.0)),
        std::make_tuple(Vec3d(-6.6, 4.4, -2.2), -2.2, Vec3d(3.0, -2.0, 1.0)),
        std::make_tuple(Vec3d(10.0, -5.0, 2.5), 2.0, Vec3d(5.0, -2.5, 1.25)),
        std::make_tuple(Vec3d(8.8, -7.7, 6.6), 4.4, Vec3d(2.0, -1.75, 1.5)),
        std::make_tuple(Vec3d(9.0, 12.0, 15.0), 3.0, Vec3d(3.0, 4.0, 5.0))  
    ));

    // Vec3d operator / (const Vec3d& vector) const
    class Vec3d_DivideByVectorF : public Vec3d_VecVecVecFixture {};
    TEST_P(Vec3d_DivideByVectorF, Vec3d_DivideByVector)
    {
        Vec3d output = vectorOne / vectorTwo;
        ASSERT_DOUBLE_EQ(expected.x, output.x);
        ASSERT_DOUBLE_EQ(expected.y, output.y);   
        ASSERT_DOUBLE_EQ(expected.z, output.z);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec3d_DivideByVector, Vec3d_DivideByVectorF, testing::Values(
        std::make_tuple(Vec3d(10.0, 20.0, 30.0), Vec3d(2.0, 4.0, 6.0), Vec3d(5.0, 5.0, 5.0)),
        std::make_tuple(Vec3d(-6.6, 4.4, -2.2), Vec3d(-2.2, 2.2, 1.1), Vec3d(3.0, 2.0, -2.0)),
        std::make_tuple(Vec3d(10.0, -5.0, 2.5), Vec3d(2.0, -5.0, 0.5), Vec3d(5.0, 1.0, 5.0)),
        std::make_tuple(Vec3d(8.8, -7.7, 6.6), Vec3d(4.4, -7.7, 3.3), Vec3d(2.0, 1.0, 2.0))
    ));

    // void operator /= (double scalar)
    class Vec3d_DivideEqualsByScalarF : public Vec3d_VecScaVecFixture {};
    TEST_P(Vec3d_DivideEqualsByScalarF, Vec3d_DivideEqualsByScalar)
    {
        vector /= scalar;
        ASSERT_DOUBLE_EQ(expected.x, vector.x);
        ASSERT_DOUBLE_EQ(expected.y, vector.y);   
        ASSERT_DOUBLE_EQ(expected.z, vector.z);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec3d_DivideEqualsByScalar, Vec3d_DivideEqualsByScalarF, testing::Values(
        std::make_tuple(Vec3d(10.0, 20.0, 30.0), 2.0, Vec3d(5.0, 10.0, 15.0)),
        std::make_tuple(Vec3d(-6.6, 4.4, -2.2), -2.2, Vec3d(3.0, -2.0, 1.0)),
        std::make_tuple(Vec3d(10.0, -5.0, 2.5), 2.0, Vec3d(5.0, -2.5, 1.25)),
        std::make_tuple(Vec3d(8.8, -7.7, 6.6), 4.4, Vec3d(2.0, -1.75, 1.5))
    ));

    // void operator /= (const Vec3d& vector)
    class Vec3d_DivideEqualsByVectorF : public Vec3d_VecVecVecFixture {};
    TEST_P(Vec3d_DivideEqualsByVectorF, Vec3d_DivideEqualsByVector)
    {
        vectorOne /= vectorTwo;
        ASSERT_DOUBLE_EQ(expected.x, vectorOne.x);
        ASSERT_DOUBLE_EQ(expected.y, vectorOne.y);   
        ASSERT_DOUBLE_EQ(expected.z, vectorOne.z);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec3d_DivideEqualsByVector, Vec3d_DivideEqualsByVectorF, testing::Values(
        std::make_tuple(Vec3d(10.0, 20.0, 30.0), Vec3d(2.0, 4.0, 6.0), Vec3d(5.0, 5.0, 5.0)),
        std::make_tuple(Vec3d(-6.6, 4.4, -2.2), Vec3d(-2.2, 2.2, 1.1), Vec3d(3.0, 2.0, -2.0)),
        std::make_tuple(Vec3d(10.0, -5.0, 2.5), Vec3d(2.0, -5.0, 0.5), Vec3d(5.0, 1.0, 5.0)),
        std::make_tuple(Vec3d(8.8, -7.7, 6.6), Vec3d(4.4, -7.7, 3.3), Vec3d(2.0, 1.0, 2.0))
    ));

    // double Vec3d::dot(const Vec3d& vector) const
    class Vec3d_DotVectorF : public Vec3d_VecVecScaFixture {};
    TEST_P(Vec3d_DotVectorF, Vec3d_DotVector)
    {
        double output = vectorOne.dot(vectorTwo);
        ASSERT_NEAR(expected, output, 1E-05);
    }

    INSTANTIATE_TEST_SUITE_P(Vec3d_DotVector, Vec3d_DotVectorF, testing::Values(
        std::make_tuple(Vec3d(5., 4., 3.), Vec3d(6.2, 2., 1.1), 42.3),
        std::make_tuple(Vec3d(-5., -4., -3.), Vec3d(-6.2, 3., 1.1), 15.7),
        std::make_tuple(Vec3d(-5., 4., 3.), Vec3d(6.2, 1., -1.1), -30.3),
        std::make_tuple(Vec3d(5., -4., 3.), Vec3d(6.2, -2.5, 1.1), 44.3)
    ));

    // double Vec3d::dot(double scalar) const
    class Vec3d_DotScalarF : public Vec3d_VecVecScaFixture {};
    TEST_P(Vec3d_DotScalarF, Vec3d_DotScalar)
    {
        double output = vectorOne.dot(vectorTwo.x);
        ASSERT_NEAR(expected, output, 1E-06);
    }

    INSTANTIATE_TEST_SUITE_P(Vec3d_DotScalar, Vec3d_DotScalarF, testing::Values(
        std::make_tuple(Vec3d(5., 4., 3.), Vec3d(6.2, 0., 0.), 74.4),
        std::make_tuple(Vec3d(-5., -4., -3.), Vec3d(-6.2, 0., 0.), 74.4),
        std::make_tuple(Vec3d(-5., 4., 3.), Vec3d(0., 0., 0.), 0.),
        std::make_tuple(Vec3d(5., -4., 3.), Vec3d(-1.1, 0., 0.), -4.4)
    ));


    // double Vec3d::dot(double xTwo, double yTwo, double zTwo) const
    class Vec3d_DotScalarScalarF : public Vec3d_VecVecScaFixture {};
    TEST_P(Vec3d_DotScalarScalarF, Vec3d_DotScalarScalar)
    {
        double output = vectorOne.dot(vectorTwo.x, vectorTwo.y, vectorTwo.z);
        ASSERT_NEAR(expected, output, 1E-06);
    }

    INSTANTIATE_TEST_SUITE_P(Vec3d_DotScalarScalar, Vec3d_DotScalarScalarF, testing::Values(
        std::make_tuple(Vec3d(5., 4., 3.), Vec3d(6.2, 2., 1.1), 42.3),
        std::make_tuple(Vec3d(-5., -4., -3.), Vec3d(-6.2, 3., 1.1), 15.7),
        std::make_tuple(Vec3d(-5., 4., 3.), Vec3d(6.2, 1., -1.1), -30.3),
        std::make_tuple(Vec3d(5., -4., 3.), Vec3d(6.2, -2.5, 1.1), 44.3)
    ));

    // Vec3d Vec3d::normalize() const
    class Vec3d_NormaliseF : public Vec3d_VecVecVecFixture {};
    TEST_P(Vec3d_NormaliseF, Vec3d_Normalise)
    {
        Vec3d output = vectorOne.normalise();
        ASSERT_NEAR(expected.x, output.x, 1E-05);
        ASSERT_NEAR(expected.y, output.y, 1E-05);
        ASSERT_NEAR(expected.z, output.z, 1E-05);
    }

    INSTANTIATE_TEST_SUITE_P(Vec3d_Normalise, Vec3d_NormaliseF, testing::Values(
        std::make_tuple(Vec3d(5.0, 5.0, 5.0), Vec3d(0.0, 0.0, 0.0), Vec3d(0.57735, 0.57735, 0.57735)),
        std::make_tuple(Vec3d(-5.0, -5.0, -5.0), Vec3d(0.0, 0.0, 0.0), Vec3d(-0.57735, -0.57735, -0.57735)),
        std::make_tuple(Vec3d(-6.0, 8.0, -10.0), Vec3d(0.0, 0.0, 0.0), Vec3d(-0.42426, 0.56569, -0.70711))
    ));

    class Vec3d_VecDoubleDoubleFixture : public testing::TestWithParam<std::tuple<Vec3d, double, double, double>>
    {
        protected:
            void SetUp() override
            {
                vector = std::get<0>(GetParam());
                expectedX = std::get<1>(GetParam());
                expectedY = std::get<2>(GetParam());
                expectedZ = std::get<3>(GetParam());
            }
            Vec3d vector;
            double expectedX, expectedY, expectedZ;
    };

    // Vec3d Vec3d::toDouble() const
    class Vec3d_ConvertToDoubleF : public Vec3d_VecDoubleDoubleFixture {};
    TEST_P(Vec3d_ConvertToDoubleF, Vec3d_ConvertToDouble)
    { 
        ASSERT_EQ(typeid(double), typeid(vector.toDouble().x));
        ASSERT_EQ(typeid(double), typeid(vector.toDouble().y));   
        ASSERT_EQ(typeid(double), typeid(vector.toDouble().z));   
        ASSERT_DOUBLE_EQ(expectedX, vector.toDouble().x);
        ASSERT_DOUBLE_EQ(expectedY, vector.toDouble().y);   
        ASSERT_DOUBLE_EQ(expectedZ, vector.toDouble().z);   
    }

    INSTANTIATE_TEST_SUITE_P(Vec3d_ConvertToDouble, Vec3d_ConvertToDoubleF, testing::Values(
        std::make_tuple(Vec3d(0.0, 0.0, 0.0), 0.0, 0.0, 0.0),
        std::make_tuple(Vec3d(5.2, 5.2, 5.2), 5.2, 5.2, 5.2),
        std::make_tuple(Vec3d(-5.2, -5.2, -5.2), -5.2, -5.2, -5.2),
        std::make_tuple(Vec3d(10.09, -10.09, 20.18), 10.09, -10.09, 20.18)
    ));

}