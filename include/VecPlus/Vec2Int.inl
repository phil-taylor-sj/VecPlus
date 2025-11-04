#pragma once


namespace vecp
{
    template<typename T>
    Vec2Decimal<float> Vec2Int<T>::toFloat() const
    {
        return Vec2Decimal<float>((float)this->x, (float)this->y);
    }

    template<typename T>
    Vec2Decimal<double> Vec2Int<T>::toDouble() const
    {
        return Vec2Decimal<double>((double)this->x, (double)this->y);
    }
}