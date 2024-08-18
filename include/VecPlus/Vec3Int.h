#pragma once
#include "Vec3Base.h"
#include <VecPlus/Vec3Decimal.h>

namespace vecp
{
    /*!
     * \brief Represents a 2D vector with components of privative integer types.
     * 
     * Extends the Vec2Base class with functionaltiy for converting the vector 
     * into a Vec2Decimal types of either floats or doubles.
     * 
     * \tparam T The type of elements in the vector (e.g. float, double, int).
     * 
    */
    template<typename T>
    class Vec3Int : public Vec3Base<T, Vec3Int>
    {
    public:
        /**
         * \brief Convert current vector to a Vec2f instance.
         * 
         * \return A new vector containing the equivalent float values.
         */
        Vec3Decimal<float> toFloat() const;
        
        /**
         * \brief Convert current vector to a Vec2d instance.
         * 
         * \return A new vector containing the equivalent double values.
         */
        Vec3Decimal<double> toDouble() const;

        using Vec3Base<T, Vec3Int>::Vec3Base;
        //Vec2int(int xin = 0, int yin = 0);
    };

    extern template class Vec3Base<int, Vec3Int>;

    extern template class Vec3Int<int>;
}