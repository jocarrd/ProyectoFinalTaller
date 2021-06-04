#include <assert.h>
#include "Array.h"
#include <float.h>
#include <stdio.h>
#include "unit.h"
#include <math.h>


#define FAIL() printf("\nfailure in %s() line %d\n", __func__, __LINE__)
#define _assert(test) do { if (!(test)) { FAIL(); return 1; } } while(0)
#define _verify(test) do { int r=test(); tests_run++; if(r) return r; } while(0)

int tests_run = 0;


int test_unit1() {

    double * ds = vector(3); 
    ds[0] = 1;
    ds[1] = 2;
    ds[2] = 3;
    

    double *f = unit(ds,3);

    double* resultado = vector(3);
    resultado[0] = 0.2672612419124244000;
    resultado[1] = 0.5345224838248487900;
    resultado[2] = 0.8017837257372731900;

    


    printVector(f, 3);
    
    _assert(compareV(f,3,resultado,3));


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




int all_tests() {


    _verify(test_unit1);
    _verify(test_unit2);
   
    return 0;

}






int main() {

    int result = all_tests();

    if (result == 0)
        printf("PASSED\n");

    printf("Tests run: %d\n", tests_run);

    return result != 0;


}
