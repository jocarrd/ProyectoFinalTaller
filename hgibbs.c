#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Array.h"
#include "iodkf.h"
#include "unit.h"
#include "hgibbs.h"
#include <string.h>


double* hgibbs(double* r1, double* r2, double* r3, double Mjd1, double Mjd2, double Mjd3)
{
    double theta, theta1, copa, magr1, magr2, magr3, tolangle, dt21, dt31, dt32, term1, term2, term3;
    double* v2, * p, * pn, * r1n;
    string error;

    error = "ok";
    theta = 0.0;
    theta1 = 0.0;
    magr1 = norma(r1, 3);
    magr2 = norma(r2, 3);
    magr3 = norma(r3, 3);

    for (int i = 0; i < 3; i++)
    {
        v2[i] = 0.0;
    }

    tolangle = 0.01745329251994;
    dt21 = (Mjd2 - Mjd1) * 86400.0;
    dt31 = (Mjd3 - Mjd1) * 86400.0;
    dt32 = (Mjd3 - Mjd2) * 86400.0;

    p = crossProd(r2, 3, r3, 3);
    pn = unit(p);
    r1n = unit(r1);
    copa = asin(dot(pn, 3, r1n, 3));

    if (abs(dot(r1n, 3, pn, 3)) > 0.017452406)
    {
        error = "not coplanar";
    }

    theta = angl(r1, r2);
    theta1 = angl(r2, r3);

    if ((theta > tolangle) || (theta1 > tolangle))
    {
        error = "ngl > 1�";
    }

    term1 = -dt32 * (1.0 / (dt21 * dt31) + GM_Earth / (12.0 * magr1 * magr1 * magr1));
    term2 = (dt32 - dt21) * (1.0 / (dt21 * dt32) + GM_Earth / (12.0 * magr2 * magr2 * magr2));
    term3 = dt21 * (1.0 / (dt32 * dt31) + GM_Earth / (12.0 * magr3 * magr3 * magr3));

    v2 = sumV(vec_x_esc(r1, 3, term1), 3, sumV(vec_x_esc(r2, 3, term2), 3, vec_x_esc(r3, 3, term3), 3), 3);

    printf("%d", "El angulo es: ", theta, " rad");
    printf("Error?: ", error);
    return v2;
}