#include <assert.h>
#include "Array.h"
#include <float.h>
#include <stdio.h>
#include "gast.h"
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


int test_Gast_1() {

    double resultado = gast(4.974611635416653e+04);
    printf("resultado: %f\n", resultado);

    _assert(esIgual(resultado, 2.96320762344617));

    return 0;


}



int all_tests() {


    _verify(test_Gast_1);
    


    return 0;

}


int main() {

    int result = all_tests();

    if (result == 0)
        printf("PASSED\n");

    printf("Tests run: %d\n", tests_run);

    return result != 0;


}
