#include <VecPlus/Vec3Decimal.h>
#include <VecPlus/Vec3Base.h>


namespace vecp
{
    template class Vec3Base<float, Vec3Decimal>;

    template class Vec3Base<double, Vec3Decimal>;

    template class Vec3Decimal<float>;

    template class Vec3Decimal<double>;
}
