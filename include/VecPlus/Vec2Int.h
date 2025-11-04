#pragma once
#include <VecPlus/Vec2Base.h>
#include <VecPlus/Vec2Decimal.h>

namespace vecp
{
    /*!
     * \brief Represents a 2D vector with components of privative integer types.
     * 
     * Extends the Vec2Base class with functionaltiy for converting the vector 
     * into a Vec2Decimal types of either floats or doubles.
     * 
     * @tparam T The type of elements in the vector (e.g. float, double, int).
     * 
    */
    template<typename T>
    class Vec2Int : public Vec2Base<T, Vec2Int>
    {
    public:
        /**
         * \brief Convert current vector to a Vec2f instance.
         * 
         * \return A new vector containing the equivalent float values.
         */
        Vec2Decimal<float> toFloat() const;
        
        /**
         * \brief Convert current vector to a Vec2d instance.
         * 
         * \return A new vector containing the equivalent double values.
         */
        Vec2Decimal<double> toDouble() const;

        using Vec2Base<T, Vec2Int>::Vec2Base;
        //Vec2int(int xin = 0, int yin = 0);
    };

    extern template class Vec2Base<int, Vec2Int>;

    extern template class Vec2Int<int>;
}

#include <VecPlus/Vec2Base.inl>