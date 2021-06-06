#include "gibbs.h"


void gibbs(double* r1, double* r2, double* r3, double* v2, double theta) {
    double  small = 0.00000001;
    theta = 0.0;
    
    double  theta1 = 0.0;

    double magr1 = norma(r1, 3);
    double magr2 = norma(r2, 3);
    double  magr3 = norma(r3, 3);

    int i;
    for (i = 0; i < 3; i++) {
        v2[i] = 0.0;
    }



    double* p = cross(r2, r3);
    double* q = cross(r3, r1);
    double* w = cross(r1, r2);
    double* pn = unit(p, 3);
    double* r1n = unit(r1, 3);
    double copa = asin(dot(pn, 3, r1n, 3));

    if (abs(dot(r1n, 3, pn, 3)) > 0.017452406) return;


    double* d = sumV(p, 3, sumV(q, 3, w, 3), 3);

    double magd = norma(d, 3);
    double* n =  sumV(esc_x_vec(magr1, p, 3), 3, sumV(esc_x_vec(magr2, q, 3), 3, esc_x_vec(magr3, w, 3), 3), 3);
    double magn = norma(n, 3);
    double* nn = unit(n, 3);
    double* dn = unit(d, 3);



    if ((abs(magd) < small) || (abs(magn) < small) || (dot(nn, 3, dn, 3) < small)) return;

    else {
    theta = angl(r1, r2);
    theta1 = angl(r2, r3);

   
     double r1mr2 = magr1 - magr2;
    double r3mr1 = magr3 - magr1;
   double  r2mr3 = magr2 - magr3;

    double *s =  sumV(esc_x_vec(r1mr2, r3, 3), 3, sumV(esc_x_vec(r3mr1,r2,3), 3,esc_x_vec(r2mr3,r1,3),3),3);
     double *b = cross(d, r2);
    double l = sqrt(GM_Earth / (magd * magn));
   double  tover2 = l / magr2;


    v2 = sumV(esc_x_vec(tover2, b,3),3, esc_x_vec( l , s,3),3);
    

}
}

