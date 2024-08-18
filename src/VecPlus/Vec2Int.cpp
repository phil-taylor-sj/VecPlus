#include <VecPlus/Vec2Base.h>
#include <VecPlus/Vec2Base.inl>
#include <VecPlus/Vec2Int.h>



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

    template class Vec2Base<int, Vec2Int>;

    template class Vec2Int<int>;
}    





