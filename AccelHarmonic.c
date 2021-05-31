
#include "AccelHarmonic.h"




double* AccelHarmonic(double* r, double** E, int n_max, int m_max) {

    
    double r_ref = 6378.1363e3;   
    double gm = 398600.4415e9;    

    
    double* r_bf = prodMatVec(E, 3, 3, r, 3);


  
    double d = norma(r_bf, 3);                    
    double latgc = asin(r_bf[3] / d);
    double lon = atan2(r_bf[2], r_bf[1]);

    double** pnm = array(3, 3), ** dpnm = array(3, 3);
    Legendre(n_max, m_max, latgc, pnm, dpnm);

    double dUdr = 0;
    double dUdlatgc = 0;
    double dUdlon = 0;
    double q3 = 0;
    double q2 = q3;
    double q1 = q2;
    double b1, b2, b3;
    for (int n = 0; n < n_max; n++) {
        b1 = (-gm / d * d) * pow((r_ref / d), n) * (n + 1);
        b2 = (gm / d) * pow((r_ref / d), n);
        b3 = (gm / d) * pow((r_ref / d), n);
        for (int m = 0; m < m_max; m++) {
            q1 = q1 + pnm[n + 1][m + 1] * (Cnm[n + 1][m + 1] * cos(m * lon) + Snm[n + 1][m + 1] * sin(m * lon));
            q2 = q2 + dpnm[n + 1][m + 1] * (Cnm[n + 1][m + 1] * cos(m * lon) + Snm[n + 1][m + 1] * sin(m * lon));
            q3 = q3 + m * pnm[n + 1][m + 1] * (Snm[n + 1][m + 1] * cos(m * lon) - Cnm[n + 1][m + 1] * sin(m * lon));
        }
        dUdr = dUdr + q1 * b1;
        dUdlatgc = dUdlatgc + q2 * b2;
        dUdlon = dUdlon + q3 * b3;
        q3 = 0;
        q2 = q3;
        q1 = q2;
    }

    // Body-fixed acceleration
    double r2xy = pow(r_bf[1], 2) + pow(r_bf[2], 2);

    double ax = (1 / d * dUdr - r_bf[3]) / (pow(d, 2) * sqrt(r2xy)) * dUdlatgc * r_bf[1] - (1 / r2xy * dUdlon) * r_bf[2];
    double ay = (1 / d * dUdr - r_bf[3]) / (pow(d, 2) * sqrt(r2xy)) * dUdlatgc * r_bf[2] + (1 / r2xy * dUdlon) * r_bf[1];
    double az = 1 / d * dUdr * r_bf[3] + sqrt(r2xy) / pow(d, 2) * dUdlatgc;

    double* a_bf = vector(3);
    a_bf[0] = ax;
    a_bf[1] = ay;
    a_bf[2] = az;

    //Inertial acceleration
    double* a = prodMatVec(E, 3, 3, a_bf, 3);
    return a;
}