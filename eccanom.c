#include <stdio.h>
#include <math.h>
#include "eccanom.h"
#include "iodkf.h"


double EccAnom(double M, double e) {
    double f, E, eps = 2.22044604925031e-16;
    int i, maxit;

    maxit = 15;
    i = 1;


    M = fmod(M, 2.0 * pi);


    if (e < 0.8)
        E = M;
    else
        E = pi;


    f = E - e * sin(E) - M;
    E = E - f / (1.0 - e * cos(E));

    // Iteration
    while (fabs(f) > 1e2 * eps) {
        f = E - e * sin(E) - M;
        E = E - f / (1.0 - e * cos(E));
        i = i + 1;
        if (i == maxit)
            printf(" convergence problems in EccAnom");

    }
    return E;
}