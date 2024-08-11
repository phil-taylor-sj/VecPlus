#pragma once
#include "Vec2Base.h"
#include <VecPlus/Vec2Decimal.h>

namespace vecp
{

    template<typename T>
    class Vec2Int : public Vec2Base<T, Vec2Int>
    {
    public:
        /**
         * @brief Convert current vector to a Vec2f instance.
         * 
         * @return A new vector containing the equivalent float values.
         */
        Vec2Decimal<float> toFloat() const;
        
        /**
         * @brief Convert current vector to a Vec2d instance.
         * 
         * @return A new vector containing the equivalent double values.
         */
        Vec2Decimal<double> toDouble() const;

        using Vec2Base<T, Vec2Int>::Vec2Base;
        //Vec2int(int xin = 0, int yin = 0);
    };

    extern template class Vec2Base<int, Vec2Int>;

    extern template class Vec2Int<int>;
}