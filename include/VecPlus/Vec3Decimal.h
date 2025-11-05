#pragma once

#include <VecPlus/Vec3Base.h>


namespace vecp
{

    /*! 
     * \brief Represents a 3D vector with components of primative decimal types.
     * 
     * Extends the Vec2Base class with functionality for division, rotation, 
     * calculation of mangitude, and calculation of the dot product.
     * 
     * \tparam T The type of elements in the vector (e.g. float, double, int).
     * 
    */
    template <typename T>
    class Vec3Decimal : public Vec3Base<T, Vec3Decimal>
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
        T mag(const Vec3Decimal<T>& vector) const;

        /*!
         * \brief Apply a rotation to the vector by a given angle.
         * 
         * \param angle The angle (in degrees) by which to rotate the vector.
        */
        Vec3Decimal<T> rotate(char axis, T angle) const;

        /*!
         * \brief Round each component down to the nearest integer.
         * 
         * \return A new vector containing the floored compoent.
        */
        Vec3Decimal<T> floor() const;

        /*!
         * \brief Round each component towards zero to the nearest integer.
         * 
         * \return A new vector containing the floored compoent.
        */
        Vec3Decimal<T> floorAbs() const;

        /*!
         * \brief Round each component up to the nearest integer.
         * 
         * \return A new vector containing the rounded compoents.
        */
        Vec3Decimal<T> ceil() const;

        /*!
         * \brief Round each component away from zero to the nearest integer.
         * 
         * \return A new vector containing the rounded compoents.
        */
        Vec3Decimal<T> ceilAbs() const;

        /*!
         * \brief Overload the division operator (/) for vector by scalar division.
         * 
         * \param value The scalar value to divide the current vector by.
         * \return A new vector containing the modified values.
        */
        Vec3Decimal<T> operator / (T value) const;

        /*!
         * \brief Overload the division operator (/) for vector by vector division.
         * 
         * \param vector The vector to divide the current vector values by.
         * \return A new vector containing the modified values.
        */
        Vec3Decimal<T> operator / (const Vec3Decimal<T>& vector) const;
        
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
        void operator /= (const Vec3Decimal<T>& vector);

        /*!
         * \brief Calculate dot product of the current vector and another vector.
         * 
         * \param vector The vector to apply to the current vector.
         * \return The dot product of the vectors.
        */
        T dot(const Vec3Decimal<T>& vector) const;

        /*!
         * \brief Calculate dot product of the current vector a vector of three identical scalar values.
         * 
         * \param value The x & y scalar value to apply to the current vector.
         * \return The dot product of the vectors.
        */
        T dot(T value) const;

        /*!
         * \brief Calculate dot product of the current vector and a vector of three scalar values.
         * 
         * \param xTwo The x scalar value to apply to the current vector.
         * \param yTwo The y scalar valeu to apply to the current vector.
         * \param zTwo The z scalar valeu to apply to the current vector.
         * \return The dot product of the vectors.
        */
        T dot(T xTwo, T yTwo, T zTwo) const;

        /*!
         * \brief Normalise the current vector and return the result as a new vector.
         *
         * \return A new vector containing the normalised x and y components.
        */
        Vec3Decimal<T> normalise() const;

        /**
         * \brief Convert current vector to a Vec3f instance.
         * 
         * \return A new vector containing the equivalent float values.
         */
        Vec3Decimal<float> toFloat() const;
        
        /**
         * \brief Convert current vector to a Vec3d instance.
         * 
         * \return A new vector containing the equivalent double values.
         */
        Vec3Decimal<double> toDouble() const;

        using Vec3Base<T, Vec3Decimal>::Vec3Base;
        //Vec2fd(T xin = 0., T yin = 0.);

    private:
        inline static constexpr T m_pi = 3.141592653589793;
    }; 
}

#include <VecPlus/Vec3Decimal.inl>