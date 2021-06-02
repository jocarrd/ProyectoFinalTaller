#include "unit.h"
#include "Array.h"

double* unit(double* vec, int n)
{
    double  small, magv;

    double* outvec = vector(3);

    small = 0.000001;
    magv = norma(vec, 3);

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