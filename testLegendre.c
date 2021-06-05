#include <assert.h>
#include "Array.h"
#include <float.h>
#include <stdio.h>
#include "Legendre.h"
#include <math.h>


#define FAIL() printf("\nfailure in %s() line %d\n", __func__, __LINE__)
#define _assert(test) do { if (!(test)) { FAIL(); return 1; } } while(0)
#define _verify(test) do { int r=test(); tests_run++; if(r) return r; } while(0)

int tests_run = 0;


int esIgual(double c, double b) {

    printf("c: %f\n", c);
    printf("b: %f\n", b);

    if (c == b) {
        return 0;
    }
    return 1;
}


int test_Legendre_1() {

    double** pnm_real = array(2, 3);
    double ** dpnm_real = array(2, 3);



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


    _assert(compare(pnm, 2, 3, pnm_real,2,3));
     _assert(compare(dpnm, 2, 3, dpnm_real,2,3));


    return 0;


}

int test_Legendre_2() {


    


    return 0;


}


int all_tests() {


    _verify(test_Legendre_1);
    _verify(test_Legendre_2);


    return 0;

}


int main() {

    int result = all_tests();

    if (result == 0)
        printf("PASSED\n");

    printf("Tests run: %d\n", tests_run);

    return result != 0;


}
