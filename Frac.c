#include "Frac.h"
#include <math.h>
#include <stdio.h>

double Frac(double x)
{
    double res = x - floor(x);
    printf("res %d\n", res);
    printf("x %d\n", x);
    printf("floor %d\n", floor(x));


    return res;
}