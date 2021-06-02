#include "doubler.h"

void doubler(double cc1, double cc2,  double magrsite1, double  magrsite2, double magr1in,double  magr2in,  double *los1, double *los2, double * los3, double * rsite1, double*  rsite2, double* rsite3, double t1, double t3,  char direct ,  double *r2, double* r3, double* f1, double* f2, double* q1, double* magr1, double* magr2, double* a, double* deltae32) {

    double rho1 = (-cc1 + sqrt(pow(cc1, 2) - 4 * (pow(magrsite1, 2) - pow(magr1in, 2)))) / 2.0;
    double rho2 = (-cc2 + sqrt(pow(cc2, 2) - 4 * (pow(magrsite2, 2) - pow(magr2in, 2)))) / 2.0;

    double* r1 = sumaVectores(vectorPorConst(los1, 3, rho1), 3, rsite1, 3);
    r2 = sumaVectores(vectorPorConst(los2, 3, rho2), 3, rsite2, 3);

    *magr1 = norma(r1, 3);
    *magr2 = norma(r2, 3);

    double* w = vector(5);
    if (direct == 'y') {
        w = vectorPorConst(cross(r1, r2), 3, 1 / (*magr1 * *magr2));
    }
    else {
        w = vectorPorConst(cross(r1, r2), 3, -1 / (*magr1 * *magr2));
    }

    double rho3 = -dot(rsite3, 3, w, 3) / dot(los3, 3, w, 3);
    r3 = sumaVectores(vectorPorConst(los3, 3, rho3), 3, rsite3, 3);
    double magr3 = norma(r3, 3);

    double cosdv21 = dot(r2, 3, r1, 3) / (*magr2 * *magr1);
    double sindv21 = norma(cross(r2, r1), 3) / (*magr2 * *magr1);
    double dv21 = atan2(sindv21, cosdv21);

    double cosdv31 = dot(r3, 3, r1, 3) / (magr3 * *magr1);
    double sindv31 = sqrt(1.0 - pow(cosdv31, 2));
    double dv31 = atan2(sindv31, cosdv31);

    double cosdv32 = dot(r3, 3, r2, 3) / (magr3 * *magr2);
    double sindv32 = norma(cross(r3, r2), 3) / (magr3 * *magr2);
    double dv32 = atan2(sindv32, cosdv32);

    double c1, c3, p;

    if (dv31 > pi) {
        c1 = (*magr2 * sindv32) / (*magr1 * sindv31);
        c3 = (*magr2 * sindv21) / (magr3 * sindv31);
        p = (c1 * *magr1 + c3 * magr3 - *magr2) / (c1 + c3 - 1);
    }
    else {
        c1 = (*magr1 * sindv31) / (*magr2 * sindv32);
        c3 = (*magr1 * sindv21) / (magr3 * sindv32);
        p = (c3 * magr3 - c1 * *magr2 + *magr1) / (-c1 + c3 + 1);
    }

    double ecosv1 = (p / *magr1) - 1;
    double ecosv2 = (p / *magr2) - 1;
    double ecosv3 = (p / magr3) - 1;

    double esinv2;

    if (fabs(dv21 - pi) < 2.71828) {
        esinv2 = (-cosdv21 * ecosv2 + ecosv1) / sindv21;
    }
    else {
        esinv2 = (cosdv32 * ecosv2 - ecosv3) / sindv31;
    }

    double e;
    e = sqrt(pow(ecosv2, 2) + pow(esinv2, 2));
    *a = p / (1 - pow(e, 2));

    double n, s, c, deltam32, deltam12;

    if (e * e < 0.99) {

        double sinde32, cosde32, sinde21, cosde21, deltae21;

        n = sqrt(GM_Earth / pow(*a, 3));
        s = *magr2 / (p * sqrt(1 - pow(e, 2)) * esinv2);
        c = *magr2 / p * (pow(e, 2) + ecosv2);

        sinde32 = magr3 / sqrt(*a * p) * sindv32 - magr3 / p * (1 - cosdv32) * s;
        cosde32 = 1 - *magr2 * magr3 / (*a * p) * (1 - cosdv32);
        *deltae32 = atan2(sinde32, cosde32);

        sinde21 = *magr1 / sqrt(*a * p) * sindv21 + *magr1 / p * (1 - cosdv21) * s;
        cosde21 = 1 - *magr2 * *magr1 / (*a * p) * (1 - cosdv21);
        deltae21 = atan2(sinde21, cosde21);

        deltam32 = *deltae32 + 2 * s * pow((sin(*deltae32 / 2)), 2) - c * sin(*deltae32);
        deltam12 = -deltae21 + 2 * s * pow((sin(deltae21 / 2)), 2) + c * sin(deltae21);
    }
    else {

        double sindh32, sindh21, deltah32, deltah21,

            n = sqrt(GM_Earth / -1 * pow(*a, 3));
        s = *magr2 / p * sqrt(pow(e, 2) - 1) * esinv2;
        c = *magr2 / p * (pow(e, 2) + ecosv2);

        sindh32 = magr3 / sqrt(-1 * *a * p) * sindv32 - magr3 / p * (1 - cosdv32) * s;
        sindh21 = *magr1 / sqrt(-1 * *a * p) * sindv21 + *magr1 / p * (1 - cosdv21) * s;

        deltah32 = log(sindh32 + sqrt(pow(sindh32, 2) + 1));
        deltah21 = log(sindh21 + sqrt(pow(sindh21, 2) + 1));

        deltam32 = -deltah32 + 2 * s * pow((sinh(deltah32 / 2)), 2) + c * sinh(deltah32);
        deltam12 = deltah21 + 2 * s * pow((sinh(deltah21 / 2)), 2) - c * sinh(deltah21);

        *deltae32 = deltah32;
    }
    *f1 = t1 - deltam12 / n;
    *f2 = t3 - deltam32 / n;
    *q1 = sqrt(pow(*f1, 2) + pow(*f2, 2));
}





