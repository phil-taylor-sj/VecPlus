#pragma once


namespace vecp
{
    template<typename T>
    Vec3Decimal<float> Vec3Int<T>::toFloat() const
    {
        return Vec3Decimal<float>((float)this->x, (float)this->y, (float)this->z);
    }

    template<typename T>
    Vec3Decimal<double> Vec3Int<T>::toDouble() const
    {
        return Vec3Decimal<double>((double)this->x, (double)this->y, (double)this->z);
    }
}