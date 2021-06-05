#include <assert.h>
#include "Array.h"
#include <float.h>
#include <stdio.h>
#include "Cheb3D.h"
#include <math.h>


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



int all_tests() {


    _verify(test_Cheb3D_1);



    return 0;

}


int main() {

    int result = all_tests();

    if (result == 0)
        printf("PASSED\n");

    printf("Tests run: %d\n", tests_run);

    return result != 0;


}
