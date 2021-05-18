#include "unit.h"

double* unit(double* vec, int n)
{
    double* outvec, small, magv;

    small = 0.000001;
    magv = norm(vec, 3);

    if (magv > small)
        for (int i = 0; i < 3; i++)
        {
            outvec[i] = vec[i] / magv;
        }
    else
        for (int i = 0; i < 3; i++)
        {
            outvec[i] = 0.0;
        }
    return outvec;
}