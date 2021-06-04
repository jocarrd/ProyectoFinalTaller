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

#define FAIL() printf("\nfailure in %s() line %d\n", __func__, __LINE__)
#define _assert(test) do { if (!(test)) { FAIL(); return 1; } } while(0)
#define _verify(test) do { int r=test(); tests_run++; if(r) return r; } while(0)


int tests_run = 0;

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

    return 0;
}



int main() {
    int result = all_tests();

    double *v;

    if (result == 0)
        printf("PASSED\n");

    printf("Tests run: %d\n", tests_run);

    return result != 0;
}



