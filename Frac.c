#include "Frac.h"
#include <math.h>

double Frac(double x)
{
    double res = x - floor(x);
    return res;
}