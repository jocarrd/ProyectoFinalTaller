#include <assert.h>
#include "Array.h"
#include <float.h>
#include <stdio.h>
#include "R_x.h"
#include <math.h>


#define FAIL() printf("\nfailure in %s() line %d\n", __func__, __LINE__)
#define _assert(test) do { if (!(test)) { FAIL(); return 1; } } while(0)
#define _verify(test) do { int r=test(); tests_run++; if(r) return r; } while(0)

int tests_run = 0;


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

    _assert(compare(comprobar,3, 3, resultado, 3,3));


    return 0;


}


int all_tests() {


    _verify(test_Rx1);
    

    return 0;

}






int main() {

    int result = all_tests();

    if (result == 0)
        printf("PASSED\n");

    printf("Tests run: %d\n", tests_run);

    return result != 0;


}
