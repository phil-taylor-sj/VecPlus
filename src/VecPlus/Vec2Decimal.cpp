#include <VecPlus/Vec2Base.h>
#include <VecPlus/Vec2Decimal.h>


namespace vecp
{
    template class Vec2Base<float, Vec2Decimal>;

    template class Vec2Base<double, Vec2Decimal>;

    template class Vec2Decimal<float>;

    template class Vec2Decimal<double>;
}
