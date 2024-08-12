#include "pch.h"
#include <VecPlus/Vec2.h>
#include <iostream>

using namespace vecp;

namespace Vec2d_Tests
{
    TEST(TestConstructorDefault, SetDefaultValues)
    {   
        Vec2f vector = Vec2f();
        ASSERT_EQ(vector.x, 0.0f);
        ASSERT_EQ(vector.y, 0.0f);
    }

    // Constructor with specified values test
    TEST(TestConstructorValues, SetSpecifiedValues)
    {
        Vec2f vector = Vec2f(-3.5f, 4.2f);
        ASSERT_EQ(vector.x, -3.5f);
        ASSERT_EQ(vector.y, 4.2f);
    }

    class VecScaVecFixture : public testing::TestWithParam<std::tuple<Vec2f, float, Vec2f>>
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

    class VecVecVecFixture : public testing::TestWithParam<std::tuple<Vec2f, Vec2f, Vec2f>>
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
    class AddVectorF : public VecVecVecFixture {};
    TEST_P(AddVectorF, AddVector)
    {
        Vec2f output = vectorOne + vectorTwo;
        ASSERT_EQ(expected.x, output.x);
        ASSERT_EQ(expected.y, output.y);
    }

    INSTANTIATE_TEST_SUITE_P(AddVector, AddVectorF, testing::Values(
        std::make_tuple(Vec2f(1.1f, 2.2f), Vec2f(3.3f, 4.4f), Vec2f(4.4f, 6.6f)),
        std::make_tuple(Vec2f(-2.5f, 5.1f), Vec2f(7.2f, -3.3f), Vec2f(4.7f, 1.8f)),
        std::make_tuple(Vec2f(0.0f, -8.4f), Vec2f(-4.4f, 6.6f), Vec2f(-4.4f, -1.8f)),
        std::make_tuple(Vec2f(10.0f, -10.0f), Vec2f(-10.0f, 10.0f), Vec2f(0.0f, 0.0f))
    ));

    // void operator += (const Vec2f& vector)
    class AddEqualsVectorF : public VecVecVecFixture {};
    TEST_P(AddEqualsVectorF, AddEqualsVector)
    {
        vectorOne += vectorTwo;
        ASSERT_EQ(expected.x, vectorOne.x);
        ASSERT_EQ(expected.y, vectorOne.y);
    }

    INSTANTIATE_TEST_SUITE_P(AddEqualsVector, AddEqualsVectorF, testing::Values(
        std::make_tuple(Vec2f(1.1f, 2.2f), Vec2f(3.3f, 4.4f), Vec2f(4.4f, 6.6f)),
        std::make_tuple(Vec2f(-2.5f, 5.1f), Vec2f(7.2f, -3.3f), Vec2f(4.7f, 1.8f)),
        std::make_tuple(Vec2f(0.0f, -8.4f), Vec2f(-4.4f, 6.6f), Vec2f(-4.4f, -1.8f)),
        std::make_tuple(Vec2f(10.0f, -10.0f), Vec2f(-10.0f, 10.0f), Vec2f(0.0f, 0.0f))
    ));

    // Vec2f operator - (const Vec2f& vector) const
    class SubtractVectorF : public VecVecVecFixture {};
    TEST_P(SubtractVectorF, SubtractVector)
    {
        Vec2f output = vectorOne - vectorTwo;
        ASSERT_EQ(expected.x, output.x);
        ASSERT_EQ(expected.y, output.y);
    }

    INSTANTIATE_TEST_SUITE_P(SubtractVector, SubtractVectorF, testing::Values(
        std::make_tuple(Vec2f(5.5f, 7.7f), Vec2f(3.3f, 2.2f), Vec2f(2.2f, 5.5f)),
        std::make_tuple(Vec2f(10.0f, 10.0f), Vec2f(4.5f, 6.5f), Vec2f(5.5f, 3.5f)),
        std::make_tuple(Vec2f(-3.3f, 8.8f), Vec2f(2.2f, -5.5f), Vec2f(-5.5f, 14.3f)),
        std::make_tuple(Vec2f(0.0f, 0.0f), Vec2f(-7.7f, 9.9f), Vec2f(7.7f, -9.9f))
    ));

    // void operator -= (const Vec2f& vector)
    class SubtractEqualsVectorF : public VecVecVecFixture {};
    TEST_P(SubtractEqualsVectorF, SubtractEqualsVector)
    {
        vectorOne -= vectorTwo;
        ASSERT_EQ(expected.x, vectorOne.x);
        ASSERT_EQ(expected.y, vectorOne.y);
    }

    INSTANTIATE_TEST_SUITE_P(SubtractEqualsVector, SubtractEqualsVectorF, testing::Values(
        std::make_tuple(Vec2f(5.5f, 7.7f), Vec2f(3.3f, 2.2f), Vec2f(2.2f, 5.5f)),
        std::make_tuple(Vec2f(10.0f, 10.0f), Vec2f(4.5f, 6.5f), Vec2f(5.5f, 3.5f)),
        std::make_tuple(Vec2f(-3.3f, 8.8f), Vec2f(2.2f, -5.5f), Vec2f(-5.5f, 14.3f)),
        std::make_tuple(Vec2f(0.0f, 0.0f), Vec2f(-7.7f, 9.9f), Vec2f(7.7f, -9.9f))
    ));

    // Vec2f operator * (float scalar) const
    class MultiplyByScalarF : public VecScaVecFixture {};
    TEST_P(MultiplyByScalarF, MultiplyByScalar)
    {
        Vec2f output = vector * scalar;
        ASSERT_EQ(expected.x, output.x);
        ASSERT_EQ(expected.y, output.y);   
    }

    INSTANTIATE_TEST_SUITE_P(MultiplyByScalar, MultiplyByScalarF, testing::Values(
        std::make_tuple(Vec2f(0.0f, 0.0f), 10.0f, Vec2f(0.0f, 0.0f)),
        std::make_tuple(Vec2f(3.3f, 4.4f), 10.0f, Vec2f(33.0f, 44.0f)),
        std::make_tuple(Vec2f(-6.6f, 4.4f), 5.0f, Vec2f(-33.0f, 22.0f)),
        std::make_tuple(Vec2f(8.8f, -7.7f), -5.0f, Vec2f(-44.0f, 38.5f))
    ));

    // Vec2f operator * (const Vec2f& vector) const
    class MultiplyByVectorF : public VecVecVecFixture {};
    TEST_P(MultiplyByVectorF, MultiplyByVector)
    {
        Vec2f output = vectorOne * vectorTwo;
        ASSERT_EQ(expected.x, output.x);
        ASSERT_EQ(expected.y, output.y);   
    }

    INSTANTIATE_TEST_SUITE_P(MultiplyByVector, MultiplyByVectorF, testing::Values(
        std::make_tuple(Vec2f(0.0f, 0.0f), Vec2f(10.0f, 10.0f), Vec2f(0.0f, 0.0f)),
        std::make_tuple(Vec2f(3.3f, 4.4f), Vec2f(5.5f, 10.0f), Vec2f(18.15f, 44.0f)),
        std::make_tuple(Vec2f(-6.6f, 4.4f), Vec2f(5.5f, -5.0f), Vec2f(-36.3f, -22.0f)),
        std::make_tuple(Vec2f(8.8f, -7.7f), Vec2f(-5.5f, -5.5f), Vec2f(-48.4f, 42.35f))
    ));

    // void operator *= (float scalar)
    class MultiplyEqualsByScalarF : public VecScaVecFixture {};
    TEST_P(MultiplyEqualsByScalarF, MultiplyEqualsByScalar)
    {
        vector *= scalar;
        ASSERT_EQ(expected.x, vector.x);
        ASSERT_EQ(expected.y, vector.y);   
    }

    INSTANTIATE_TEST_SUITE_P(MultiplyEqualsByScalar, MultiplyEqualsByScalarF, testing::Values(
        std::make_tuple(Vec2f(0.0f, 0.0f), 10.0f, Vec2f(0.0f, 0.0f)),
        std::make_tuple(Vec2f(3.3f, 4.4f), 10.0f, Vec2f(33.0f, 44.0f)),
        std::make_tuple(Vec2f(-6.6f, 4.4f), 5.0f, Vec2f(-33.0f, 22.0f)),
        std::make_tuple(Vec2f(8.8f, -7.7f), -5.0f, Vec2f(-44.0f, 38.5f))
    ));

    // void operator *= (const Vec2f& vector)
    class MultiplyEqualsByVectorF : public VecVecVecFixture {};
    TEST_P(MultiplyEqualsByVectorF, MultiplyEqualsByVector)
    {
        vectorOne *= vectorTwo;
        ASSERT_EQ(expected.x, vectorOne.x);
        ASSERT_EQ(expected.y, vectorOne.y);   
    }

    INSTANTIATE_TEST_SUITE_P(MultiplyEqualsByVector, MultiplyEqualsByVectorF, testing::Values(
        std::make_tuple(Vec2f(0.0f, 0.0f), Vec2f(10.0f, 10.0f), Vec2f(0.0f, 0.0f)),
        std::make_tuple(Vec2f(3.3f, 4.4f), Vec2f(5.5f, 10.0f), Vec2f(18.15f, 44.0f)),
        std::make_tuple(Vec2f(-6.6f, 4.4f), Vec2f(5.5f, -5.0f), Vec2f(-36.3f, -22.0f)),
        std::make_tuple(Vec2f(8.8f, -7.7f), Vec2f(-5.5f, -5.5f), Vec2f(-48.4f, 42.35f))
    ));

    class VecVecBoolFixture : public testing::TestWithParam<std::tuple<Vec2f, Vec2f, bool>>
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
    class CompareVectorsF : public VecVecBoolFixture {};
    TEST_P(CompareVectorsF, CompareVectors)
    {
        bool output = vectorOne == vectorTwo;
        ASSERT_EQ(expected, output);
        ASSERT_EQ(expected, output);   
    }

    INSTANTIATE_TEST_SUITE_P(CompareVectors, CompareVectorsF, testing::Values(
        std::make_tuple(Vec2f(-5.5f, 5.5f), Vec2f(-5.5f, 5.5f), true),
        std::make_tuple(Vec2f(0.0f, 0.0f), Vec2f(0.0f, 0.0f), true),
        std::make_tuple(Vec2f(-5.5f, 5.5f), Vec2f(5.5f, -5.5f), false),
        std::make_tuple(Vec2f(6.1f, 0.0f), Vec2f(7.1f, 0.0f), false)
    ));TEST(TestConstructorDefault, SetDefaultValues)
    {   
        Vec2f vector = Vec2f();
        ASSERT_EQ(vector.x, 0.0f);
        ASSERT_EQ(vector.y, 0.0f);
    }

    // Constructor with specified values test
    TEST(TestConstructorValues, SetSpecifiedValues)
    {
        Vec2f vector = Vec2f(-3.5f, 4.2f);
        ASSERT_EQ(vector.x, -3.5f);
        ASSERT_EQ(vector.y, 4.2f);
    }

    class VecScaVecFixture : public testing::TestWithParam<std::tuple<Vec2f, float, Vec2f>>
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

    class VecVecVecFixture : public testing::TestWithParam<std::tuple<Vec2f, Vec2f, Vec2f>>
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
    class AddVectorF : public VecVecVecFixture {};
    TEST_P(AddVectorF, AddVector)
    {
        Vec2f output = vectorOne + vectorTwo;
        ASSERT_EQ(expected.x, output.x);
        ASSERT_EQ(expected.y, output.y);
    }

    INSTANTIATE_TEST_SUITE_P(AddVector, AddVectorF, testing::Values(
        std::make_tuple(Vec2f(1.1f, 2.2f), Vec2f(3.3f, 4.4f), Vec2f(4.4f, 6.6f)),
        std::make_tuple(Vec2f(-2.5f, 5.1f), Vec2f(7.2f, -3.3f), Vec2f(4.7f, 1.8f)),
        std::make_tuple(Vec2f(0.0f, -8.4f), Vec2f(-4.4f, 6.6f), Vec2f(-4.4f, -1.8f)),
        std::make_tuple(Vec2f(10.0f, -10.0f), Vec2f(-10.0f, 10.0f), Vec2f(0.0f, 0.0f))
    ));

    // void operator += (const Vec2f& vector)
    class AddEqualsVectorF : public VecVecVecFixture {};
    TEST_P(AddEqualsVectorF, AddEqualsVector)
    {
        vectorOne += vectorTwo;
        ASSERT_EQ(expected.x, vectorOne.x);
        ASSERT_EQ(expected.y, vectorOne.y);
    }

    INSTANTIATE_TEST_SUITE_P(AddEqualsVector, AddEqualsVectorF, testing::Values(
        std::make_tuple(Vec2f(1.1f, 2.2f), Vec2f(3.3f, 4.4f), Vec2f(4.4f, 6.6f)),
        std::make_tuple(Vec2f(-2.5f, 5.1f), Vec2f(7.2f, -3.3f), Vec2f(4.7f, 1.8f)),
        std::make_tuple(Vec2f(0.0f, -8.4f), Vec2f(-4.4f, 6.6f), Vec2f(-4.4f, -1.8f)),
        std::make_tuple(Vec2f(10.0f, -10.0f), Vec2f(-10.0f, 10.0f), Vec2f(0.0f, 0.0f))
    ));

    // Vec2f operator - (const Vec2f& vector) const
    class SubtractVectorF : public VecVecVecFixture {};
    TEST_P(SubtractVectorF, SubtractVector)
    {
        Vec2f output = vectorOne - vectorTwo;
        ASSERT_EQ(expected.x, output.x);
        ASSERT_EQ(expected.y, output.y);
    }

    INSTANTIATE_TEST_SUITE_P(SubtractVector, SubtractVectorF, testing::Values(
        std::make_tuple(Vec2f(5.5f, 7.7f), Vec2f(3.3f, 2.2f), Vec2f(2.2f, 5.5f)),
        std::make_tuple(Vec2f(10.0f, 10.0f), Vec2f(4.5f, 6.5f), Vec2f(5.5f, 3.5f)),
        std::make_tuple(Vec2f(-3.3f, 8.8f), Vec2f(2.2f, -5.5f), Vec2f(-5.5f, 14.3f)),
        std::make_tuple(Vec2f(0.0f, 0.0f), Vec2f(-7.7f, 9.9f), Vec2f(7.7f, -9.9f))
    ));

    // void operator -= (const Vec2f& vector)
    class SubtractEqualsVectorF : public VecVecVecFixture {};
    TEST_P(SubtractEqualsVectorF, SubtractEqualsVector)
    {
        vectorOne -= vectorTwo;
        ASSERT_EQ(expected.x, vectorOne.x);
        ASSERT_EQ(expected.y, vectorOne.y);
    }

    INSTANTIATE_TEST_SUITE_P(SubtractEqualsVector, SubtractEqualsVectorF, testing::Values(
        std::make_tuple(Vec2f(5.5f, 7.7f), Vec2f(3.3f, 2.2f), Vec2f(2.2f, 5.5f)),
        std::make_tuple(Vec2f(10.0f, 10.0f), Vec2f(4.5f, 6.5f), Vec2f(5.5f, 3.5f)),
        std::make_tuple(Vec2f(-3.3f, 8.8f), Vec2f(2.2f, -5.5f), Vec2f(-5.5f, 14.3f)),
        std::make_tuple(Vec2f(0.0f, 0.0f), Vec2f(-7.7f, 9.9f), Vec2f(7.7f, -9.9f))
    ));

    // Vec2f operator * (float scalar) const
    class MultiplyByScalarF : public VecScaVecFixture {};
    TEST_P(MultiplyByScalarF, MultiplyByScalar)
    {
        Vec2f output = vector * scalar;
        ASSERT_EQ(expected.x, output.x);
        ASSERT_EQ(expected.y, output.y);   
    }

    INSTANTIATE_TEST_SUITE_P(MultiplyByScalar, MultiplyByScalarF, testing::Values(
        std::make_tuple(Vec2f(0.0f, 0.0f), 10.0f, Vec2f(0.0f, 0.0f)),
        std::make_tuple(Vec2f(3.3f, 4.4f), 10.0f, Vec2f(33.0f, 44.0f)),
        std::make_tuple(Vec2f(-6.6f, 4.4f), 5.0f, Vec2f(-33.0f, 22.0f)),
        std::make_tuple(Vec2f(8.8f, -7.7f), -5.0f, Vec2f(-44.0f, 38.5f))
    ));

    // Vec2f operator * (const Vec2f& vector) const
    class MultiplyByVectorF : public VecVecVecFixture {};
    TEST_P(MultiplyByVectorF, MultiplyByVector)
    {
        Vec2f output = vectorOne * vectorTwo;
        ASSERT_EQ(expected.x, output.x);
        ASSERT_EQ(expected.y, output.y);   
    }

    INSTANTIATE_TEST_SUITE_P(MultiplyByVector, MultiplyByVectorF, testing::Values(
        std::make_tuple(Vec2f(0.0f, 0.0f), Vec2f(10.0f, 10.0f), Vec2f(0.0f, 0.0f)),
        std::make_tuple(Vec2f(3.3f, 4.4f), Vec2f(5.5f, 10.0f), Vec2f(18.15f, 44.0f)),
        std::make_tuple(Vec2f(-6.6f, 4.4f), Vec2f(5.5f, -5.0f), Vec2f(-36.3f, -22.0f)),
        std::make_tuple(Vec2f(8.8f, -7.7f), Vec2f(-5.5f, -5.5f), Vec2f(-48.4f, 42.35f))
    ));

    // void operator *= (float scalar)
    class MultiplyEqualsByScalarF : public VecScaVecFixture {};
    TEST_P(MultiplyEqualsByScalarF, MultiplyEqualsByScalar)
    {
        vector *= scalar;
        ASSERT_EQ(expected.x, vector.x);
        ASSERT_EQ(expected.y, vector.y);   
    }

    INSTANTIATE_TEST_SUITE_P(MultiplyEqualsByScalar, MultiplyEqualsByScalarF, testing::Values(
        std::make_tuple(Vec2f(0.0f, 0.0f), 10.0f, Vec2f(0.0f, 0.0f)),
        std::make_tuple(Vec2f(3.3f, 4.4f), 10.0f, Vec2f(33.0f, 44.0f)),
        std::make_tuple(Vec2f(-6.6f, 4.4f), 5.0f, Vec2f(-33.0f, 22.0f)),
        std::make_tuple(Vec2f(8.8f, -7.7f), -5.0f, Vec2f(-44.0f, 38.5f))
    ));

    // void operator *= (const Vec2f& vector)
    class MultiplyEqualsByVectorF : public VecVecVecFixture {};
    TEST_P(MultiplyEqualsByVectorF, MultiplyEqualsByVector)
    {
        vectorOne *= vectorTwo;
        ASSERT_EQ(expected.x, vectorOne.x);
        ASSERT_EQ(expected.y, vectorOne.y);   
    }

    INSTANTIATE_TEST_SUITE_P(MultiplyEqualsByVector, MultiplyEqualsByVectorF, testing::Values(
        std::make_tuple(Vec2f(0.0f, 0.0f), Vec2f(10.0f, 10.0f), Vec2f(0.0f, 0.0f)),
        std::make_tuple(Vec2f(3.3f, 4.4f), Vec2f(5.5f, 10.0f), Vec2f(18.15f, 44.0f)),
        std::make_tuple(Vec2f(-6.6f, 4.4f), Vec2f(5.5f, -5.0f), Vec2f(-36.3f, -22.0f)),
        std::make_tuple(Vec2f(8.8f, -7.7f), Vec2f(-5.5f, -5.5f), Vec2f(-48.4f, 42.35f))
    ));

    class VecVecBoolFixture : public testing::TestWithParam<std::tuple<Vec2f, Vec2f, bool>>
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
    class CompareVectorsF : public VecVecBoolFixture {};
    TEST_P(CompareVectorsF, CompareVectors)
    {
        bool output = vectorOne == vectorTwo;
        ASSERT_EQ(expected, output);
        ASSERT_EQ(expected, output);   
    }

    INSTANTIATE_TEST_SUITE_P(CompareVectors, CompareVectorsF, testing::Values(
        std::make_tuple(Vec2f(-5.5f, 5.5f), Vec2f(-5.5f, 5.5f), true),
        std::make_tuple(Vec2f(0.0f, 0.0f), Vec2f(0.0f, 0.0f), true),
        std::make_tuple(Vec2f(-5.5f, 5.5f), Vec2f(5.5f, -5.5f), false),
        std::make_tuple(Vec2f(6.1f, 0.0f), Vec2f(7.1f, 0.0f), false)
    ));
}