#pragma once

namespace vecp
{

    template <typename T, template <typename> class Derived>
    Derived<T> Vec2Base<T, Derived>::operator + (const Derived<T>& vector) const
    {
        return Derived<T>(this->x + vector.x, this->y + vector.y);
    }

    template <typename T, template <typename> class Derived>
    Derived<T> Vec2Base<T, Derived>::operator - (const Derived<T>& vector) const
    {
        return Derived<T>(this->x - vector.x, this->y - vector.y);
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
    void Vec2Base<T, Derived>::operator += (const Derived<T> vector)
    {
        this->x += vector.x;
        this->y += vector.y;
    }

    template <typename T, template <typename> class Derived>
    void Vec2Base<T, Derived>::operator -= (const Derived<T>& vector)
    {
        this->x -= vector.x;
        this->y -= vector.y;
    }

    template <typename T, template <typename> class Derived>
    bool Vec2Base<T, Derived>::operator == (const Derived<T>& vector)
    {
        return (this->x == vector.x && this->y == vector.y);
    }

    //template <typename T, template <typename> class Derived>
    //Vec2b<T, Derived>::Vec2b(T xin, T yin) : x(xin), y(yin) {}
}


