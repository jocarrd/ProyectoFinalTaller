#include "Frac.h"
#include <math.h>
#include <stdio.h>

double Frac(double x)
{
    double res = x - floor(x);
  
    return res;
}