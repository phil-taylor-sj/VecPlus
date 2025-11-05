#pragma once

#include <cmath>
#include <algorithm>


namespace vecp
{
    /*!
     * \brief Represents a 3D vector with components of type T.
     * 
     * This template class provides basic operations for generic 3D vectors 
     * such as addition, subtraction, multiplication, and boolean comparision.
     * 
     * \tparam T The type of elements in the vector (e.g. float, double, int).
     * 
    */
    template <typename T, template <typename> class Derived>
    class Vec3Base
    {
    public:
        T x; /// The x-coordinate of the vector.
        T y; /// The y-coordinate of the vector.
        T z; /// The z-coordiante of the vector
        

        /*!
         * \brief Get the absolute values of each component.
         * 
         * \return A new vector containing the absolute values.
         * 
        */
        Derived<T> abs() const;

        /*!
         * \brief Get the maximum value of all components.
         * 
         * \return Returns the maximum value.
         * 
        */
        T max() const;

        /*!
         * \brief Get the maximum value of each components two vectors.
         * 
         * \return Returns a vector of maximum values.
         * 
        */
        Derived<T> max(const Derived<T>& vector) const;

        /*!
         * \brief Get the minimum value of all components.
         * 
         * \return Returns the minimum value.
         * 
        */
        T min() const; 
        
        /*!
         * \brief Get the minimum value of each components two vectors.
         * 
         * \return Returns a vector of minimum values.
         * 
        */
        Derived<T> min(const Derived<T>& vector) const;

        /*!
         * \brief Overload the addition operator (+) for vector addition.
         * 
         * \param vector The vector to be added to  the current vector.
         * \return A new vector containing the modified values.
         * 
        */
        Derived<T> operator + (const Derived<T>& vector) const;

        /*!
         * \brief Overload the addition assignment operator (+=) for vector addition.
         * 
         * \param vector The vector to be added to the current vector.
        */
        void operator += (const Derived<T> vector);
        
        /*!
         * \brief Overload the subtration operator (-) for vector subtraction.
         * 
         * \param vector The vector to be subtracted from the current vector.
         * \return A new vector containing the modified values.
         * 
        */
        Derived<T> operator - (const Derived<T>& vector) const;

        /*!
         * \brief Overload the subtraction assignment operator (-=) for vector subtraction.
         * 
         * \param vector The vector to be subtracted from the current vector.
        */
        void operator -= (const Derived<T>& vector);

        /*!
         * \brief Overload the multiplication operator (*) for vector by scalar multiplication.
         * 
         * \param value The scalar value to be multiplied.
         * \return A new vector containing the modified values.
        */
        Derived<T> operator * (T value) const;
        
        /*!
         * \brief Overload the multiplication operator (*) for vector by vector multiplication.
         * 
         * \param vector The vector to multiple the current vector values by.
         * \return A new vector containing the modified values.
        */
        Derived<T> operator * (const Derived<T>& vector) const;
        
        /*!
         * \brief Overload the multiplication operator (*=) for vector by scalar multiplication.
         * 
         * \param value The scalar value to multiply the current vector by.
        */
        void operator *= (T value);

        /*!
         * \brief Overload the multiplication operator (*=) for vector by vector multiplication.
         * 
         * \param vector The vector multiply the current vector values by.
        */
        void operator *= (const Derived<T>& vector);

        /*!
         * \brief Overload the equality operator (==) for vector comparison.
         *
         * \param vector The vector to compare with.
         * \return True if both vector components are equal, otherwise false.
        */

        bool operator == (const Derived<T>& vector) const;

        /*!
         * \brief Construct a new Vec2 object with given x and y components.
         * 
         * \param xin The x component of the vector.
         * \param yin The y component of the vector.
        */
        Vec3Base(T xin = T(), T yin = T(), T zin = T()) : x(xin), y(yin), z(zin) {}
    };
}

#include <VecPlus/Vec3Base.inl>