#pragma once

namespace vecp
{

    template <typename T, template <typename> class Derived>
    Derived<T> Vec2Base<T, Derived>::abs() const
    {
        return Derived<T>(std::abs(this->x), std::abs(this->y));
    }

    template <typename T, template <typename> class Derived>
    T Vec2Base<T, Derived>::max() const
    {
        return std::max(this->x, this->y);
    }

    template <typename T, template <typename> class Derived>
    T Vec2Base<T, Derived>::min() const
    {
        return std::min(this->x, this->y);
    }

    template <typename T, template <typename> class Derived>
    Derived<T> Vec2Base<T, Derived>::operator + (T scalar) const
    {
        return Derived<T>(this->x + scalar, this->y + scalar);
    }

    template <typename T, template <typename> class Derived>
    void Vec2Base<T, Derived>::operator += (T scalar)
    {
        this->x += scalar;
        this->y += scalar;
    }

    template <typename T, template <typename> class Derived>
    Derived<T> Vec2Base<T, Derived>::operator + (const Derived<T>& vector) const
    {
        return Derived<T>(this->x + vector.x, this->y + vector.y);
    }

    template <typename T, template <typename> class Derived>
    void Vec2Base<T, Derived>::operator += (const Derived<T>& vector)
    {
        this->x += vector.x;
        this->y += vector.y;
    }

    template <typename T, template <typename> class Derived>
    Derived<T> Vec2Base<T, Derived>::operator - (T scalar) const
    {
        return Derived<T>(this->x - scalar, this->y - scalar);
    }

    template <typename T, template <typename> class Derived>
    void Vec2Base<T, Derived>::operator -= (T scalar)
    {
        this->x -= scalar;
        this->y -= scalar;
    }

    template <typename T, template <typename> class Derived>
    Derived<T> Vec2Base<T, Derived>::operator - (const Derived<T>& vector) const
    {
        return Derived<T>(this->x - vector.x, this->y - vector.y);
    }

    template <typename T, template <typename> class Derived>
    void Vec2Base<T, Derived>::operator -= (const Derived<T>& vector)
    {
        this->x -= vector.x;
        this->y -= vector.y;
    }

    template <typename T, template <typename> class Derived>
    Derived<T> Vec2Base<T, Derived>::operator * (T value) const
    {
        return Derived<T>(this->x * value, this->y * value);
    }
    
    template <typename T, template <typename> class Derived>
    Derived<T> Vec2Base<T, Derived>::operator * (const Derived<T>& vector) const
    {
        return Derived<T>(this->x * vector.x, this->y * vector.y);
    }
    
    template <typename T, template <typename> class Derived>
    void Vec2Base<T, Derived>::operator *= (T value)
    {
        this->x *= value;
        this->y *= value;
    }

    template <typename T, template <typename> class Derived>
    void Vec2Base<T, Derived>::operator *= (const Derived<T>& vector)
    {
        this->x *= vector.x;
        this->y *= vector.y;
    }

    template <typename T, template <typename> class Derived>
    bool Vec2Base<T, Derived>::operator == (const Derived<T>& vector)
    {
        return (this->x == vector.x && this->y == vector.y);
    }

    //template <typename T, template <typename> class Derived>
    //Vec2b<T, Derived>::Vec2b(T xin, T yin) : x(xin), y(yin) {}
}


