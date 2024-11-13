#pragma once

namespace vecp
{

    template <typename T, template <typename> class Derived>
    Derived<T> Vec3Base<T, Derived>::abs() const
    {
        return Derived<T>(std::abs(this->x), std::abs(this->y), std::abs(this->z));
    }

    template <typename T, template <typename> class Derived>
    T Vec3Base<T, Derived>::max() const
    {
        return std::max(std::max(this->x, this->y), this->z);
    }

    template <typename T, template <typename> class Derived>
    T Vec3Base<T, Derived>::min() const
    {
        return std::min(std::min(this->x, this->y), this->z);
    }

    template <typename T, template <typename> class Derived>
    Derived<T> Vec3Base<T, Derived>::operator + (const Derived<T>& vector) const
    {
        return Derived<T>(this->x + vector.x, this->y + vector.y, this->z + vector.z);
    }

    template <typename T, template <typename> class Derived>
    void Vec3Base<T, Derived>::operator += (const Derived<T> vector)
    {
        this->x += vector.x;
        this->y += vector.y;
        this->z += vector.z;
    }

    template <typename T, template <typename> class Derived>
    Derived<T> Vec3Base<T, Derived>::operator - (const Derived<T>& vector) const
    {
        return Derived<T>(this->x - vector.x, this->y - vector.y, this->z - vector.z);
    }

    template <typename T, template <typename> class Derived>
    void Vec3Base<T, Derived>::operator -= (const Derived<T>& vector)
    {
        this->x -= vector.x;
        this->y -= vector.y;
        this->z -= vector.z;
    }

    template <typename T, template <typename> class Derived>
    Derived<T> Vec3Base<T, Derived>::operator * (T value) const
    {
        return Derived<T>(this->x * value, this->y * value, this->z * value);
    }
    
    template <typename T, template <typename> class Derived>
    Derived<T> Vec3Base<T, Derived>::operator * (const Derived<T>& vector) const
    {
        return Derived<T>(this->x * vector.x, this->y * vector.y, this->z * vector.z);
    }
    
    template <typename T, template <typename> class Derived>
    void Vec3Base<T, Derived>::operator *= (T value)
    {
        this->x *= value;
        this->y *= value;
        this->z *= value;
    }

    template <typename T, template <typename> class Derived>
    void Vec3Base<T, Derived>::operator *= (const Derived<T>& vector)
    {
        this->x *= vector.x;
        this->y *= vector.y;
        this->z *= vector.z;
    }

    template <typename T, template <typename> class Derived>
    bool Vec3Base<T, Derived>::operator == (const Derived<T>& vector) const
    {
        return (this->x == vector.x && this->y == vector.y && this->z == vector.z);
    }
}
