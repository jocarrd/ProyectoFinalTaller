#include <assert.h>
#include "Array.h"
#include <float.h>
#include <stdio.h>
#include "doubler.h"
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


int test_Doubler_1() {

    //entrada

    double* los1 = vector(3);
    los1[0] = 1;
    los1[1] = 2;
    los1[2] = 3;
    double *los2= vector(3);
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
    double *rsite2 = vector(3);
    rsite2[0] = 1;
    rsite2[1] = 2;
    rsite2[2] = 3;
    double * rsite3= vector(3);
    rsite3[0] = 1;
    rsite3[1] = 2;
    rsite3[2] = 3;




    //salida
   
    double* r2 = vector(3);
    double* r3 = vector(3);      
    double* f1 = vector(1); 
    double* f2= vector(1);     
    double* q1 = vector(1);     
    double* magr1= vector(1);     
    double* magr2= vector(1);      
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



int all_tests() {


    _verify(test_Doubler_1);



    return 0;

}


int main() {

    int result = all_tests();

    if (result == 0)
        printf("PASSED\n");

    printf("Tests run: %d\n", tests_run);

    return result != 0;


}
