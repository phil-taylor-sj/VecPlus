#include "pch.h"
#include <VecPlus/Vec2.h>
#include <iostream>

using namespace vecp;

namespace Vec2Int_Tests
{
    TEST(TestDefault, SetDefaultValues)
    {   
        Vec2i vecOne = Vec2i();
        ASSERT_EQ(vecOne.x, 0);
        ASSERT_EQ(vecOne.y, 0);
    }

    class VecScaVecFixture : public testing::TestWithParam<std::tuple<Vec2i, int, Vec2i>>
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

    class VecVecVecFixture : public testing::TestWithParam<std::tuple<Vec2i, Vec2i, Vec2i>>
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


    // void operator *= (int value)
    class MultiplyEqualsScalarF : public VecScaVecFixture {};
    TEST_P(MultiplyEqualsScalarF, ApplyMultiplyEqualsScalar)
    {
        vector *= scalar;
        ASSERT_EQ(expected.x, vector.x);
        ASSERT_EQ(expected.y, vector.y);   
    }
    
    
    INSTANTIATE_TEST_SUITE_P(ApplyMultiplyEquals, MultiplyEqualsScalarF, testing::Values(
        std::make_tuple(Vec2i(0, 0), 10, Vec2i(0, 0)),
        std::make_tuple(Vec2i(3, 4), 10, Vec2i(30, 40)),
        std::make_tuple(Vec2i(-6, 4), 5, Vec2i(-30, 20)),
        std::make_tuple(Vec2i(8, -7), -5, Vec2i(-40, 35))
    ));

    // Vec2i operator * (int value)
    class MultiplyScalarF : public VecScaVecFixture {};
    TEST_P(MultiplyScalarF, MultiplyScalar)
    {
        Vec2i output = vector * scalar;
        ASSERT_EQ(expected.x, output.x);
        ASSERT_EQ(expected.y, output.y);   
    }

    INSTANTIATE_TEST_SUITE_P(MultiplyEquals, MultiplyScalarF, testing::Values(
        std::make_tuple(Vec2i(0, 0), 10, Vec2i(0, 0)),
        std::make_tuple(Vec2i(3, 4), 10, Vec2i(30, 40)),
        std::make_tuple(Vec2i(-6, 4), 5, Vec2i(-30, 20)),
        std::make_tuple(Vec2i(8, -7), -5, Vec2i(-40, 35))
    ));
}