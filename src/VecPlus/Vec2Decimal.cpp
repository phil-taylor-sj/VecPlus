#include <VecPlus/Vec2Base.h>
#include <VecPlus/Vec2Decimal.h>


namespace vecp
{
    template <typename T>
    T Vec2Decimal<T>::mag() const
    {
        return sqrt(pow(this->x, 2) + pow(this->y, 2));
    }

    template <typename T>
    T Vec2Decimal<T>::mag(const Vec2Decimal<T>& vector) const
    {
        return sqrt(pow(this->x - vector.x, 2) + pow(this->y - vector.y, 2));
    }

    template <typename T>
    Vec2Decimal<T> Vec2Decimal<T>::rotate(T angle) const
    {
        T cosAngle = cos(angle * this->m_pi / 180.);
        T sinAngle = sin(angle * this->m_pi / 180.);
        return Vec2Decimal<T> (
            this->x * cosAngle - this->y * sinAngle,
            this->x * sinAngle + this->y * cosAngle
        );
    }

    template <typename T>
    Vec2Decimal<T> Vec2Decimal<T>::floor() const
    {
        return Vec2Decimal<T>(
                std::floor(this->x),
                std::floor(this->y)
            );
    }


    template <typename T>
    Vec2Decimal<T> Vec2Decimal<T>::floorAbs() const
    {
        return Vec2Decimal<T>(
                (this->x < T()) ? std::ceil(this->x) : std::floor(this->x),
                (this->y < T()) ? std::ceil(this->y) : std::floor(this->y)
            );
    }

    template <typename T>
    Vec2Decimal<T> Vec2Decimal<T>::ceil() const
    {
        return Vec2Decimal<T>(
                std::ceil(this->x),
                std::ceil(this->y)
            );
    }

    template <typename T>
    Vec2Decimal<T> Vec2Decimal<T>::ceilAbs() const
    {
        return Vec2Decimal<T>(
                (this->x < T()) ? std::floor(this->x) : std::ceil(this->x),
                (this->y < T()) ? std::floor(this->y) : std::ceil(this->y)
            );
    }

    template <typename T>
    Vec2Decimal<T> Vec2Decimal<T>::operator / (T value) const
    {
        return Vec2Decimal<T>(this->x / value, this->y / value);
    }

    template <typename T>
    Vec2Decimal<T> Vec2Decimal<T>::operator / (const Vec2Decimal<T>& vector) const
    {
        return Vec2Decimal<T>(this->x / vector.x, this->y / vector.y);
    }
    
    template <typename T>
    void Vec2Decimal<T>::operator /= (T value)
    {
        this->x /= value;
        this->y /= value;
    }

    template <typename T>
    void Vec2Decimal<T>::operator /= (const Vec2Decimal<T>& vector)
    {
        this->x /= vector.x;
        this->y /= vector.y;
    }

    template <typename T>
    T Vec2Decimal<T>::dot(const Vec2Decimal<T>& vector) const
    {
        return this->x * vector.x + this->y * vector.y;
    }

    template <typename T>
    T Vec2Decimal<T>::dot(T value) const
    {
        return this->x * value + this->y * value;
    }

    template <typename T>
    T Vec2Decimal<T>::dot(T xTwo, T yTwo) const
    {
        return this->x * xTwo + this->y * yTwo;
    }

    template <typename T>
    Vec2Decimal<T> Vec2Decimal<T>::normalise() const
    {
        T magnitude = sqrt(pow(this->x, 2) + pow(this->y, 2));
        return Vec2Decimal<T>(this->x / magnitude, this->y / magnitude);
    }


    template<typename T>
    Vec2Decimal<float> Vec2Decimal<T>::toFloat() const
    {
        return Vec2Decimal<float>((float)this->x, (float)this->y);
    }

    template<typename T>
    Vec2Decimal<double> Vec2Decimal<T>::toDouble() const
    {
        return Vec2Decimal<double>((double)this->x, (double)this->y);
    }

    template class Vec2Base<float, Vec2Decimal>;

    template class Vec2Base<double, Vec2Decimal>;

    template class Vec2Decimal<float>;

    template class Vec2Decimal<double>;



}
