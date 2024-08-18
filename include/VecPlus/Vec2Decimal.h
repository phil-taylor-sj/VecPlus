#pragma once
#include <VecPlus/Vec2Base.h>

namespace vecp
{

    /*! 
     * \brief Represents a 2D vector with components of primative decimal types.
     * 
     * Extends the Vec2Base class with functionality for division, rotation, 
     * calculation of mangitude, and calculation of the dot product.
     * 
     * \tparam T The type of elements in the vector (e.g. float, double, int).
     * 
    */
    template <typename T>
    class Vec2Decimal : public Vec2Base<T, Vec2Decimal>
    {
    public:
        
        /*!
         * \brief Calculate the magnitude (length) of the vector.
         * 
         * \return The magnitude of the vector. 
        */
        T mag() const;

        /*!
         * \brief Calcualte the magnitude (legnth) of the distance vector between
         * this vector and another vector.
         * 
         * \param vector The other vector to calculate the distance vector between.
         * \return The magnitude of the transform vector.
         * 
        */
        T mag(const Vec2Decimal<T>& vector) const;

        /*!
         * \brief Apply a rotation to the vector by a given angle.
         * 
         * \param angle The angle (in degrees) by which to rotate the vector.
        */
        void rotate(T angle);


        /*!
         * \brief Overload the division operator (/) for vector by scalar division.
         * 
         * \param value The scalar value to divide the current vector by.
         * \return A new vector containing the modified values.
        */
        Vec2Decimal<T> operator / (T value) const;

        /*!
         * \brief Overload the division operator (/) for vector by vector division.
         * 
         * \param vector The vector to divide the current vector values by.
         * \return A new vector containing the modified values.
        */
        Vec2Decimal<T> operator / (const Vec2Decimal<T>& vector) const;
        
        /*!
         * \brief Overload the division operator (/=) for vector by scalar division.
         * 
         * \param value The scalar value to divide the current vector by.
        */
        void operator /= (T value);

        /*!
         * \brief Overload the division operator (/=) for vector by scalar division.
         * 
         * \param vector The vector to divide the current vector values by.
        */
        void operator /= (const Vec2Decimal<T>& vector);

        /*!
         * \brief Calculate dot product of the current vector and another vector.
         * 
         * \param vector The vector to apply to the current vector.
         * \return The dot product of the vectors.
        */
        T dot(const Vec2Decimal<T>& vector) const;

        /*!
         * \brief Calculate dot product of the current vector a vector of two identical scalar values.
         * 
         * \param value The x & y scalar value to apply to the current vector.
         * \return The dot product of the vectors.
        */
        T dot(T value) const;

        /*!
         * \brief Calculate dot product of the current vector and a vector of two scalar values.
         * 
         * \param xTwo The x scalar value to apply to the current vector.
         * \param yTwo The y scalar valeu to apply to the current vector.
         * \return The dot product of the vectors.
        */
        T dot(T xTwo, T yTwo) const;

        using Vec2Base<T, Vec2Decimal>::Vec2Base;
        //Vec2fd(T xin = 0., T yin = 0.);

    private:
        double m_pi = 3.141592653589793;
    }; 

    extern template class Vec2Decimal<float>;

    extern template class Vec2Decimal<double>;

    extern template class Vec2Base<float, Vec2Decimal>;

    extern template class Vec2Base<double, Vec2Decimal>;

}
