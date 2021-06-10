#include <stdio.h>
#include <math.h>
#include "Array.h"
#include "iodkf.h"
#include "Position.h"
#include "R_x.h"
#include "NutAngles.h"
#include "MeanObliquity.h"
#include "NutMatrix.h"
#include "Mjday_TDB.h"
#include "doubler.h"
#include "globales.h"
#include <stdio.h>
#include <cfloat>
#include "eccanom.h"
#include "EqnEquinox.h"
#include "Frac.h"
#include "gast.h"
#include "gmst.h"
#include "Legendre.h"
#include "R_x.h"
#include "R_y.h"
#include "R_z.h"
#include "timediff.h"
#include "unit.h"
#include "Cheb3D.h"

#define FAIL() printf("\nfailure in %s() line %d\n", __func__, __LINE__)
#define _assert(test) do { if (!(test)) { FAIL(); return 1; } } while(0)
#define _verify(test) do { int r=test(); tests_run++; if(r) return r; } while(0)


int tests_run = 0;

int esIgual(double c, double b) {

    printf("c: %f\n", c);
    printf("b: %f\n", b);


    if (fabs(c - b) <= DBL_EPSILON) {
        return 0;

    }
    return 1;
}
int test_Cheb3D_1() {


    double* Cx = vector(3);
    Cx[0] = 1;
    Cx[1] = 2;
    Cx[2] = 3;
    double* Cy = vector(3);
    Cy[0] = 4;
    Cy[1] = 5;
    Cy[2] = 6;
    double* Cz = vector(3);
    Cz[0] = 7;
    Cz[1] = 8;
    Cz[2] = 9;

    double* resultado = Cheb3D(9, 3, 3, 10, Cx, Cy, Cz);


    double* resultado_real = vector(3);
    resultado_real[0] = 2.42857142857143;
    resultado_real[1] = 7.57142857142857;
    resultado_real[2] = 12.7142857142857;

    printVector(resultado, 3);
    printVector(resultado_real, 3);

    _assert(compareV(resultado, 3, resultado_real, 3));






    return 0;


}

int test_Rz1() {

    double** resultado = R_z(0.1);

    double** comprobar = array(3, 3);
    comprobar[0][0] = 0.9950041652780258200;
    comprobar[0][1] = 0.0998334166468281550;
    comprobar[0][2] = 0.0000000000000000000;

    comprobar[1][0] = -0.0998334166468281550;
    comprobar[1][1] = 0.9950041652780258200;
    comprobar[1][2] = 0.0000000000000000000;

    comprobar[2][0] = 0.0000000000000000000;
    comprobar[2][1] = 0.0000000000000000000;
    comprobar[2][2] = 1.0000000000000000000;

    printArray(resultado, 3, 3);

    _assert(compare(comprobar, 3, 3, resultado, 3, 3));


    return 0;


}

int test_unit1() {

    double* ds = vector(3);
    ds[0] = 1;
    ds[1] = 2;
    ds[2] = 3;


    double* f = unit(ds, 3);

    double* resultado = vector(3);
    resultado[0] = 0.2672612419124244000;
    resultado[1] = 0.5345224838248487900;
    resultado[2] = 0.8017837257372731900;




    printVector(f, 3);

    _assert(compareV(f, 3, resultado, 3));


    return 0;


}

int test_unit2() {

    double* ds = vector(3);
    ds[0] = 5;
    ds[1] = 6;
    ds[2] = 7;


    double* f = unit(ds, 3);

    double* resultado = vector(3);
    resultado[0] = 0.4767312946227961800;
    resultado[1] = 0.5720775535473553400;
    resultado[2] = 0.6674238124719146200;




    printVector(f, 3);

    _assert(compareV(f, 3, resultado, 3));


    return 0;


}

int test_Timediff1() {

    double* UT1_GPS = vector(1);
    double* TT_UTC = vector(1);
    double* GPS_UTC = vector(1);


    timediff(20, 22, UT1_GPS, TT_UTC, GPS_UTC);



    printf("Tests run: %f\n", *UT1_GPS);
    printf("Tests run: %f\n", *TT_UTC);
    printf("Tests run: %f\n", *GPS_UTC);


    _assert(esIgual(*UT1_GPS, 17.000000));
    _assert(esIgual(*TT_UTC, 54.184000));
    _assert(esIgual(*GPS_UTC, 3.000000));



    return 0;


}

int test_Ry1() {

    double** resultado = R_y(0.1);

    double** comprobar = array(3, 3);
    comprobar[0][0] = 0.9950041652780258200;
    comprobar[0][1] = 0.0000000000000000000;
    comprobar[0][2] = -0.0998334166468281550;

    comprobar[1][0] = 0.0000000000000000000;
    comprobar[1][1] = 1.0000000000000000000;
    comprobar[1][2] = 0.0000000000000000000;

    comprobar[2][0] = 0.0998334166468281550;
    comprobar[2][1] = 0.0000000000000000000;
    comprobar[2][2] = 0.9950041652780258200;

    printArray(resultado, 3, 3);

    _assert(compare(comprobar, 3, 3, resultado, 3, 3));


    return 0;


}
int test_Rx1() {



    double** resultado = R_x(0.1);

    double** comprobar = array(3, 3);
    comprobar[0][0] = 1.0000000000000000000;
    comprobar[0][1] = 0.0000000000000000000;
    comprobar[0][2] = 0.0000000000000000000;

    comprobar[1][0] = 0.0000000000000000000;
    comprobar[1][1] = 0.9950041652780258200;
    comprobar[1][2] = 0.0998334166468281550;

    comprobar[2][0] = 0.0000000000000000000;
    comprobar[2][1] = -0.0998334166468281550;
    comprobar[2][2] = 0.9950041652780258200;

    printArray(resultado, 3, 3);

    _assert(compare(comprobar, 3, 3, resultado, 3, 3));


    return 0;


}
int test_Legendre_1() {

    double** pnm_real = array(2, 3);
    double** dpnm_real = array(2, 3);



    //cambiar valores
    pnm_real[0][0] = 1.0000000000000000000;
    pnm_real[0][1] = 0.0000000000000000000;
    pnm_real[0][2] = 0.0000000000000000000;

    pnm_real[1][0] = 0.2444270239242194700;
    pnm_real[1][1] = -1.7147173032239305000;
    pnm_real[1][2] = 0.0000000000000000000;

    dpnm_real[0][0] = 0.0000000000000000000;
    dpnm_real[0][1] = 0.0000000000000000000;
    pnm_real[0][2] = 0.0000000000000000000;

    dpnm_real[1][0] = -1.7147173032239305000;
    dpnm_real[1][1] = -0.2444270239242194700;
    dpnm_real[1][2] = 0.0000000000000000000;




    double** pnm = array(2, 3);
    double** dpnm = array(2, 3);

    Legendre(1, 2, 3, pnm, dpnm);
    printArray(pnm, 2, 3);
    printArray(dpnm, 2, 3);


    _assert(compare(pnm, 2, 3, pnm_real, 2, 3));
    _assert(compare(dpnm, 2, 3, dpnm_real, 2, 3));


    return 0;


}

int test_Gmst_1() {


    double resultado = gmst(34.2);

    printf("resultado: %f\n", resultado);

    _assert(esIgual(resultado, 2.818181));



    return 0;


}

int test_Gmst_2() {


    double resultado = gmst(21.1);

    printf("resultado: %f\n", resultado);

    _assert(esIgual(resultado, 1.964506));



    return 0;


}

int test_Gast_1() {

    double resultado = gast(4.974611635416653e+04);
    printf("resultado: %f\n", resultado);

    _assert(esIgual(resultado, 2.96320762344617));

    return 0;


}
int test_fracc1() {

    double f = Frac(5.1);


    _assert(esIgual(f, 0.10000));


    return 0;


}

int test_fracc2() {

    double f = Frac(6);


    _assert(esIgual(f, 0));


    return 0;


}

int test_EqnEquinox_1() {

    double resultado = EqnEquinox(4.974611635416653e+04);

    printf("resultado: %f\n", resultado);

    _assert(esIgual(resultado, 0.000057));

    return 0;


}
int test_Eccanom_1() {


    double resultado = EccAnom(40, 23);
    printf("resultado: %f\n", resultado);

    _assert(esIgual(3.1066, resultado));


    return 0;


}

int test_Eccanom_2() {


    double resultado = EccAnom(1, 3);
    printf("resultado: %f\n", resultado);

    _assert(esIgual(2.5850, resultado));


    return 0;


}


int test_Doubler_1() {

    //entrada

    double* los1 = vector(3);
    los1[0] = 1;
    los1[1] = 2;
    los1[2] = 3;
    double* los2 = vector(3);
    los2[0] = 1;
    los2[1] = 2;
    los2[2] = 3;
    double* los3 = vector(3);
    los3[0] = 1;
    los3[1] = 2;
    los3[2] = 3;
    double* rsite1 = vector(3);
    rsite1[0] = 1;
    rsite1[1] = 2;
    rsite1[2] = 3;
    double* rsite2 = vector(3);
    rsite2[0] = 1;
    rsite2[1] = 2;
    rsite2[2] = 3;
    double* rsite3 = vector(3);
    rsite3[0] = 1;
    rsite3[1] = 2;
    rsite3[2] = 3;




    //salida

    double* r2 = vector(3);
    double* r3 = vector(3);
    double* f1 = vector(1);
    double* f2 = vector(1);
    double* q1 = vector(1);
    double* magr1 = vector(1);
    double* magr2 = vector(1);
    double* a = vector(1);
    double* deltae32 = vector(1);



    doubler(1, 2, 3, 4, 5, 6, los1, los2, los3, rsite1, rsite2, rsite3, 1, 1, 'c', r2, r3, f1, f2, q1, magr1, magr2, a, deltae32);



    printVector(r2, 3);
    printVector(r3, 3);
    printVector(f1, 1);
    printVector(f2, 1);
    printVector(q1, 1);
    printVector(magr1, 1);
    printVector(magr2, 1);
    printVector(a, 1);
    printVector(deltae32, 1);





    return 0;


}



int NutMatrix_01() {
    double **m, **sol;

    sol = array(3, 3);
    m = array(3, 3);

    sol[0][0] = 0.999999998058958;
    sol[0][1] = -5.71647031444515e-05;
    sol[0][2] = -2.47846909052258e-05;
    sol[1][0] = 5.71655733262547e-05;
    sol[1][1] = 0.99999999774968;
    sol[1][2] = 3.51103624666727e-05;
    sol[2][0] = 2.47826837760046e-05;
    sol[2][1] = -3.51117792296018e-05;
    sol[2][2] = 0.999999999076491;

    m = NutMatrix(49746.1097222222);

    _assert(compare(m, 3, 3, sol, 3, 3));
    freeArray(sol, 3, 3);
    freeArray(m, 3, 3);

    return 0;
}



int NutAngles_01() {
    double dpsi, deps, dpsi_sol, deps_sol;

    dpsi_sol = 6.23063736216799e-05;
    deps_sol = -3.51110708894389e-05;

    NutAngles(49746.1097222222, &dpsi, &deps);
    printf("dpsis=%5.15lf deps=%5.15lf \n", dpsi, deps);

    _assert((fabs(dpsi_sol - dpsi) < pow(10, -10))&& (fabs(deps_sol - deps) < pow(10, -10)));

    return 0;
}

int Mjday_TDB_01() {
    double mj, sol;

    sol = 49746.1097222304;
    
    _assert(fabs(sol - Mjday_TDB(49746.1097222222)) < pow(10, -10));

    return 0;


}




int MeanObliquity_01() {
    double mj, sol;
    sol = 0.409103979370901;

    
   

    _assert(fabs(sol - MeanObliquity(49746.1097222222)) < pow(10, -10));
    return 0;
}


int R_x_01() {
    double **sol, **m;

    sol = array(3, 3);
    m = array(3, 3);

    sol[0][0] = 1.0;
    sol[0][1] = 0.0;
    sol[0][2] = 0.0;
    sol[1][0] = 0.0;
    sol[1][1] = 0.540302305868140;
    sol[1][2] = 0.841470984807897;
    sol[2][0] = 0.0;
    sol[2][1] = -0.841470984807897;
    sol[2][2] = 0.540302305868140;

    m = R_x(1.0);

    _assert(compare(m, 3, 3, sol, 3, 3));
    freeArray(sol, 3, 3);
    freeArray(m, 3, 3);

    return 0;
}

int position_01() {
    double lon, lat, alt, *Rs, *sol;

    sol = vector(3);
    lon = -2.76234307910694;
    lat = 0.376551295459273;
    alt = 300.2;
    sol[0] = -5512567.84003607;
    sol[1] = -2196994.44666933;
    sol[2] = 2330804.96614689;

    Rs = position(lon, lat, alt);

    _assert(compareV(Rs, 3, sol, 3));

    freeVector(Rs, 3);

    return 0;
}

int dot_01() {
    double *v1, *v2, sol;

    v1 = vector(3);
    v2 = vector(3);

    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    v2[0] = 1;
    v2[1] = 2;
    v2[2] = 3;
    sol = 14.0;

    _assert(fabs(sol - dot(v1, 3, v2, 3)) < pow(10, -10));

    freeVector(v1, 3);
    freeVector(v2, 3);

    return 0;
}

int norma_01() {
    double *w, sol;

    w = vector(3);
    w[0] = 2.0;
    w[1] = 0.0;
    w[2] = 0.0;
    sol = 2.0;

    _assert(fabs(sol - norma(w, 3)) < pow(10, -10));

    freeVector(w, 3);

    return 0;
}

int trasp_01() {
    double **m1, **sol, **tr;

    sol = array(3, 3);
    m1 = array(3, 3);

    m1[0][0] = 1;
    m1[0][1] = 0;
    m1[0][2] = 2;
    m1[1][0] = -1;
    m1[1][1] = 5;
    m1[1][2] = 0;
    m1[2][0] = 0;
    m1[2][1] = 3;
    m1[2][2] = -9;

    sol[0][0] = 1;
    sol[0][1] = -1;
    sol[0][2] = 0;
    sol[1][0] = 0;
    sol[1][1] = 5;
    sol[1][2] = 3;
    sol[2][0] = 2;
    sol[2][1] = 0;
    sol[2][2] = -9;

    tr = trasp(m1, 3);



    _assert(compare(tr, 3, 3, sol, 3, 3));

    freeArray(sol, 3, 3);
    freeArray(tr, 3, 3);
    freeArray(m1, 3, 3);

    return 0;
}

int inv_01() {
    double **m1, **sol, **in;

    sol = array(3, 3);
    m1 = array(3, 3);

 
    sol = array(3, 3);
    sol[0][0] = 1;
    sol[1][1] = 1;
    sol[2][2] = 1;
    m1 = eye(3);

    m1[0][0] = 3;
    m1[0][1] = 0;
    m1[0][2] = 1;
    m1[1][0] = 3;
    m1[1][1] = 0;
    m1[1][2] = 0;
    m1[2][0] = 5;
    m1[2][1] = 1;
    m1[2][2] = 1;


    in = inv(m1, 3);
    // printArray(sol,3,3);
    printArray(in, 3, 3);

    _assert(compare(in, 3, 3, sol, 3, 3));

    freeArray(sol, 3, 3);
    freeArray(in, 3, 3);
    freeArray(m1, 3, 3);

    return 0;
}

int prod_01() {
    double **m, **m1, **m2, **sol;

    sol = array(3, 3);
    m1 = array(3, 3);
    m2 = array(3, 3);

    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[0][2] = 3;
    m1[1][0] = 4;
    m1[1][1] = 5;
    m1[1][2] = 6;
    m1[2][0] = 7;
    m1[2][1] = 8;
    m1[2][2] = 9;
    m2[0][0] = 1;
    m2[0][1] = 2;
    m2[0][2] = 3;
    m2[1][0] = 4;
    m2[1][1] = 5;
    m2[1][2] = 6;
    m2[2][0] = 7;
    m2[2][1] = 8;
    m2[2][2] = 9;

    sol[0][0] = 30;
    sol[0][1] = 36;
    sol[0][2] = 42;
    sol[1][0] = 66;
    sol[1][1] = 81;
    sol[1][2] = 96;
    sol[2][0] = 102;
    sol[2][1] = 126;
    sol[2][2] = 150;

    m = prod(m1, 3, 3, m2, 3, 3);

    // printf("Producto de matrices: \n");
    // printArray(m, 3, 3);
    // printArray(sol, 3, 3);

    _assert(compare(m, 3, 3, sol, 3, 3));

    freeArray(sol, 3, 3);
    freeArray(m, 3, 3);
    freeArray(m1, 3, 3);
    freeArray(m2, 3, 3);

    return 0;
}

int eye_01() {
    double **m, **sol;

    sol = array(3, 3);
    sol[0][0] = 1;
    sol[1][1] = 1;
    sol[2][2] = 1;
    m = eye(3);

    _assert(compare(m, 3, 3, sol, 3, 3));

    freeArray(sol, 3, 3);
    freeArray(m, 3, 3);

    return 0;
}

int sum_01() {
    double **m, **m1, **m2, **sol;

    sol = array(3, 3);
    m1 = array(3, 3);
    m2 = array(3, 3);

    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[0][2] = 3;
    m1[1][0] = 1;
    m1[1][1] = 2;
    m1[1][2] = 3;
    m1[2][0] = 1;
    m1[2][1] = 2;
    m1[2][2] = 3;
    m2[0][0] = 1;
    m2[0][1] = 2;
    m2[0][2] = 3;
    m2[1][0] = 1;
    m2[1][1] = 2;
    m2[1][2] = 3;
    m2[2][0] = 1;
    m2[2][1] = 2;
    m2[2][2] = 3;

    sol[0][0] = 2;
    sol[0][1] = 4;
    sol[0][2] = 6;
    sol[1][0] = 2;
    sol[1][1] = 4;
    sol[1][2] = 6;
    sol[2][0] = 2;
    sol[2][1] = 4;
    sol[2][2] = 6;

    m = sum(m1, 3, 3, m2, 3, 3);

    _assert(compare(m, 3, 3, sol, 3, 3));

    freeArray(sol, 3, 3);
    freeArray(m, 3, 3);
    freeArray(m1, 3, 3);
    freeArray(m2, 3, 3);

    return 0;
}

int all_tests() {
    _verify(position_01);
    _verify(dot_01);
    _verify(norma_01);
    _verify(trasp_01);
    _verify(prod_01);
    _verify(sum_01);
    _verify(eye_01);
    _verify(inv_01);
    _verify(test_Doubler_1);
    _verify(test_Eccanom_1);
    _verify(test_Eccanom_2);
    _verify(test_EqnEquinox_1);
    _verify(test_fracc1);
    _verify(test_fracc2);
    _verify(test_Gast_1);
    _verify(test_Gmst_1);
    _verify(test_Gmst_2);
    _verify(test_Legendre_1);
    _verify(test_Rx1);
    _verify(test_Ry1);
    _verify(test_Rz1);
    _verify(test_Timediff1);
    _verify(test_unit1);
    _verify(test_unit2);
    _verify(test_Cheb3D_1);


    return 0;
}

/*


int main() {
    int result = all_tests();

    double *v;

    if (result == 0)
        printf("PASSED\n");

    printf("Tests run: %d\n", tests_run);

    return result != 0;
}

*/

