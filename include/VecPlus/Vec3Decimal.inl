#pragma once


namespace vecp
{
    template <typename T>
    T Vec3Decimal<T>::mag() const
    {
        return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
    }

    template <typename T>
    T Vec3Decimal<T>::mag(const Vec3Decimal<T>& vector) const
    {
        return sqrt(
            pow(this->x - vector.x, 2) +
            pow(this->y - vector.y, 2) +
            pow(this->z - vector.z, 2)
        );
    }

    template <typename T>
    Vec3Decimal<T> Vec3Decimal<T>::rotate(char axis, T angle) const
    {
        T cosAngle = cos(angle * this->m_pi / 180.);
        T sinAngle = sin(angle * this->m_pi / 180.);
        Vec3Decimal<T> vector = Vec3Decimal<T>(this->x, this->y, this->z);
        switch (axis) {
        case 'x':
            vector.y = this->y * cosAngle - this->z * sinAngle;
            vector.z = this->y * sinAngle + this->z * cosAngle;
            break;
        case 'y':
            vector.z = this->z * cosAngle - this->x * sinAngle;
            vector.x = this->z * sinAngle + this->x * cosAngle;
            break;
        case 'z':
            vector.x = this->x * cosAngle - this->y * sinAngle;
            vector.y = this->x * sinAngle + this->y * cosAngle;
            break;
        }
        return vector;
    }

    template <typename T>
    Vec3Decimal<T> Vec3Decimal<T>::floor() const
    {
        return Vec3Decimal<T>(
            std::floor(this->x),
            std::floor(this->y),
            std::floor(this->z)
        );
    }

    template <typename T>
    Vec3Decimal<T> Vec3Decimal<T>::floorAbs() const
    {
        return Vec3Decimal<T>(
            (this->x < T()) ? std::ceil(this->x) : std::floor(this->x),
            (this->y < T()) ? std::ceil(this->y) : std::floor(this->y),
            (this->z < T()) ? std::ceil(this->z) : std::floor(this->z)
        );
    }

    template <typename T>
    Vec3Decimal<T> Vec3Decimal<T>::ceil() const
    {
        return Vec3Decimal<T>(
            std::ceil(this->x),
            std::ceil(this->y),
            std::ceil(this->z)
        );
    }

    template <typename T>
    Vec3Decimal<T> Vec3Decimal<T>::ceilAbs() const
    {
        return Vec3Decimal<T>(
            (this->x < T()) ? std::floor(this->x) : std::ceil(this->x),
            (this->y < T()) ? std::floor(this->y) : std::ceil(this->y),
            (this->z < T()) ? std::floor(this->z) : std::ceil(this->z)
        );
    }

    template <typename T>
    Vec3Decimal<T> Vec3Decimal<T>::operator / (T value) const
    {
        return Vec3Decimal<T>(this->x / value, this->y / value, this->z / value);
    }

    template <typename T>
    Vec3Decimal<T> Vec3Decimal<T>::operator / (const Vec3Decimal<T>& vector) const
    {
        return Vec3Decimal<T>(this->x / vector.x, this->y / vector.y, this->z / vector.z);
    }

    template <typename T>
    void Vec3Decimal<T>::operator /= (T value)
    {
        this->x /= value;
        this->y /= value;
        this->z /= value;
    }

    template <typename T>
    void Vec3Decimal<T>::operator /= (const Vec3Decimal<T>& vector)
    {
        this->x /= vector.x;
        this->y /= vector.y;
        this->z /= vector.z;
    }

    template <typename T>
    T Vec3Decimal<T>::dot(const Vec3Decimal<T>& vector) const
    {
        return this->x * vector.x + this->y * vector.y + this->z * vector.z;
    }

    template <typename T>
    T Vec3Decimal<T>::dot(T value) const
    {
        return this->x * value + this->y * value + this->z * value;
    }

    template <typename T>
    T Vec3Decimal<T>::dot(T xTwo, T yTwo, T zTwo) const
    {
        return this->x * xTwo + this->y * yTwo + this->z * zTwo;
    }

    template <typename T>
    Vec3Decimal<T> Vec3Decimal<T>::normalise() const
    {
        T magnitude = sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
        return Vec3Decimal<T>(this->x / magnitude, this->y / magnitude, this->z / magnitude);
    }


    template<typename T>
    Vec3Decimal<float> Vec3Decimal<T>::toFloat() const
    {
        return Vec3Decimal<float>((float)this->x, (float)this->y, (float)this->z);
    }

    template<typename T>
    Vec3Decimal<double> Vec3Decimal<T>::toDouble() const
    {
        return Vec3Decimal<double>((double)this->x, (double)this->y, (double)this->z);
    }
}